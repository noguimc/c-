import os
import socket
import sys
import atexit
from flask import Flask, render_template, request, jsonify, send_file, redirect, url_for
from werkzeug.utils import secure_filename
import threading
import webbrowser
import time
from pathlib import Path
import argparse
import logging
from logging.handlers import RotatingFileHandler

# 导入托盘图标模块
try:
    from tray_icon import TrayIcon
    TRAY_AVAILABLE = True
except ImportError:
    TRAY_AVAILABLE = False
    print("警告: 无法导入托盘图标模块，请安装pystray和Pillow")

app = Flask(__name__)

# 配置日志记录
log_dir = 'logs'
if not os.path.exists(log_dir):
    os.makedirs(log_dir)

# 设置日志格式
log_format = '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
logging.basicConfig(
    level=logging.INFO,
    format=log_format,
    handlers=[
        RotatingFileHandler(os.path.join(log_dir, 'app.log'), maxBytes=10240000, backupCount=5),
        logging.StreamHandler(sys.stdout)
    ]
)

logger = logging.getLogger(__name__)

# 配置上传文件夹
UPLOAD_FOLDER = 'uploads'
if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.config['MAX_CONTENT_LENGTH'] = 1024 * 1024 * 1024  # 限制上传文件大小为1GB

# 全局变量，用于托盘图标
tray_icon = None

# 允许所有文件类型
def allowed_file(filename):
    return True  # 允许所有文件类型

def get_local_ip():
    """获取本机IP地址"""
    try:
        # 创建一个UDP套接字
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        # 连接到一个公共DNS服务器（不会实际发送数据）
        s.connect(("8.8.8.8", 80))
        ip = s.getsockname()[0]
        s.close()
        return ip
    except:
        return "127.0.0.1"

@app.route('/')
def index():
    """主页"""
    try:
        logger.info("访问主页")
        return render_template('index.html')
    except Exception as e:
        logger.error(f"访问主页时出错: {str(e)}")
        return render_template('error.html', error=str(e)), 500

@app.route('/files', methods=['GET'])
def list_files():
    """获取文件列表"""
    try:
        logger.info("获取文件列表")
        files = []
        for filename in os.listdir(app.config['UPLOAD_FOLDER']):
            file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
            if os.path.isfile(file_path):
                # 获取文件大小
                size = os.path.getsize(file_path)
                # 获取文件修改时间
                mtime = os.path.getmtime(file_path)
                files.append({
                    'name': filename,
                    'size': size,
                    'mtime': mtime,
                    'download_url': f'/download/{filename}'
                })
        logger.info(f"成功获取文件列表，共 {len(files)} 个文件")
        return jsonify(files)
    except Exception as e:
        logger.error(f"获取文件列表时出错: {str(e)}")
        return jsonify({'error': '获取文件列表失败'}), 500

@app.route('/upload', methods=['POST'])
def upload_file():
    """上传文件"""
    try:
        logger.info("开始上传文件")
        if 'file' not in request.files:
            logger.warning("上传请求中没有文件部分")
            return jsonify({'error': '没有文件部分'}), 400

        file = request.files['file']
        if file.filename == '':
            logger.warning("没有选择文件")
            return jsonify({'error': '没有选择文件'}), 400

        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            # 如果文件已存在，添加时间戳避免覆盖
            if os.path.exists(os.path.join(app.config['UPLOAD_FOLDER'], filename)):
                name, ext = os.path.splitext(filename)
                filename = f"{name}_{int(time.time())}{ext}"
                logger.info(f"文件已存在，重命名为: {filename}")

            file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
            file.save(file_path)
            file_size = os.path.getsize(file_path)
            logger.info(f"文件上传成功: {filename}, 大小: {file_size} 字节")
            return jsonify({'message': '文件上传成功', 'filename': filename})

        logger.warning(f"不允许的文件类型: {file.filename}")
        return jsonify({'error': '不允许的文件类型'}), 400
    except Exception as e:
        logger.error(f"上传文件时出错: {str(e)}")
        return jsonify({'error': f'上传失败: {str(e)}'}), 500

@app.route('/download/<filename>')
def download_file(filename):
    """下载文件"""
    try:
        logger.info(f"尝试下载文件: {filename}")
        file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        if os.path.exists(file_path):
            file_size = os.path.getsize(file_path)
            logger.info(f"开始下载文件: {filename}, 大小: {file_size} 字节")
            return send_file(file_path, as_attachment=True)
        logger.warning(f"请求下载的文件不存在: {filename}")
        return jsonify({'error': '文件不存在'}), 404
    except Exception as e:
        logger.error(f"下载文件时出错: {str(e)}")
        return jsonify({'error': f'下载失败: {str(e)}'}), 500

@app.route('/delete/<filename>', methods=['DELETE'])
def delete_file(filename):
    """删除文件"""
    try:
        logger.info(f"尝试删除文件: {filename}")
        file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
        if os.path.exists(file_path):
            os.remove(file_path)
            logger.info(f"文件删除成功: {filename}")
            return jsonify({'message': '文件删除成功'})
        logger.warning(f"请求删除的文件不存在: {filename}")
        return jsonify({'error': '文件不存在'}), 404
    except Exception as e:
        logger.error(f"删除文件时出错: {str(e)}")
        return jsonify({'error': f'删除失败: {str(e)}'}), 500

def open_browser():
    """延迟打开浏览器"""
    time.sleep(1.5)
    webbrowser.open('http://127.0.0.1:5000')

if __name__ == '__main__':
    # 设置命令行参数解析
    parser = argparse.ArgumentParser(description='文件互传系统')
    parser.add_argument('--port', '-p', type=int, default=5000, 
                        help='设置服务器端口号 (默认: 5000)')
    parser.add_argument('--no-browser', action='store_true',
                        help='启动时不自动打开浏览器')
    args = parser.parse_args()

    # 获取本机IP
    local_ip = get_local_ip()
    port = args.port

    print(f"文件传输服务器启动中...")
    print(f"本地访问地址: http://127.0.0.1:{port}")
    print(f"局域网访问地址: http://{local_ip}:{port}")
    print(f"文件大小限制: 1GB")

    # 在新线程中打开浏览器（除非指定了--no-browser参数）
    if not args.no_browser:
        threading.Thread(target=open_browser, daemon=True).start()

    # 启动Flask应用
    app.run(host='0.0.0.0', port=port, debug=False)
