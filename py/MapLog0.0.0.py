import matplotlib.pyplot as plt
import numpy as np

# 创建随机数据的函数
def generate_random_data():
    return np.random.random((1200, 1200))

# 初始随机数据
data1 = generate_random_data()
data2 = generate_random_data()

# 创建图形和轴
fig, axs = plt.subplots(1, 2, figsize=(10, 5))

# 绘制折线图
line, = axs[0].plot([1, 2, 3], [4, 5, 6])
axs[0].set_title('Plot 1')

# 绘制灰度图
im = axs[1].imshow(data1, cmap='gray')
axs[1].set_title('Gray Image')

# 添加颜色条
fig.colorbar(im, ax=axs[1])

# 按键事件处理函数
def on_key(event):
    print(f'Key pressed: {event.key}')
    if event.key == 'q':
        plt.close(event.canvas.figure)  # 按 'q' 键关闭图形窗口
    elif event.key == 'a':
        # 更新数据
        new_data1 = generate_random_data()
        new_data2 = [4, 5, 6]  # 可以更新折线图的数据源，这里保持不变
        # 更新灰度图
        im.set_data(new_data1)
        # 更新折线图
        line.set_ydata(new_data2)
        # 重新绘制图形
        fig.canvas.draw_idle()
    elif event.key == 'd':
        # 更新数据
        new_data1 = generate_random_data()
        new_data2 = [6, 5, 4]  # 可以更新折线图的数据源，这里保持不变
        # 更新灰度图
        im.set_data(new_data1)
        # 更新折线图
        line.set_ydata(new_data2)
        # 重新绘制图形
        fig.canvas.draw_idle()

# 连接按键事件到处理函数
fig.canvas.mpl_connect('key_press_event', on_key)

# 自动调整子图之间的间距
plt.tight_layout()

# 显示图形
plt.show()
