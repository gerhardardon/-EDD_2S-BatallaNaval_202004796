
import sys
from tkinter import END

from listCarrito import listaCarrito
 
try:
    import tkinter as tk
except ImportError:
    import tkinter as tk

try:
    
    py3 = False
except ImportError:
    import tkinter.ttk as ttk
    py3 = True

mainUser=""
lstCarrito = listaCarrito()
total=0
cantTotal=""

def cleartotal():
    global total
    total=0

def quitarTotal():
    global total
    total-=1

def agregaraCarrito(x):
    global total
    total+=1
    newx = x.split(") ")
    print(newx[0],"-",newx[1])
    lstCarrito.agregar(newx[0],newx[1])


def vp_start_guiStore(x):
    global mainUser
    mainUser=x
    '''Starting point when module is the main routine.'''
    global val, w, root
    root = tk.Tk()
    top = Toplevel1 (root)
    root.mainloop()


w = None
def create_Toplevel1(rt, *args, **kwargs):
    '''Starting point when module is imported by another module.
       Correct form of call: 'create_Toplevel1(root, *args, **kwargs)' .'''
    global w, w_win, root
    #rt = root
    root = rt
    w = tk.Toplevel (root)
    top = Toplevel1 (w)
    return (w, top)

def destroy_Toplevel1():
    global w
    w.destroy()
    w = None

