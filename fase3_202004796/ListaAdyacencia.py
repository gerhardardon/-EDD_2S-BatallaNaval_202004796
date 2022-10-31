from os import system
import webbrowser


class nodoAdy:
    def __init__(self, num):
        self.num = num
        self.list = None
        self.siguiente = None

class adyacente:
    def __init__(self):
        self.primero=None
        self.ultimo=None
    
    def inicializar(self,x):
        i=0
        while i<x:
            nuevo=nodoAdy(i)

            if (self.primero==None):
                self.primero=nuevo
            else:
                self.ultimo.siguiente=nuevo
            self.ultimo=nuevo
            i+=1

    def agregarList(self,num,num2):
        aux = self.primero
        while (aux != None):

            if aux.num==num:
                if aux.list==None:
                    aux.list=listaIntern()
                aux.list.agregar(num2)
            aux = aux.siguiente
    
    def imprimir(self):
        aux = self.primero
        while (aux != None):
            if aux.list!=None:
                print(aux.num,"->")
                aux.list.imprimir()
            else:
                print(aux.num,"-> Vacio")
            aux = aux.siguiente
    
    def grafo(self):
        text="digraph G {\n"
        aux = self.primero
        while (aux != None):
            if aux.list!=None:
                text+=str(aux.num)+"->"+aux.list.grafo()+"\n"
            
            aux = aux.siguiente
        
        text+="}"

        with open('grafo.dot', 'w') as f:
            f.write(text)
        try:
            system('dot -Tpng ' +  'grafo.dot -o ' +  'grafo.png')
            webbrowser.open_new_tab( 'grafo.png')
        except:
            print("")

    def adyacencia(self):
        text="digraph G {\nnode[shape=elipse]\n"
        aux = self.primero
        while (aux != None):
            text+="nodo"+str(aux.num)+ " [label=\""+str(aux.num)+"\",group=1]"+"\n"
            if aux.list!=None:
                text+=aux.list.adyacencia(str(aux.num))
            if aux.num>0:
                text+="nodo"+str(aux.num-1)+"->"+"nodo"+str(aux.num)+"\n"

            aux = aux.siguiente
        
        text+="}"
        with open('adyacencia.dot', 'w') as f:
            f.write(text)
        try:
            system('dot -Tpng ' +  'adyacencia.dot -o ' +  'adyacencia.png')
            webbrowser.open_new_tab( 'adyacencia.png')
        except:
            print("")


class nodoIntern:
    def __init__(self,num):
        self.num = num
        self.siguiente = None

class listaIntern:
    def __init__(self):
        self.primero=None
        self.ultimo=None

    def agregar(self,num):
        nuevo=nodoIntern(num)
        if (self.primero==None):
            self.primero=nuevo
        else:
            self.ultimo.siguiente=nuevo
        self.ultimo=nuevo
    
    def imprimir(self):
        aux = self.primero
        while (aux != None):
            print(" ",aux.num,end="")
            aux = aux.siguiente
        print("")
    
    def grafo(self):
        text=""
        aux = self.primero
        while (aux != None):
            if aux.siguiente!=None:
                text+=str(aux.num)+","
            else:
                text+=str(aux.num)
            aux = aux.siguiente
        return text

    def adyacencia(self,cat):
        text=""
        i=2
        aux = self.primero
        while (aux != None):
            text+="nodo_"+cat+str(i)+" [label=\""+str(aux.num)+"\",group="+str(i)+"]\n"
            if(i>2):
                text+="nodo_"+cat+str(i-1)+"->"+"nodo_"+cat+str(i)+"\n"
            i+=1
            aux=aux.siguiente
        
        text+="nodo"+cat+"->"+"nodo_"+cat+"2\n"
        text+="{rank=same;nodo"+cat+";"
        j=2
        while j<i:
            text+="nodo_"+cat+str(j)+";"
            j+=1
        text+="}\n"
        return text


"""lst=adyacente()
lst.inicializar(10)
lst.agregarList(0,3)
lst.agregarList(1,1)
lst.agregarList(1,8)
lst.agregarList(2,7)
lst.agregarList(3,5)
lst.agregarList(4,3)
lst.agregarList(4,8)
lst.agregarList(6,1)
lst.agregarList(6,5)
lst.agregarList(7,2)
lst.agregarList(7,9)
lst.agregarList(9,6)
lst.agregarList(9,1)


lst.imprimir()

lst.adyacencia()
lst.grafo()"""