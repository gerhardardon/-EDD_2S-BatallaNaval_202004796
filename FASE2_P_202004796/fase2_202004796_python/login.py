#! /usr/bin/env python#  -*- coding: utf-8 -*-## GUI module generated by PAGE version 6.2#  in conjunction with Tcl version 8.6#    Sep 22, 2022 04:17:34 PM CST  platform: Windows NTimport sys
try:
    import tkinter as tk
except ImportError:
    import tkinter as tk

from cliente import*
from users import vp_start_gui2

def ingresar(x,x2):
    if req_login(x,x2)==200:
        vp_start_gui2(x)
    

def vp_start_gui():
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

        top.geometry("571x274+365+140")
        top.minsize(300, 1)
        top.maxsize(1370, 749)
        top.resizable(1,  1)
        top.title("New Toplevel")
        top.configure(background="#ffffff")

        self.Label1 = tk.Label(top)
        self.Label1.place(relx=0.28, rely=0.033, height=31, width=242)
        self.Label1.configure(background="#ffffff")
        self.Label1.configure(disabledforeground="#a3a3a3")
        self.Label1.configure(font="-family {Rockwell Condensed} -size 24 -weight bold")
        self.Label1.configure(foreground="#8cc6ff")
        self.Label1.configure(text='''BATALLA NAVAL''')

        self.menubar = tk.Menu(top,font="TkMenuFont",bg=_bgcolor,fg=_fgcolor)
        top.configure(menu = self.menubar)

        self.Label1_1 = tk.Label(top)
        self.Label1_1.place(relx=0.1, rely=0.250, height=31, width=99)
        self.Label1_1.configure(activebackground="#f9f9f9")
        self.Label1_1.configure(activeforeground="#000080")
        self.Label1_1.configure(background="#ffffff")
        self.Label1_1.configure(disabledforeground="#a3a3a3")
        self.Label1_1.configure(font="-family {Rockwell Condensed} -size 24")
        self.Label1_1.configure(foreground="#8cc6ff")
        self.Label1_1.configure(highlightbackground="#d9d9d9")
        self.Label1_1.configure(highlightcolor="black")
        self.Label1_1.configure(text='''User:''')

        self.Label1_1_1 = tk.Label(top)
        self.Label1_1_1.place(relx=0.068, rely=0.370, height=31, width=99)
        self.Label1_1_1.configure(activebackground="#f9f9f9")
        self.Label1_1_1.configure(activeforeground="#000080")
        self.Label1_1_1.configure(background="#ffffff")
        self.Label1_1_1.configure(disabledforeground="#a3a3a3")
        self.Label1_1_1.configure(font="-family {Rockwell Condensed} -size 24")
        self.Label1_1_1.configure(foreground="#8cc6ff")
        self.Label1_1_1.configure(highlightbackground="#d9d9d9")
        self.Label1_1_1.configure(highlightcolor="black")
        self.Label1_1_1.configure(text='''Password:''')

        self.Label2 = tk.Label(top)
        self.Label2.place(relx=0.068, rely=0.490, height=31, width=99)
        self.Label2.configure(activebackground="#f9f9f9")
        self.Label2.configure(activeforeground="#000080")
        self.Label2.configure(background="#ffffff")
        self.Label2.configure(disabledforeground="#a3a3a3")
        self.Label2.configure(font="-family {Rockwell Condensed} -size 24")
        self.Label2.configure(foreground="#8cc6ff")
        self.Label2.configure(highlightbackground="#d9d9d9")
        self.Label2.configure(highlightcolor="black")
        self.Label2.configure(text='''Age:''')

        self.Label3 = tk.Label(top)
        self.Label3.place(relx=0.068, rely=0.610, height=31, width=99)
        self.Label3.configure(activebackground="#f9f9f9")
        self.Label3.configure(activeforeground="#000080")
        self.Label3.configure(background="#ffffff")
        self.Label3.configure(disabledforeground="#a3a3a3")
        self.Label3.configure(font="-family {Rockwell Condensed} -size 24")
        self.Label3.configure(foreground="#8cc6ff")
        self.Label3.configure(highlightbackground="#d9d9d9")
        self.Label3.configure(highlightcolor="black")
        self.Label3.configure(text='''Id:''')

        self.Entry1 = tk.Entry(top)
        self.Entry1.place(relx=0.294, rely=0.250, height=30, relwidth=0.252)
        self.Entry1.configure(background="#eaeaea")
        self.Entry1.configure(borderwidth="0")
        self.Entry1.configure(cursor="fleur")
        self.Entry1.configure(disabledforeground="#a3a3a3")
        self.Entry1.configure(font="TkFixedFont")
        self.Entry1.configure(foreground="#000000")
        self.Entry1.configure(insertbackground="black")
  
        self.Entry1_1 = tk.Entry(top)
        self.Entry1_1.place(relx=0.294, rely=0.370, height=30, relwidth=0.252)
        self.Entry1_1.configure(background="#eaeaea")
        self.Entry1_1.configure(borderwidth="0")
        self.Entry1_1.configure(disabledforeground="#a3a3a3")
        self.Entry1_1.configure(font="TkFixedFont")
        self.Entry1_1.configure(foreground="#000000")
        self.Entry1_1.configure(highlightbackground="#d9d9d9")
        self.Entry1_1.configure(highlightcolor="black")
        self.Entry1_1.configure(insertbackground="black")
        self.Entry1_1.configure(selectbackground="blue")
        self.Entry1_1.configure(selectforeground="white")

        self.Entry2 = tk.Entry(top)
        self.Entry2.place(relx=0.294, rely=0.490, height=30, relwidth=0.252)
        self.Entry2.configure(background="#eaeaea")
        self.Entry2.configure(borderwidth="0")
        self.Entry2.configure(cursor="fleur")
        self.Entry2.configure(disabledforeground="#a3a3a3")
        self.Entry2.configure(font="TkFixedFont")
        self.Entry2.configure(foreground="#000000")
        self.Entry2.configure(insertbackground="black")

        self.Entry3 = tk.Entry(top)
        self.Entry3.place(relx=0.294, rely=0.610, height=30, relwidth=0.252)
        self.Entry3.configure(background="#eaeaea")
        self.Entry3.configure(borderwidth="0")
        self.Entry3.configure(cursor="fleur")
        self.Entry3.configure(disabledforeground="#a3a3a3")
        self.Entry3.configure(font="TkFixedFont")
        self.Entry3.configure(foreground="#000000")
        self.Entry3.configure(insertbackground="black")

        self.Button2 = tk.Button(top)
        self.Button2.place(relx=0.753, rely=0.500, height=44, width=77)
        self.Button2.configure(activebackground="#ececec")
        self.Button2.configure(activeforeground="#000040")
        self.Button2.configure(background="#ff80ff")
        self.Button2.configure(disabledforeground="#a3a3a3")
        self.Button2.configure(font="-family {Rockwell Condensed} -size 19")
        self.Button2.configure(foreground="#ffffff")
        self.Button2.configure(highlightbackground="#d9d9d9")
        self.Button2.configure(highlightcolor="black")
        self.Button2.configure(highlightthickness="0")
        self.Button2.configure(pady="0")
        self.Button2.configure(relief="flat")
        self.Button2.configure(text='''Crear''')
        self.Button2.configure(command=lambda:req_create(self.Entry1.get(),self.Entry1_1.get(),self.Entry2.get(),self.Entry3.get()) and tk.messagebox.showinfo(message="Creado con exito", title="Atencion"))
        
        self.Button1 = tk.Button(top)
        self.Button1.place(relx=0.753, rely=0.693, height=44, width=77)
        self.Button1.configure(activebackground="#ececec")
        self.Button1.configure(activeforeground="#000040")
        self.Button1.configure(background="#8080ff")
        self.Button1.configure(disabledforeground="#a3a3a3")
        self.Button1.configure(font="-family {Rockwell Condensed} -size 19")
        self.Button1.configure(foreground="#ffffff")
        self.Button1.configure(highlightbackground="#d9d9d9")
        self.Button1.configure(highlightcolor="black")
        self.Button1.configure(highlightthickness="0")
        self.Button1.configure(pady="0")
        self.Button1.configure(relief="flat")
        self.Button1.configure(text='''Login''')
        self.Button1.configure(command=lambda: ingresar(self.Entry1.get(),self.Entry1_1.get()) or self.Entry1.delete(0, tk.END) or self.Entry1_1.delete(0, tk.END) )
  
if __name__ == '__main__':
    vp_start_gui()
  
  