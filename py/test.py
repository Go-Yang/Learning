import tkinter as tk
from tkinter import *
from tkinter import filedialog
import cv2
import numpy as np
from PIL import Image, ImageTk


class DisplayImage:
    '''用于展示选择的图片'''
    def __init__(self, master):
        self.master = master
        master.title("GUI")
        self.image_frame = Frame(master, bd=0, height=200, width=800, bg='yellow', highlightthickness=2,
                                 highlightbackground='gray', highlightcolor='black')
        self.image_frame.pack()
        self.Text_label = Label(master, text='图像预览')
        self.Text_label.pack()
        self.Choose_image = Button(master, command=self.choose_pic, text="Choose image",
                                   width=17, default=ACTIVE, borderwidth=0)
        self.Choose_image.pack()
        self.Display_image = Button(master, command=self.display_image, text="Display image",
                                    width=17, default=ACTIVE, borderwidth=0)
        self.Display_image.pack()
        self.filenames = []
        self.pic_filelist = []
        self.imgt_list = []
        self.image_labellist = []

    def display_image(self, event=None):
        #在重新选择图片时清空原先列表
        self.pic_filelist.clear()
        self.imgt_list.clear()
        self.image_labellist.clear()

        #清空框架中的内容
        for widget in self.image_frame.winfo_children():
            widget.destroy()

        #布局所选图片
        for i in range(len(self.filenames)):
            self.pic_filelist.append(Image.open(self.filenames[i]).resize((200,200)))
            self.imgt_list.append(ImageTk.PhotoImage(image=self.pic_filelist[i]))
            self.image_labellist.append(Label(self.image_frame, highlightthickness=0, borderwidth=0))
            self.image_labellist[i].configure(image=self.imgt_list[i])
            self.image_labellist[i].pack(side=LEFT, expand=True)

    def choose_pic(self, event=None):
        self.filenames.clear()
        self.filenames += filedialog.askopenfilenames()

def main():
    window = tk.Tk()
    GUI = DisplayImage(window)
    window.title('投影亮度参数标定软件模块')
    window.geometry('1000x600')
    window.mainloop()

if __name__ == '__main__':
    main()
