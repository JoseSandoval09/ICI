//PROYECTO 2 parcial II
//PROGRAMA II
//Estructuras Computacionales 2°A (PARCIAL 2)
/*
Ángel David Ortiz Quiroz        ID: 261481
Ximena Rivera Delgadillo        ID: 261261
Erick Ivan Ramirez Reyes        ID: 260806
Diego Emanuel Saucedo Ortega    ID: 261230
Jose Luis Sandoval Perez        ID: 261731
Carlos Daniel Torres Macias     ID: 244543
*/


#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0




class nodo {
   public:
    nodo(int v, nodo *sig = NULL, nodo *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;

   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() : plista(NULL) {}
    ~lista();

    void Insertar(int v);
    void Borrar(int v);
    void Buscar(int v);
    bool ListaVacia() { return plista == NULL; }
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    int ValorActual() { return plista->valor; }

   private:
    pnodo plista;
};

lista::~lista() {
   pnodo aux;

   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}

void lista::Insertar(int v) {
   pnodo nuevo;

   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual
      nuevo = new nodo(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga
      // un valor mayor que v
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodo(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void lista::Borrar(int v) {
   pnodo nodo;

   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   if(!nodo || nodo->valor != v) return;
   // Borrar el nodo

   if(nodo->anterior) // no es el primer elemento
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
}


void lista::Mostrar(int orden) {
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->siguiente;
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}

void lista::Siguiente() {
   if(plista) plista = plista->siguiente;
}

void lista::Anterior() {
   if(plista) plista = plista->anterior;
}

void lista::Primero() {
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo() {
   while(plista && plista->siguiente) plista = plista->siguiente;
}

int main() {
	int op, dato;
	lista Lista;

    do {
        cout << "\t.:MENU:.\n";
        cout << "1. Insertar elementos a la lista de id's\n";
        cout << "2. Mostrar elementos de lista de id's en orden ascendente\n";
        cout << "3. Mostrar elementos de lista de id's en orden descendente\n";
        cout << "4. Eliminar un elemento de la lista\n";
        cout << "5. Salir\n";
        cin >> op;

        switch (op) {
        case 1: cout << "Digite un numero: ";
            cin >> dato;
            Lista.Insertar(dato);
            system("pause");
            break;
        case 2: Lista.Mostrar(ASCENDENTE);
            cout << "\n";
            system("pause");
            break;
        case 3: Lista.Mostrar(DESCENDENTE);
            cout << "\n";
            system("pause");
            break;
        case 4: cout << "Digite el ID que desea eliminar: ";
            cin >> dato;
            Lista.Borrar(dato);
            cout << "\nListo";
            system("pause");
        }
        system("cls");
    } while (op != 5);
   
	cout << "---------------------------------------------------------------------------------\n";
    cout << "PROGRAMA HECHO POR:" << endl;
    cout << "Angel David Ortiz Quiroz        ID : 261481" << endl;
    cout << "Ximena Rivera Delgadillo        ID : 261261" << endl;
    cout << "Erick Ivan Ramirez Reyes        ID : 260806" << endl;
    cout << "Diego Emanuel Saucedo Ortega    ID : 261230" << endl;
    cout << "Jose Luis Sandoval Perez        ID : 261731" << endl;
    cout << "Carlos Daniel Torres Macias     ID : 244543" << endl;
 
  



   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;

   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;



   return 0;
}
