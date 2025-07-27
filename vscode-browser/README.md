# VSCode Browser Extension

一个简单的VSCode插件，允许你在VSCode的侧边栏中打开浏览器。

## 功能

- 在VSCode侧边栏中集成网页浏览器
- 支持基本的浏览器操作（前进、后退、刷新）
- 支持URL导航
- 默认使用Google作为起始页面

## 使用方法

1. 安装插件后，在VSCode侧边栏中会出现一个浏览器图标
2. 点击图标打开浏览器视图
3. 在地址栏输入URL并按回车键或点击"Go"按钮进行导航
4. 使用工具栏按钮进行前进、后退和刷新操作

## 安装

1. 克隆此仓库
2. 进入项目目录
3. 运行 `npm install`
4. 按下 F5 在开发模式下运行插件
5. 或者使用 `vsce package` 打包插件后安装

## 开发

- `extension.js`: 插件主要代码
- `package.json`: 插件配置文件

## 注意事项

- 由于安全限制，某些网站可能无法在iframe中正常显示
- 需要VSCode 1.60.0或更高版本

## License

MIT
