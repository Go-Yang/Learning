import json
import matplotlib.pyplot as plt
import numpy as np
import tkinter as tk
from tkinter.scrolledtext import ScrolledText
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk

# 创建随机数据的函数
def generate_random_data():
    return np.random.random((20, 20))

# 按键事件处理函数
def on_key(event):
    print(f'Key pressed: {event.key}')
    if event.key == 'q':
        root.quit()  # 按 'q' 键关闭图形窗口
    elif event.key == 'a':
        # 更新数据
        new_data1 = generate_random_data()
        new_data2 = [4, 5, 6]  # 可以更新折线图的数据源，这里保持不变
        # 更新灰度图
        im.set_data(new_data1)
        # 更新折线图
        line.set_ydata(new_data2)
        # 重新绘制图形
        canvas.draw_idle()
    elif event.key == 'd':
        # 更新数据
        new_data1 = generate_random_data()
        new_data2 = [6, 5, 4]  # 可以更新折线图的数据源，这里保持不变
        # 更新灰度图
        im.set_data(new_data1)
        # 更新折线图
        line.set_ydata(new_data2)
        # 重新绘制图形
        canvas.draw_idle()

# 关闭窗口的函数
def close_window():
    root.quit()
    root.destroy()

# 创建主窗口
root = tk.Tk()
root.title("Matplotlib Viewer")

# 设置窗口关闭协议
root.protocol("WM_DELETE_WINDOW", close_window)



# 创建图形和轴
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# 初始随机数据
data1 = generate_random_data()
data2 = generate_random_data()

# 绘制折线图
line, = axs[0].plot([1, 2, 3], [4, 5, 6])  # 注意这里的逗号，line 是 Line2D 对象
axs[0].set_title('Plot 1')

# 绘制灰度图
im = axs[1].imshow(data1, cmap='gray')
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

# 创建日志窗口
def open_log_window():
    log_window = tk.Toplevel(root)
    log_window.title("Log Viewer")
    
    # 创建一个文本窗口用于显示日志
    text_box = ScrolledText(log_window, height=20)
    text_box.pack(side=tk.TOP, fill=tk.BOTH, expand=True)
    
    # 模拟日志内容
    log_content = """
    This is a sample log file.
    Each new line represents a new log entry.
    Key events:
    - Press 'a' to update td
    ddhe data with new random values.
    - Press 'd' to update the data with another set of random values.
    - Press 'q' to close the window.
    """
    
    # 在文本窗口中显示日志内容
    text_box.insert(tk.END, log_content)

# 创建一个按钮来打开日志窗口
btn_open_log = tk.Button(root, text="Open Log Window", command=open_log_window)
btn_open_log.pack(side=tk.BOTTOM, fill=tk.X)

# 运行 Tkinter 主循环
root.mainloop()
