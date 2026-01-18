// DOM元素
const fileInput = document.getElementById('file-input');
const uploadButton = document.getElementById('upload-button');
const dropZone = document.getElementById('drop-zone');
const progressContainer = document.getElementById('progress-container');
const progressFill = document.getElementById('progress-fill');
const progressText = document.getElementById('progress-text');
const filesList = document.getElementById('files-list');
const searchInput = document.getElementById('search-input');
const refreshBtn = document.getElementById('refresh-btn');
const notification = document.getElementById('notification');
const notificationMessage = document.getElementById('notification-message');
const notificationClose = document.getElementById('notification-close');
const statusIndicator = document.getElementById('status-indicator');
const statusText = document.getElementById('status-text');

// 初始化
document.addEventListener('DOMContentLoaded', () => {
    loadFiles();
    setupEventListeners();
});

// 设置事件监听器
function setupEventListeners() {
    // 上传按钮点击事件
    uploadButton.addEventListener('click', () => {
        fileInput.click();
    });

    // 文件选择事件
    fileInput.addEventListener('change', (e) => {
        if (e.target.files.length > 0) {
            uploadFiles(e.target.files);
        }
    });

    // 拖放事件
    dropZone.addEventListener('dragover', (e) => {
        e.preventDefault();
        dropZone.classList.add('dragover');
    });

    dropZone.addEventListener('dragleave', () => {
        dropZone.classList.remove('dragover');
    });

    dropZone.addEventListener('drop', (e) => {
        e.preventDefault();
        dropZone.classList.remove('dragover');

        if (e.dataTransfer.files.length > 0) {
            uploadFiles(e.dataTransfer.files);
        }
    });

    // 搜索输入事件
    searchInput.addEventListener('input', () => {
        filterFiles(searchInput.value);
    });

    // 刷新按钮点击事件
    refreshBtn.addEventListener('click', loadFiles);

    // 通知关闭按钮点击事件
    notificationClose.addEventListener('click', hideNotification);
}

// 上传文件
async function uploadFiles(files) {
    if (files.length === 0) return;

    showProgress();

    for (const file of files) {
        await uploadSingleFile(file);
    }

    hideProgress();
    loadFiles();
}

// 上传单个文件
function uploadSingleFile(file) {
    return new Promise((resolve, reject) => {
        // 检查文件大小是否超过1GB
        const maxSize = 1024 * 1024 * 1024; // 1GB
        if (file.size > maxSize) {
            showNotification(`文件 "${file.name}" 大小超过1GB限制`, 'error');
            reject(new Error('文件大小超过限制'));
            return;
        }

        const formData = new FormData();
        formData.append('file', file);

        const xhr = new XMLHttpRequest();

        // 上传进度
        xhr.upload.addEventListener('progress', (e) => {
            if (e.lengthComputable) {
                const percentComplete = Math.round((e.loaded / e.total) * 100);
                updateProgress(percentComplete);
            }
        });

        // 上传完成
        xhr.addEventListener('load', () => {
            if (xhr.status >= 200 && xhr.status < 300) {
                const response = JSON.parse(xhr.responseText);
                showNotification(`文件 "${response.filename}" 上传成功！`, 'success');
                resolve();
            } else {
                const response = JSON.parse(xhr.responseText);
                showNotification(`文件上传失败: ${response.error}`, 'error');
                reject(new Error(response.error));
            }
        });

        // 上传错误
        xhr.addEventListener('error', () => {
            showNotification('文件上传过程中发生错误', 'error');
            reject(new Error('上传错误'));
        });

        xhr.open('POST', '/upload');
        xhr.send(formData);
    });
}

// 加载文件列表
async function loadFiles() {
    try {
        const response = await fetch('/files');
        const files = await response.json();
        renderFilesList(files);
    } catch (error) {
        showNotification('无法加载文件列表', 'error');
        console.error('加载文件列表失败:', error);
    }
}

