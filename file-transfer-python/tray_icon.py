import os
import sys
import threading
import webbrowser
import pystray
from PIL import Image, ImageDraw
import time

class TrayIcon:
    def __init__(self, app, port=5000):
        self.app = app
        self.port = port
        self.icon = None
        self.running = False

    def create_image(self):
        """创建托盘图标"""
        # 创建一个简单的图像
        image = Image.new('RGB', (64, 64), color=(1, 86, 155))
        dc = ImageDraw.Draw(image)

        # 绘制一个简单的文件传输图标
        dc.rectangle([16, 20, 48, 44], fill=(245, 128, 37))
        dc.polygon([(32, 10), (22, 20), (42, 20)], fill=(245, 128, 37))

        # 添加箭头表示传输
        dc.line([(20, 32), (30, 32), (30, 28), (36, 32), (30, 36), (30, 32)], 
                fill=(255, 255, 255), width=2)

        return image

    def setup_menu(self):
        """设置托盘菜单"""
        return (
            pystray.MenuItem("打开文件传输系统", self.open_browser),
            pystray.MenuItem("本地地址", self.copy_local_address),
            pystray.MenuItem("局域网地址", self.copy_network_address),
            pystray.Menu.SEPARATOR,
            pystray.MenuItem("退出", self.quit_app)
        )

    def open_browser(self, icon, item):
        """打开浏览器"""
        webbrowser.open(f'http://127.0.0.1:{self.port}')

    def copy_local_address(self, icon, item):
        """复制本地地址到剪贴板"""
        address = f'http://127.0.0.1:{self.port}'
        self.to_clipboard(address)
        self.show_notification("已复制本地地址", address)

    def copy_network_address(self, icon, item):
        """复制局域网地址到剪贴板"""
        import socket
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.connect(("8.8.8.8", 80))
            ip = s.getsockname()[0]
            s.close()
            address = f'http://{ip}:{self.port}'
            self.to_clipboard(address)
            self.show_notification("已复制局域网地址", address)
        except:
            self.show_notification("获取网络地址失败", "无法获取本机IP地址")

    def to_clipboard(self, text):
        """将文本复制到剪贴板"""
        if sys.platform == 'win32':
            import win32clipboard
            win32clipboard.OpenClipboard()
            win32clipboard.EmptyClipboard()
            win32clipboard.SetClipboardText(text)
            win32clipboard.CloseClipboard()
        elif sys.platform == 'darwin':
            import subprocess
            subprocess.run('pbcopy', universal_newlines=True, input=text)
        else:
            # Linux
            import subprocess
            try:
                subprocess.run(['xclip', '-selection', 'clipboard'], 
                              universal_newlines=True, input=text)
            except FileNotFoundError:
                # 如果没有xclip，尝试xsel
                subprocess.run(['xsel', '-b', '-i'], 
                              universal_newlines=True, input=text)

    def show_notification(self, title, message):
        """显示通知"""
        if self.icon:
            self.icon.notify(message, title)

    def quit_app(self, icon, item):
        """退出应用"""
        self.running = False
        self.icon.stop()
        os._exit(0)

    def start(self):
        """启动托盘图标"""
        self.running = True

        # 创建图标
        self.icon = pystray.Icon(
            "file_transfer",
            icon=self.create_image(),
            title="文件互传系统",
            menu=self.setup_menu()
        )

        # 在单独的线程中运行托盘
        threading.Thread(target=self.icon.run, daemon=True).start()

        # 等待图标初始化
        time.sleep(0.5)

        # 显示启动通知
        self.show_notification("文件互传系统已启动", f"端口: {self.port}")
