from tablaHash import*
class nodoCarrito:
    def __init__(self,id,name):
        self.id = id
        self.name=name
        self.siguiente = None

class listaCarrito:
    def __init__(self):
        self.primero=None
        self.ultimo=None

    def agregar(self,id,name):
        nuevo=nodoCarrito(id,name)
        if (self.primero==None):
            self.primero=nuevo
        else:
            self.ultimo.siguiente=nuevo
        self.ultimo=nuevo
    
    def imprimir(self):
        aux = self.primero
        while (aux != None):
            print(aux.id)
            aux = aux.siguiente
        print("")
    
    def clear(self):
        self.primero=None
        self.ultimo=None

    def crearHash(self):
        lstHash = hash()
        aux = self.primero
        while (aux != None):
            lstHash.agregar(int(aux.id),aux.name)
            aux = aux.siguiente
        lstHash.tablaHash()

    