// 渲染文件列表
function renderFilesList(files) {
    if (files.length === 0) {
        filesList.innerHTML = `
            <div class="empty-state">
                <i class="fas fa-folder-open"></i>
                <p>暂无文件</p>
            </div>
        `;
        return;
    }

    filesList.innerHTML = files.map(file => {
        const fileIcon = getFileIcon(file.name);
        const formattedSize = formatFileSize(file.size);
        const formattedDate = formatDate(file.mtime);

        return `
            <div class="file-item" data-filename="${file.name.toLowerCase()}">
                <div class="file-name">
                    <i class="${fileIcon} file-icon"></i>
                    <span>${file.name}</span>
                </div>
                <span>${formattedSize}</span>
                <span>${formattedDate}</span>
                <div class="file-actions">
                    <button class="btn-action" onclick="downloadFile('${encodeURIComponent(file.name)}')" title="下载">
                        <i class="fas fa-download"></i>
                    </button>
                    <button class="btn-action btn-delete" onclick="deleteFile('${encodeURIComponent(file.name)}')" title="删除">
                        <i class="fas fa-trash"></i>
                    </button>
                </div>
            </div>
        `;
    }).join('');
}

// 获取文件图标
function getFileIcon(filename) {
    const extension = filename.split('.').pop().toLowerCase();

    const iconMap = {
        // 文档
        pdf: 'fas fa-file-pdf',
        doc: 'fas fa-file-word',
        docx: 'fas fa-file-word',
        xls: 'fas fa-file-excel',
        xlsx: 'fas fa-file-excel',
        ppt: 'fas fa-file-powerpoint',
        pptx: 'fas fa-file-powerpoint',
        txt: 'fas fa-file-alt',
        // 图片
        jpg: 'fas fa-file-image',
        jpeg: 'fas fa-file-image',
        png: 'fas fa-file-image',
        gif: 'fas fa-file-image',
        svg: 'fas fa-file-image',
        // 音频
        mp3: 'fas fa-file-audio',
        wav: 'fas fa-file-audio',
        // 视频
        mp4: 'fas fa-file-video',
        avi: 'fas fa-file-video',
        mov: 'fas fa-file-video',
        // 代码
        js: 'fas fa-file-code',
        html: 'fas fa-file-code',
        css: 'fas fa-file-code',
        cpp: 'fas fa-file-code',
        py: 'fas fa-file-code',
        // 压缩文件
        zip: 'fas fa-file-archive',
        rar: 'fas fa-file-archive',
        '7z': 'fas fa-file-archive',
        // 默认
        default: 'fas fa-file'
    };

    return iconMap[extension] || iconMap.default;
}

// 格式化文件大小
function formatFileSize(bytes) {
    if (bytes === 0) return '0 Bytes';

    const k = 1024;
    const sizes = ['Bytes', 'KB', 'MB', 'GB'];
    const i = Math.floor(Math.log(bytes) / Math.log(k));

    return parseFloat((bytes / Math.pow(k, i)).toFixed(2)) + ' ' + sizes[i];
}

// 格式化日期
function formatDate(timestamp) {
    const date = new Date(timestamp * 1000);
    return date.toLocaleDateString() + ' ' + date.toLocaleTimeString();
}

// 过滤文件
function filterFiles(searchTerm) {
    const fileItems = document.querySelectorAll('.file-item');

    fileItems.forEach(item => {
        const filename = item.getAttribute('data-filename');
        if (filename.includes(searchTerm.toLowerCase())) {
            item.style.display = '';
        } else {
            item.style.display = 'none';
        }
    });
}

// 下载文件
function downloadFile(filename) {
    window.location.href = `/download/${filename}`;
}

// 删除文件
async function deleteFile(filename) {
    if (!confirm('确定要删除这个文件吗？')) return;

    try {
        const response = await fetch(`/delete/${filename}`, {
            method: 'DELETE'
        });

        if (response.ok) {
            showNotification('文件删除成功', 'success');
            loadFiles();
        } else {
            const result = await response.json();
            showNotification('文件删除失败: ' + result.error, 'error');
        }
    } catch (error) {
        showNotification('文件删除过程中发生错误', 'error');
        console.error('删除文件失败:', error);
    }
}

// 显示上传进度
function showProgress() {
    progressContainer.style.display = 'block';
    updateProgress(0);
}

// 隐藏上传进度
function hideProgress() {
    setTimeout(() => {
        progressContainer.style.display = 'none';
    }, 500);
}

// 更新进度条
function updateProgress(percent) {
    progressFill.style.width = `${percent}%`;
    progressText.textContent = `${percent}%`;
}

// 显示通知
function showNotification(message, type = 'info') {
    notificationMessage.textContent = message;

    // 根据类型设置不同的样式
    notification.classList.remove('success', 'error', 'warning');
    if (type !== 'info') {
        notification.classList.add(type);
    }

    notification.classList.add('show');

    // 5秒后自动隐藏
    setTimeout(hideNotification, 5000);
}

// 隐藏通知
function hideNotification() {
    notification.classList.remove('show');
}
