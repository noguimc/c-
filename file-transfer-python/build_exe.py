import os
import sys
import subprocess
import shutil

def build_exe():
    """使用PyInstaller将Flask应用打包为exe"""
    print("开始打包文件互传程序为exe...")

    # 确保已安装所有依赖
    print("安装依赖...")
    subprocess.check_call([sys.executable, "-m", "pip", "install", "-r", "requirements.txt"])

    # 使用PyInstaller打包
    print("使用PyInstaller打包...")
    cmd = [
        "pyinstaller",
        "--name=文件互传系统",
        "--onefile",
        # 移除"--windowed"参数，这样打包后的exe可以显示命令行窗口
        "--add-data=templates;templates",
        "--add-data=static;static",
        "--icon=NONE",  # 如果有图标文件，可以替换为图标路径
        "app.py"
    ]

    subprocess.check_call(cmd)

    # 创建dist目录，如果不存在
    if not os.path.exists("dist"):
        os.makedirs("dist")

    # 复制uploads目录到dist目录
    uploads_dir = os.path.join("dist", "uploads")
    if not os.path.exists(uploads_dir):
        os.makedirs(uploads_dir)

    print("打包完成！")
    print(f"可执行文件位于: {os.path.abspath('dist/文件互传系统.exe')}")
    print("注意：首次运行时，会在exe所在目录创建uploads文件夹用于存储上传的文件。")
    print("文件大小限制：1GB")

if __name__ == "__main__":
    build_exe()
