from doctest import master
import tkinter as tk

img=""
def cambiarImg():
    global img
    img = tk.PhotoImage(file="tablero.png")
    label2 = tk.Label(image=img).place(x=50, y=100, height=380, width=380)


def openTablero():
    window = tk.Tk()
    window = tk.Toplevel(master)
    frame = tk.Frame(master=window, width=1000, height=600)
    frame.configure(background="#ffffff")
    frame.pack()

    label1 = tk.Label(bg="blue")
    label1.place(x=570, y=100, height=380, width=380)


    boton1 = tk.Button()
    boton1.place(x=300,y=500, height=64, width=107)
    boton1.configure(activebackground="#ececec")
    boton1.configure(activeforeground="#000000")
    boton1.configure(background="#80ff80")
    boton1.configure(disabledforeground="#a3a3a3")
    boton1.configure(font="-family {Segoe UI} -size 17 -weight bold")
    boton1.configure(foreground="#ffffff")
    boton1.configure(highlightbackground="#d9d9d9")
    boton1.configure(highlightcolor="black")
    boton1.configure(pady="0")
    boton1.configure(relief="flat")
    boton1.configure(text='''Atacar''')
    boton1.configure(command= lambda: cambiarImg())

    boton2 = tk.Button()
    boton2.place(x=675,y=500, height=64, width=137)
    boton2.configure(activebackground="#ececec")
    boton2.configure(activeforeground="#000000")
    boton2.configure(background="#ff8080")
    boton2.configure(disabledforeground="#a3a3a3")
    boton2.configure(font="-family {Segoe UI} -size 17 -weight bold")
    boton2.configure(foreground="#ffffff")
    boton2.configure(highlightbackground="#d9d9d9")
    boton2.configure(highlightcolor="black")
    boton2.configure(pady="0")
    boton2.configure(relief="flat")
    boton2.configure(text='''Abandonar''')

    boton3 = tk.Button()
    boton3.place(x=850,y=500, height=64, width=107)
    boton3.configure(activebackground="#ececec")
    boton3.configure(activeforeground="#000000")
    boton3.configure(background="#8080ff")
    boton3.configure(disabledforeground="#a3a3a3")
    boton3.configure(font="-family {Segoe UI} -size 17 -weight bold")
    boton3.configure(foreground="#ffffff")
    boton3.configure(highlightbackground="#d9d9d9")
    boton3.configure(highlightcolor="black")
    boton3.configure(pady="0")
    boton3.configure(relief="flat")
    boton3.configure(text='''Regresar''')

    entry1 = tk.Entry()
    entry1.place(x=200,y=510, height=20, relwidth=0.086)
    entry1.configure(background="white")
    entry1.configure(disabledforeground="#a3a3a3")
    entry1.configure(font="TkFixedFont")
    entry1.configure(foreground="#000000")
    entry1.configure(insertbackground="black")

    entry2 = tk.Entry()
    entry2.place(x=200,y=540, height=20, relwidth=0.086)
    entry2.configure(background="white")
    entry2.configure(disabledforeground="#a3a3a3")
    entry2.configure(font="TkFixedFont")
    entry2.configure(foreground="#000000")
    entry2.configure(insertbackground="black")

    window.mainloop()       