class Toplevel1:
    def __init__(self, top=None):
        
        '''This class configures and populates the toplevel window.
           top is the toplevel containing window.'''
        _bgcolor = '#d9d9d9'  # X11 color: 'gray85'
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#d9d9d9' # X11 color: 'gray85'
        _ana1color = '#d9d9d9' # X11 color: 'gray85'
        _ana2color = '#ececec' # Closest X11 color: 'gray92'

        top.geometry("600x450+312+116")
        top.minsize(120, 1)
        top.maxsize(1370, 749)
        top.resizable(1,  1)
        top.title("New Toplevel")
        top.configure(background="#ffffff")

        self.menubar = tk.Menu(top,font="TkMenuFont",bg=_bgcolor,fg=_fgcolor)
        top.configure(menu = self.menubar)

        self.Label1 = tk.Label(top)
        self.Label1.place(relx=0.333, rely=0.067, height=31, width=194)
        self.Label1.configure(background="#ffffff")
        self.Label1.configure(cursor="fleur")
        self.Label1.configure(disabledforeground="#a3a3a3")
        self.Label1.configure(font="-family {Segoe UI Black} -size 17 -weight bold")
        self.Label1.configure(foreground="#000000")
        self.Label1.configure(text='''TIENDA''')

        self.Listbox1 = tk.Listbox(top)
        self.Listbox1.place(relx=0.083, rely=0.244, relheight=0.538
                , relwidth=0.323)
        self.Listbox1.configure(background="white")
        self.Listbox1.configure(cursor="fleur")
        self.Listbox1.configure(disabledforeground="#a3a3a3")
        self.Listbox1.configure(font="TkFixedFont")
        self.Listbox1.configure(foreground="#000000")

        self.Listbox1_1 = tk.Listbox(top)
        indice=self.Listbox1_1.curselection()
        self.Listbox1_1.place(relx=0.583, rely=0.244, relheight=0.538
                , relwidth=0.323)
        self.Listbox1_1.configure(background="white")
        self.Listbox1_1.configure(disabledforeground="#a3a3a3")
        self.Listbox1_1.configure(font="TkFixedFont")
        self.Listbox1_1.configure(foreground="#000000")
        self.Listbox1_1.configure(highlightbackground="#d9d9d9")
        self.Listbox1_1.configure(highlightcolor="black")
        self.Listbox1_1.configure(selectbackground="blue")
        self.Listbox1_1.configure(selectforeground="white")

        self.Entry1 = tk.Entry(top)
        self.Entry1.place(relx=0.083, rely=0.822, height=20, relwidth=0.14)
        self.Entry1.configure(background="white")
        self.Entry1.configure(disabledforeground="#a3a3a3")
        self.Entry1.configure(font="TkFixedFont")
        self.Entry1.configure(foreground="#000000")
        self.Entry1.configure(insertbackground="black")

        self.Button1 = tk.Button(top)
        self.Button1.place(relx=0.25, rely=0.822, height=24, width=47)
        self.Button1.configure(activebackground="#ececec")
        self.Button1.configure(activeforeground="#000000")
        self.Button1.configure(background="#8080c0")
        self.Button1.configure(disabledforeground="#a3a3a3")
        self.Button1.configure(font="-family {Segoe UI} -size 15 -weight bold")
        self.Button1.configure(foreground="#ffffff")
        self.Button1.configure(highlightbackground="#d9d9d9")
        self.Button1.configure(highlightcolor="black")
        self.Button1.configure(pady="0")
        self.Button1.configure(relief="flat")
        self.Button1.configure(text='''Add''')
        self.Button1.configure(command=lambda: self.Listbox1_1.insert(END,self.Entry1.get()) or agregaraCarrito(self.Entry1.get()) or self.Label2_1.configure(text='''Total: '''+str(total)) or  self.Entry1.delete(0, tk.END))
        

        """self.Entry1_1 = tk.Entry(top)
        self.Entry1_1.place(relx=0.583, rely=0.822, height=20, relwidth=0.14)
        self.Entry1_1.configure(background="white")
        self.Entry1_1.configure(disabledforeground="#a3a3a3")
        self.Entry1_1.configure(font="TkFixedFont")
        self.Entry1_1.configure(foreground="#000000")
        self.Entry1_1.configure(highlightbackground="#d9d9d9")
        self.Entry1_1.configure(highlightcolor="black")
        self.Entry1_1.configure(insertbackground="black")
        self.Entry1_1.configure(selectbackground="blue")
        self.Entry1_1.configure(selectforeground="white")"""

        self.Button1_1 = tk.Button(top)
        self.Button1_1.place(relx=0.75, rely=0.822, height=24, width=47)
        self.Button1_1.configure(activebackground="#ececec")
        self.Button1_1.configure(activeforeground="#000000")
        self.Button1_1.configure(background="#e1031e")
        self.Button1_1.configure(disabledforeground="#a3a3a3")
        self.Button1_1.configure(font="-family {Segoe UI} -size 15 -weight bold")
        self.Button1_1.configure(foreground="#ffffff")
        self.Button1_1.configure(highlightbackground="#d9d9d9")
        self.Button1_1.configure(highlightcolor="black")
        self.Button1_1.configure(pady="0")
        self.Button1_1.configure(relief="flat")
        self.Button1_1.configure(text='''Del''')
        self.Button1_1.configure(command=lambda:self.Listbox1_1.delete(self.Listbox1_1.curselection()) or quitarTotal() or self.Label2_1.configure(text='''Total: '''+str(total))  )

        self.Label2 = tk.Label(top)
        self.Label2.place(relx=0.067, rely=0.2, height=21, width=74)
        self.Label2.configure(background="#ffffff")
        self.Label2.configure(disabledforeground="#a3a3a3")
        self.Label2.configure(font="-family {Segoe UI Black} -size 13 -weight bold")
        self.Label2.configure(foreground="#000000")
        self.Label2.configure(text='''Skins:''')

        self.Label2_1 = tk.Label(top)
        self.Label2_1.place(relx=0.583, rely=0.2, height=21, width=84)
        self.Label2_1.configure(activebackground="#f9f9f9")
        self.Label2_1.configure(activeforeground="black")
        self.Label2_1.configure(anchor='w')
        self.Label2_1.configure(background="#ffffff")
        self.Label2_1.configure(disabledforeground="#a3a3a3")
        self.Label2_1.configure(font="-family {Segoe UI Black} -size 13 -weight bold")
        self.Label2_1.configure(foreground="#8080c0")
        self.Label2_1.configure(highlightbackground="#d9d9d9")
        self.Label2_1.configure(highlightcolor="black")
        self.Label2_1.configure(text='''Total: ''')

        self.Label2_1_1 = tk.Label(top)
        self.Label2_1_1.place(relx=0.583, rely=0.156, height=21, width=94)
        self.Label2_1_1.configure(activebackground="#f9f9f9")
        self.Label2_1_1.configure(activeforeground="black")
        self.Label2_1_1.configure(anchor='w')
        self.Label2_1_1.configure(background="#ffffff")
        self.Label2_1_1.configure(disabledforeground="#a3a3a3")
        self.Label2_1_1.configure(font="-family {Segoe UI Black} -size 13 -weight bold")
        self.Label2_1_1.configure(foreground="#8080c0")
        self.Label2_1_1.configure(highlightbackground="#d9d9d9")
        self.Label2_1_1.configure(highlightcolor="black")
        self.Label2_1_1.configure(text='''Carrito:''')

        self.Button1_2 = tk.Button(top)
        self.Button1_2.place(relx=0.85, rely=0.889, height=24, width=67)
        self.Button1_2.configure(activebackground="#ececec")
        self.Button1_2.configure(activeforeground="#000000")
        self.Button1_2.configure(background="#8080c0")
        self.Button1_2.configure(disabledforeground="#a3a3a3")
        self.Button1_2.configure(font="-family {Segoe UI} -size 15 -weight bold")
        self.Button1_2.configure(foreground="#ffffff")
        self.Button1_2.configure(highlightbackground="#d9d9d9")
        self.Button1_2.configure(highlightcolor="black")
        self.Button1_2.configure(pady="0")
        self.Button1_2.configure(relief="flat")
        self.Button1_2.configure(text='''Buy''')
        self.Button1_2.configure(command=lambda: lstCarrito.crearHash())

        self.Button1_3 = tk.Button(top)
        self.Button1_3.place(relx=0.85, rely=0.822, height=24, width=67)
        self.Button1_3.configure(activebackground="#ececec")
        self.Button1_3.configure(activeforeground="#000000")
        self.Button1_3.configure(background="#8080c0")
        self.Button1_3.configure(disabledforeground="#a3a3a3")
        self.Button1_3.configure(font="-family {Segoe UI} -size 15 -weight bold")
        self.Button1_3.configure(foreground="#ffffff")
        self.Button1_3.configure(highlightbackground="#d9d9d9")
        self.Button1_3.configure(highlightcolor="black")
        self.Button1_3.configure(pady="0")
        self.Button1_3.configure(relief="flat")
        self.Button1_3.configure(text='''Cancel''')
        self.Button1_3.configure(command=lambda:self.Listbox1_1.delete(0,END) or lstCarrito.clear() or self.Label2_1.configure(text='''Total: ''') or cleartotal())


