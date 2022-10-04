#include <iostream>
#include <string>
using namespace std;

class nodoX {
public:
    int x;
    int y;
    nodoX* siguiente;

    nodoX(int x2, int y2) {
        x = x2;
        y = y2;
        siguiente = NULL;
    }
};


class pilaM {
public: nodoX* primero;
      nodoX* ultimo;

      pilaM() {
          primero = NULL;
          ultimo = NULL;
      }

      void agregar(int x, int y) {
          nodoX* nuevo = new nodoX(x, y);
          if (primero == NULL) {
              primero = nuevo;
          }
          else {
              nuevo->siguiente = primero;
              primero = nuevo;
          }
          ultimo = nuevo;
      }

      void textoDot() {
          string text = "";
          int i = 1;
          nodoX* aux = primero;
          text = "";
          text += "digraph G { \n";
          text += "node[shape=elipse] \n";
          cout << text << endl;
          text = "";
          while (aux != NULL) {

              text += "nodo" + to_string(i) + " [label=\"" + "X:" + to_string(aux->x) + "\\nY:" + to_string(aux->y) + "\"]";
              cout << text << endl;
              text = "";



              if (i > 1) {
                  text += "nodo" + to_string(i) + "->" + "nodo" + to_string(i - 1);
                  cout << text << endl;
                  text = "";
              }
              while (aux->siguiente == primero) {
                  return;
              }
              i += 1;
              aux = aux->siguiente;
          }
      }

      void imprimir() {
          nodoX* aux = primero;
          while (aux != NULL) {
              if (aux == ultimo) {
                  cout << "(" << aux->x << "," << aux->y << ")" << ends;
              }
              else {
                  cout << "(" << aux->x << "," << aux->y << ")->" << ends;
              }
              aux = aux->siguiente;
          }
      }

      string eliminar() {
          nodoX* aux = primero;
          if (primero != NULL) {
              string coordenadas = aux->x + "," + aux->y;
              
              cout << coordenadas << endl;
              primero = aux->siguiente;
              aux = NULL;
              return coordenadas;
          }

      }
};