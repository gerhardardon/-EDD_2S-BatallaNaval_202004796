from mimetypes import init
from multiprocessing.pool import INIT
from os import system
import webbrowser
from xml.dom import InvalidCharacterErr

colisiones=0
class nodoHash:
    def __init__(self,indice):
        self.indice=indice
        self.id=None
        self.nombre=None
        self.siguiente=None

class hash:
    def __init__(self):
        global colisiones
        colisiones=0
        self.primero=None
        self.ultimo=None
        i=1
        while i<=13:
            nuevo=nodoHash(i)
            if (self.primero==None):
                self.primero=nuevo
            else:
                self.ultimo.siguiente=nuevo
            self.ultimo=nuevo
            i+=1

    def obtenerId(self,llave):
        id=llave % self.ultimo.indice
        return id

    def colision(self,llave,name):
        global colisiones
        colisiones+=1
        newId= (llave%3+1)*colisiones
        newId=newId+self.obtenerId(llave)

        aux=self.primero
        while(aux!=None):
            if aux.indice==newId:
                if aux.id!=None:
                    self.colision(llave)
                else:
                    aux.id=llave
                    aux.nombre=name
            aux=aux.siguiente
        

    def rehash(self,ocupados):
        newIndice=self.ultimo.indice+1
        while newIndice <= ocupados/0.2:
            nuevo=nodoHash(newIndice)
            self.ultimo.siguiente=nuevo
            self.ultimo=nuevo
            newIndice+=1

    def ocupacion(self):
        ocupados=0
        aux=self.primero
        while (aux!=None):
            if aux.id!=None:
                ocupados+=1
            aux=aux.siguiente
        
        if ocupados/self.ultimo.indice>0.8:
            print("---porcentaje excedido")
            self.rehash(ocupados)

    def agregar(self,llave,name):
        aux=self.primero
        while (aux!=None):
            if aux.indice== self.obtenerId(llave):
                print("indice encontrado")
                if aux.id!=None:
                    print("---colision")   
                    self.colision(llave,name)
                else:
                    aux.id=llave
                    aux.nombre=name
                    print("agregado")
                    self.ocupacion()
                
            aux=aux.siguiente


    def imprimir(self):
        aux=self.primero
        while (aux!=None):
            print(aux.indice,"->",aux.id)
            aux=aux.siguiente
    
    def tablaHash(self):
        text="""digraph example {

node [shape=plaintext]
rankdir=TB

B [
label=<
  <TABLE BORDER="0" CELLBORDER="1" CELLSPACING="0">
 
   <TR PORT="header">
    <TD BGCOLOR="#d23939" COLSPAN="3">HASH</TD>
   </TR>
   
   <TR>
    <TD BGCOLOR="#ff6363">indice</TD> <TD BGCOLOR="#ff6363">id</TD><TD BGCOLOR="#ff6363">nombre</TD>
   </TR>\n"""
        aux=self.primero
        while (aux!=None):
            if aux.id!=None:
                text+="<TR><TD PORT=\"1\">"+str(aux.indice)+"</TD><TD>"+str(aux.id)+"</TD><TD>"+str(aux.nombre)+"</TD></TR>\n"
            aux=aux.siguiente
        text+="""</TABLE>
>];

}"""
        with open('hash.dot', 'w') as f:
            f.write(text)
        try:
            system('dot -Tpng ' +  'hash.dot -o ' +  'hash.png')
            webbrowser.open_new_tab( 'hash.png')
        except:
            print("")


"""lstHash = hash()
lstHash.agregar(3,"e")
lstHash.agregar(16,"w")
lstHash.agregar(29,"r")
lstHash.imprimir()
lstHash.tablaHash()"""