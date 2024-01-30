from tkinter import *
import fileA

root = Tk()
root.geometry("400x220")
root.minsize(400, 220)
root.maxsize(400, 220)
root.title("file B")


print("file B me ghus jatau")

a = fileA.setter()
print(a)


frame = Frame(root, borderwidth=5)
frame.pack(side=TOP)

b1 = Button(frame, fg="black", text="PRESS mEH", height=20, width=20)
b1.pack(side=LEFT, padx=10, pady=20)




root.mainloop()

