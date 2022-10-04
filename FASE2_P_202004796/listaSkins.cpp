#include <iostream>
#include <string>
using namespace std;

class nodoS {
public:
    int id, precio;
    string categoria, nombre, src;
    nodoS* siguiente;

    nodoS(int id2, string categoria2, int precio2, string nombre2, string src2) {
        id = id2;
        categoria = categoria2;
        precio = precio2;
        nombre = nombre2;
        src = src2;
        siguiente = NULL;
    }
};


class listaS {
public: nodoS* primero;
      nodoS* ultimo;

      listaS() {
          primero = NULL;
          ultimo = NULL;
      }

      void agregar(int id, string categoria, int precio, string nombre, string src) {
          nodoS* nuevo = new nodoS(id, categoria, precio, nombre, src);
          if (primero == NULL) {
              primero = nuevo;
          }
          else {
              nuevo->siguiente = NULL;
              ultimo->siguiente = nuevo;
          }
          ultimo = nuevo;
      }

      void textoDot(string cat, int fila) {
          string text = "";
          int i = 2;
          nodoS* aux = primero;
          while (aux != NULL) {
              text += "nodo_a" + cat + to_string(i) + " [label=\"" + "ID:" + to_string(aux->id) + "\\nPRECIO:" + to_string(aux->precio) + "\\nNOMBRE:" + aux->nombre + "\",group=" + to_string(i) + "]";
              cout << text << endl;
              text = "";

              if (i > 2) {
                  text += "nodo_a" + cat + to_string(i - 1) + "->" + "nodo_a" + cat + to_string(i);
                  cout << text << endl;
                  text = "";
              }
              while (aux->siguiente == primero) {


                  return;
              }
              i += 1;
              aux = aux->siguiente;
          }
          text += "nodo" + to_string(fila) + "->" + "nodo_a" + cat + "2";
          cout << text << endl;
          text = "";
          text = "{rank=same;nodo" + to_string(fila) + ";";
          for (int j = 2; j < i; j++) {
              text += "nodo_a" + cat + to_string(j) + ";";
          }
          text += "}";
          cout << text << endl;
      }

      void imprimir() {
          nodoS* aux = primero;
          while (aux != NULL) {
              cout << aux->id << "\r\t\t" << aux->nombre << "\r\t\t\t\t" << aux->categoria << "\r\t\t\t\t\t\t" << aux->precio << endl;
              aux = aux->siguiente;
          }
      }
};