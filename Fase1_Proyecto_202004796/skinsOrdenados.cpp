#include <iostream>
using namespace std;

class nodoS2{
public:
    int id,precio;
    string categoria,nombre,src;
    nodoS2* siguiente;
    nodoS2* anterior;

    nodoS2(int id2,string categoria2,int precio2,string nombre2,string src2){
        id=id2;
        categoria=categoria2;
        precio=precio2;
        nombre=nombre2;
        src=src2;
        siguiente=NULL;
        anterior=NULL;
    }
};


class listaS2{
public: nodoS2* primero;
        nodoS2* ultimo;

    listaS2(){
        primero=NULL;
        ultimo=NULL;
    }

    void agregar(int id,string categoria,int precio,string nombre,string src){
        nodoS2* nuevo = new nodoS2(id,categoria,precio,nombre,src);
        if (primero==NULL){
            primero=nuevo;
        }else{
            nuevo->siguiente=NULL;
            ultimo->siguiente=nuevo;
        }
        ultimo=nuevo;
    }

   void insert(int id,string categoria,int precio,string nombre,string src){
        nodoS2* nuevo = new nodoS2(id,categoria,precio,nombre,src);
        if (primero==NULL){
            primero=nuevo;
            ultimo=nuevo;
        }else {//si la lista no esta vacia
            nodoS2*auxActual = primero;
            nodoS2*auxSiguiente;
            while (auxActual->siguiente != primero) {
                auxSiguiente = auxActual->siguiente;

                if (nuevo->precio < auxActual->precio) {//insertar al inicio de la lista por que es menor
                    nuevo->siguiente = auxActual;
                    primero = nuevo;
                    auxActual->anterior=nuevo;
                    nuevo->anterior=ultimo;
                    ultimo->siguiente=nuevo;
                    
                    break;
                } else if (auxSiguiente == NULL) {//insertar al final de la lista
                    auxActual->siguiente = nuevo;
                    nuevo->anterior=auxActual;
                    nuevo->siguiente=primero;
                    primero->anterior=nuevo;

                    break;
                } else if (nuevo->precio < auxSiguiente->precio) {//insertar en medio de la lista
                    auxActual->siguiente = nuevo;
                    nuevo->anterior=auxActual;
                    nuevo->siguiente = auxSiguiente;
                    auxSiguiente->anterior=nuevo;
                    break;
                }
                auxActual = auxActual->siguiente;
            }
        }
    }

    void imprimirAscendente(){
        nodoS2* aux=primero;
        while (aux!=NULL){
            cout<< aux->id <<"\r\t\t"<<aux->nombre<<"\r\t\t\t\t"<<aux->categoria<<"\r\t\t\t\t\t\t"<<aux->precio<< endl;
            while (aux->siguiente==primero){
                return;
            }
            aux = aux->siguiente;
        }
    }
    void imprimirDescendente(){
        nodoS2* aux=ultimo;
        while (aux!=NULL){
            cout<< aux->id <<"\r\t\t"<<aux->nombre<<"\r\t\t\t\t"<<aux->categoria<<"\r\t\t\t\t\t\t"<<aux->precio<< endl;
            while (aux->anterior==ultimo){
                return;
            }
            aux = aux->anterior;
        }
    }
};