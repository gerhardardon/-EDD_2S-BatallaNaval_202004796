#include <iostream>
using namespace std;

class nodo{
public:
    string name;
    string password;
    int coins;
    int age;
    nodo* siguiente;
    nodo* anterior;

    nodo(string nombre,string contra,int monedas,int edad){ //Constructor
        name=nombre;
        password=contra;
        age=edad;
        coins=monedas;
        anterior=NULL;
        siguiente=NULL;
    }
};

class listaUser{
public:
    nodo* primero;
    nodo* ultimo;
    listaUser(){
        primero=NULL;
        ultimo=NULL;
    }

    void insert(string nombre,string contra,int monedas,int edad){
        nodo* nuevo=new nodo(nombre,contra,monedas,edad);
        if (primero==NULL){
            primero=nuevo;
        }else{
            nuevo->anterior=ultimo;
            nuevo->siguiente=primero;
            ultimo->siguiente=nuevo;
            primero->anterior=nuevo;
        }
        ultimo=nuevo;
    }

    bool compararNombre(string nombre){
        nodo* aux=primero;
        while (aux!=NULL){
            while (aux->siguiente==primero){
                if(aux->name==nombre){
                return true;
                }else{
                    return false;
                }
            }
            if(aux->name==nombre){
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }

    bool login(string nombre,string contra){
        nodo* aux=primero;
        while (aux!=NULL){
            if(aux->name==nombre and aux->password==contra){
                return true;
            }
            while (aux->siguiente==primero){
                if(aux->name==nombre and aux->password==contra){
                return true;
                }else{
                    return false;
                }
            }
            
            aux = aux->siguiente;
        }
        return false;
    }

    void editarUsuario(string name,string new_name,string new_pass,int new_age){
        nodo* aux=primero;
        while (aux!=NULL){
            if(aux->name==name){
                aux->name=new_name;
                aux->password=new_pass;
                aux->age=new_age;
                return;
            }
            while (aux->siguiente==primero){
                if(aux->name==name){
                    aux->name=new_name;
                    aux->password=new_pass;
                    aux->age=new_age;
                    return;
                }else{
                    return ;
                }
            }
            aux = aux->siguiente;
        }
    }
    
    void agregarPuntos(string name){
        nodo* aux=primero;
        while (aux!=NULL){
            if(aux->name==name){
                aux->coins=(aux->coins)+1;
                return;
            }
            while (aux->siguiente==primero){
                if(aux->name==name){
                    aux->coins=(aux->coins)+1;
                    return;
                }else{
                    return ;
                }
            }
            aux = aux->siguiente;
        }
    }

    void borrar(string nombre){
        nodo* aux=primero;
        while (aux!=NULL){
            if(aux->name==nombre){
                if(aux==primero){
                    primero=aux->siguiente;
                }else if(aux==ultimo){
                    ultimo=aux->anterior;
                }
                aux->anterior->siguiente=aux->siguiente;
                aux->siguiente->anterior=aux->anterior;
                aux->anterior=NULL;
                aux->siguiente=NULL;
                delete aux;
                cout<<"Usuario borrado"<<endl;
                return;
            }
            while (aux->siguiente==primero){
                cout<<"No hay coincidencias"<<endl;
                return;
            }
            aux = aux->siguiente;
        }  
    }

    void imprimir(){
        nodo* aux=primero;
        while (aux!=NULL){
            cout<<"NOMBRE: "<<aux->name<<"  CONTRASEÑA: "<<aux->password<<"  MONEDAS: "<<aux->coins<<"  EDAD: "<<aux->age<<endl;
            while (aux->siguiente==primero){
                return;
            }
            aux = aux->siguiente;
        }
    }

    void textoDot(){
        string text="";
        int i=1;
        nodo* aux=primero;
        text="";
        text+="digraph G { \n";
        text+="node[shape=elipse] \n";
        cout<<text<<endl;
        text="";
        while (aux!=NULL){
            text+="nodo"+to_string(i)+" [label=\""+"NOMBRE:"+aux->name+"\\nCONTRA:"+aux->password+"\\nMONEDAS:"+to_string(aux->coins)+"\\nEDAD:"+to_string(aux->age)+"\"]";
            cout<<text<<endl;
            text="";
            
            if(i>1){
                text+="nodo"+to_string(i-1)+"->"+"nodo"+to_string(i);
                cout<<text<<endl;
                text="";
                text+="nodo"+to_string(i)+"->"+"nodo"+to_string(i-1);
                cout<<text<<endl;
                text="";
            }
            while (aux->siguiente==primero){
                text+="nodo"+to_string(i)+"->"+"nodo"+to_string(1);
                cout<<text<<endl;
                text="";
                text+="nodo"+to_string(1)+"->"+"nodo"+to_string(i);
                cout<<text<<endl;
                text="";
                return;
            }
            i+=1;
            aux = aux->siguiente;
        }
    }

};
