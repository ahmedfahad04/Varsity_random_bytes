from tkinter import *

root=Tk()

def killme():
    root.quit()
    root.destroy()
    
LB=Text(root, width=16, height=5, font=("Algerian",15))
LB.grid(row=0, column=0, sticky=W+N+S)
yscrollbar=Scrollbar(root, orient=VERTICAL, command=LB.yview)
yscrollbar.grid(row=0, column=1, sticky=N+S+E+W)
LB["yscrollcommand"]=yscrollbar.set
LB.update()
h=int(round(LB.winfo_height()/LB["height"])), int(round(LB.winfo_width()/LB["width"]))

def resize(event):
   
    pixelX=root.winfo_width()-yscrollbar.winfo_width()
    pixelY=root.winfo_height()
    LB["width"]=int(round(pixelX/h[1])) 
    LB["height"]=int(round(pixelY/h[0]))
root.bind("<Configure>", resize)

root.mainloop()