const express = require('express');
const multer = require('multer');
const path = require('path');
const fs = require('fs');
const http = require('http');
const socketIo = require('socket.io');
const cors = require('cors');

const app = express();
const server = http.createServer(app);
const io = socketIo(server, {
  cors: {
    origin: "*",
    methods: ["GET", "POST"]
  }
});

// 设置文件上传目录
const UPLOAD_DIR = './uploads';
if (!fs.existsSync(UPLOAD_DIR)) {
  fs.mkdirSync(UPLOAD_DIR);
}

// 配置multer存储
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, UPLOAD_DIR);
  },
  filename: (req, file, cb) => {
    // 保留原始文件名
    cb(null, file.originalname);
  }
});

const upload = multer({ storage });

// 启用CORS
app.use(cors());
app.use(express.json());
app.use(express.static('public'));
app.use('/uploads', express.static(path.join(__dirname, 'uploads')));

// 主页路由
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// 获取文件列表
app.get('/files', (req, res) => {
  try {
    const files = fs.readdirSync(UPLOAD_DIR).map(filename => {
      const filePath = path.join(UPLOAD_DIR, filename);
      const stats = fs.statSync(filePath);
      return {
        name: filename,
        size: stats.size,
        uploadDate: stats.birthtime,
        downloadUrl: `/download/${encodeURIComponent(filename)}`
      };
    });
    res.json(files);
  } catch (err) {
    res.status(500).json({ error: '无法获取文件列表' });
  }
});

// 文件上传
app.post('/upload', upload.single('file'), (req, res) => {
  if (!req.file) {
    return res.status(400).json({ error: '没有上传文件' });
  }

  // 通知所有客户端有新文件上传
  io.emit('file-uploaded', {
    name: req.file.originalname,
    size: req.file.size,
    uploadDate: new Date()
  });

  res.json({ 
    message: '文件上传成功',
    file: req.file.originalname
  });
});

// 文件下载
app.get('/download/:filename', (req, res) => {
  const filename = req.params.filename;
  const filePath = path.join(UPLOAD_DIR, filename);

  if (!fs.existsSync(filePath)) {
    return res.status(404).json({ error: '文件不存在' });
  }

  res.download(filePath, filename, (err) => {
    if (err) {
      res.status(500).json({ error: '下载失败' });
    }
  });
});

// 文件删除
app.delete('/files/:filename', (req, res) => {
  const filename = req.params.filename;
  const filePath = path.join(UPLOAD_DIR, filename);

  if (!fs.existsSync(filePath)) {
    return res.status(404).json({ error: '文件不存在' });
  }

  fs.unlinkSync(filePath);

  // 通知所有客户端有文件被删除
  io.emit('file-deleted', { filename });

  res.json({ message: '文件删除成功' });
});

// Socket.IO 连接处理
io.on('connection', (socket) => {
  console.log('新客户端连接:', socket.id);

  socket.on('disconnect', () => {
    console.log('客户端断开连接:', socket.id);
  });
});

// 启动服务器
const PORT = process.env.PORT || 3000;
server.listen(PORT, () => {
  console.log(`文件传输服务器运行在 http://localhost:${PORT}`);
});
