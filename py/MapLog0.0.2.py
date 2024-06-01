import os
import json
import numpy as np
import matplotlib.pyplot as plt
import tkinter as tk
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk

# 创建主窗口
root = tk.Tk()
root.title("Matplotlib Viewer")

# 当前显示的map文件夹索引
current_map_index = 0
map_folders = []

# 关闭窗口的函数
def close_window():
    root.quit()
    root.destroy()

# 读取slammap.bin文件
def read_slammap_bin(file_path):
    with open(file_path, 'rb') as f:
        data = np.fromfile(f, dtype=np.uint8).reshape(1200, 1200)
    return data

# 读取areainfos.json文件
def read_areainfos_json(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
    return data

# 更新绘图数据
def update_plot(map_folder):
    json_path = os.path.join(map_folder, "areainfos.json")
    bin_path = os.path.join(map_folder, "slammap.bin")

    if os.path.exists(json_path) and os.path.exists(bin_path):
        areainfos = read_areainfos_json(json_path)
        slammap = read_slammap_bin(bin_path)

        coordinates = areainfos.get('coordinates', [])

        if coordinates:
            x, y = zip(*coordinates)
            line.set_xdata(x)
            line.set_ydata(y)
        else:
            line.set_xdata([])
            line.set_ydata([])

        im.set_data(slammap)
        canvas.draw_idle()

# 按键事件处理函数
def on_key(event):
    global current_map_index
    if event.key == 'q':
        close_window()  # 按 'q' 键关闭图形窗口
    elif event.key == 'a':
        current_map_index = (current_map_index - 1) % len(map_folders)
        update_plot(map_folders[current_map_index])
    elif event.key == 'd':
        current_map_index = (current_map_index + 1) % len(map_folders)
        update_plot(map_folders[current_map_index])

# 打开文件夹并读取数据
def open_folder():
    global map_folders
    folder_path = filedialog.askdirectory()
    if folder_path:
        map_folders = [os.path.join(folder_path, d) for d in ["map1", "map2", "map3"]]
        update_plot(map_folders[current_map_index])

# 设置窗口关闭协议
root.protocol("WM_DELETE_WINDOW", close_window)

# 创建图形和轴
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# 绘制折线图
line, = axs[0].plot([], [])  # 空折线图
axs[0].set_title('Plot 1')

# 绘制灰度图
im = axs[1].imshow(np.zeros((1200, 1200)), cmap='gray')  # 空灰度图
axs[1].set_title('Gray Image')

# 嵌入 matplotlib 图形到 Tkinter Frame 中
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# 添加导航工具栏
toolbar = NavigationToolbar2Tk(canvas, root)
toolbar.update()
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# 自动调整子图之间的间距
plt.tight_layout()

# 连接按键事件到处理函数
canvas.mpl_connect('key_press_event', on_key)

# 创建一个按钮来打开文件夹并读取数据
btn_open_folder = tk.Button(root, text="Open Folder", command=open_folder)
btn_open_folder.pack(side=tk.BOTTOM, fill=tk.X)

# 运行 Tkinter 主循环
root.mainloop()
