from tkinter import *
import os


def karOpen():
    os.system('fileB.py')
    return
def setter():
    a = entr.get()
    return a

def hoja():
    a = entr.get()
    print(a)

root = Tk()
root.geometry("400x220")
root.minsize(400, 220)
root.maxsize(400, 220)
root.title("file A")


frame = Frame(root, borderwidth=5, bg="sky blue")
frame.pack(side=TOP)


label = Label(frame, text="Enter")
label.pack()
entr = Entry(frame)
entr.pack(pady=30)



b1 = Button(frame, fg="black", text="PRESS mEH", height=5, width=5, command=karOpen)
b1.pack(side=LEFT, padx=10, pady=20)



b2 = Button(frame, fg="black", text="PRESSSS", height=5, width=5, command=hoja)
b2.pack(side=LEFT, padx=10, pady=20)

root.mainloop()