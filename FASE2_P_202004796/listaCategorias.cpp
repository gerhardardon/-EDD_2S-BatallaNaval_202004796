#include <iostream>
#include "listaSkins.cpp"
#include <string>
using namespace std;

class nodoL {
public:
    string categoria;
    nodoL* siguiente;
    listaS lista2;

    nodoL() {
        siguiente = NULL;
    }
};


class lista {
public: nodoL* primero;
      nodoL* ultimo;

      lista() {
          primero = NULL;
          ultimo = NULL;
      }

      void agregar(string categoria) {
          nodoL* nuevo = new nodoL();
          nuevo->categoria = categoria;
          if (primero == NULL) {
              primero = nuevo;
          }
          else {
              nuevo->siguiente = NULL;
              ultimo->siguiente = nuevo;
          }
          ultimo = nuevo;
      }

      void agergarLista(int id, string categoria, int precio, string nombre, string src) {
          nodoL* aux = primero;
          while (aux != NULL) {
              if (aux->categoria == categoria) {
                  aux->lista2.agregar(id, categoria, precio, nombre, src);
                  //cout<<categoria<<": Nodo agregado"<<endl;
              }
              aux = aux->siguiente;
          }

      }

      void textoDot() {
          string text = "";
          int i = 1;
          nodoL* aux = primero;
          text = "";
          text += "digraph G { \n";
          text += "node[shape=elipse] \n";
          cout << text << endl;
          text = "";
          while (aux != NULL) {
              text += "nodo" + to_string(i) + " [label=\"" + aux->categoria + "\",group=1]";
              cout << text << endl;
              text = "";
              aux->lista2.textoDot(aux->categoria, i);
              if (i > 1) {
                  text += "nodo" + to_string(i - 1) + "->" + "nodo" + to_string(i);
                  cout << text << endl;
                  text = "";
              }
              while (aux->siguiente == primero) {
                  text += "nodo" + to_string(i) + "->" + "nodo" + to_string(1);
                  cout << text << endl;
                  text = "";

                  return;
              }
              i += 1;
              aux = aux->siguiente;
          }
      }

      bool compararCategoria(string categoria) {
          nodoL* aux = primero;
          while (aux != NULL) {
              while (aux->siguiente == primero) {
                  if (aux->categoria == categoria) {
                      return true;
                  }
                  else {
                      return false;
                  }
              }
              if (aux->categoria == categoria) {
                  return true;
              }
              aux = aux->siguiente;
          }
          return false;
      }

      void imprimir() {
          nodoL* aux = primero;
          while (aux != NULL) {
              cout << aux->categoria << endl;
              aux->lista2.imprimir();

              aux = aux->siguiente;
          }
      }
};
