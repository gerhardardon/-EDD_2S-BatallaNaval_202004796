#include <iostream>
using namespace std;

class nod{
public:
    string name;
    string password;
    int coins;
    int age;
    nod* siguiente;
    nod* anterior;

    nod(string nombre,string contra,int monedas,int edad){ //Constructor
        name=nombre;
        password=contra;
        age=edad;
        coins=monedas;
        anterior=NULL;
        siguiente=NULL;
    }
};

class orden{
public:
    nod* primero;
    nod* ultimo;
    orden(){
        primero=NULL;
        ultimo=NULL;
    }


    void insert(string nombre,string contra,int monedas,int edad){
        nod* nuevo = new nod(nombre,contra,monedas,edad);
        if (primero==NULL){
            primero=nuevo;
            ultimo=nuevo;
        }else {//si la lista no esta vacia
            nod*auxActual = primero;
            nod*auxSiguiente;
            while (auxActual->siguiente != primero) {
                auxSiguiente = auxActual->siguiente;

                if (nuevo->age < auxActual->age) {//insertar al inicio de la lista por que es menor
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
                } else if (nuevo->age < auxSiguiente->age) {//insertar en medio de la lista
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
        nod* aux=primero;
        while (aux!=NULL){
            cout<<"NOMBRE: "<<aux->name<<"  CONTRASEÑA: "<<aux->password<<"  MONEDAS: "<<aux->coins<<"  EDAD: "<<aux->age<<endl;
            while (aux->siguiente==primero){
                return;
            }
            aux = aux->siguiente;
        }
    }

    void imprimirDescendente(){
        nod* aux=ultimo;
        while (aux!=NULL){
            cout<<"NOMBRE: "<<aux->name<<"  CONTRASEÑA: "<<aux->password<<"  MONEDAS: "<<aux->coins<<"  EDAD: "<<aux->age<<endl;
            while (aux->anterior==ultimo){
                return;
            }
            aux = aux->anterior;
        }
    }

};