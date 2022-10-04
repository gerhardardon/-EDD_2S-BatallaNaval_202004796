#include <iostream>
#include <string>
using namespace std;

class nodoC {
public:
    int x;
    int y;
    nodoC* siguiente;

    nodoC(int x1,int y1) {
        siguiente = NULL;
        x = x1;
        y = y1;
    }
};


class colaTuto {
public: nodoC* primero;
      nodoC* ultimo;

      colaTuto() {
          primero = NULL;
          ultimo = NULL;
      }

      void agregar(int x, int y) {
          nodoC* nuevo = new nodoC(x,y);
          if (primero == NULL) {
              primero = nuevo;
          }
          else {
              nuevo->siguiente = NULL;
              ultimo->siguiente = nuevo;
          }
          ultimo = nuevo;
      }

      void textoDot() {
          string text = "";
          int i = 1;
          nodoC* aux = primero;
          text = "";
          text += "digraph G { \n";
          text += "node[shape=elipse] \n";
          cout << text << endl;
          text = "";
          while (aux != NULL) {
              if (i == 1) {
                  text += "nodo" + to_string(i) + " [label=\"" + "ANCHO:" + to_string(aux->x) + "\\nALTO:" + to_string(aux->y) + "\"]";
                  cout << text << endl;
                  text = "";
              }
              else {
                  text += "nodo" + to_string(i) + " [label=\"" + "X:" + to_string(aux->x) + "\\nY:" + to_string(aux->y) + "\"]";
                  cout << text << endl;
                  text = "";
              }


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
          nodoC* aux = primero;
          while (aux != NULL) {
              if (aux == primero) {
                  cout << "\tTablero" << endl;
                  cout << "\t\tAncho: " << aux->x << endl;
                  cout << "\t\tAlto:" << aux->y << endl;
                  cout << "\tMovimientos" << endl;
                  cout << "\t\t" << ends;
              }
              else if (aux == ultimo) {
                  cout << "(" << aux->x << "," << aux->y << ")" << ends;
              }
              else {
                  cout << "(" << aux->x << "," << aux->y << ")->" << ends;
              }
              aux = aux->siguiente;
          }
      }


      void eliminar() {
          nodoC* aux = primero;
          if (primero != NULL) {
              cout << aux->x << aux->y << endl;
              primero = aux->siguiente;
              aux = NULL;
          }

      }
};