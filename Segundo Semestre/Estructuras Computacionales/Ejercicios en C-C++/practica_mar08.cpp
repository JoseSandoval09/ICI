#include <iostream>

using namespace std;

int main()
{
struct Nodo{
int dato;
Nodo *sig, *ant;
};
//Variales
Nodo *inicio, *tmp;
int cantidad, datoBusca;

inicio = new Nodo();
inicio->dato = 1;
inicio->sig = inicio->ant = NULL;
cout<<"Cuantos nodos adicionales al que tengo: ";
cin>>cantidad;
for(int conta=1; conta<=cantidad; conta++){
//crear nodo
tmp = new Nodo();
tmp->dato = conta+1;
tmp->sig = inicio;
inicio->ant = tmp;
tmp->ant = NULL;
inicio = tmp;
}
cout<<"\nLista de inicio a fin: ";
//Recorrer la lista
tmp = inicio;
while(tmp->sig != NULL){
cout<< tmp->dato <<" ,";
tmp = tmp->sig;
}
cout<< tmp->dato;

 cout<<"\nLista de fin a inicio: ";
//Recorrido de reversa
while(tmp != NULL){
cout<< tmp->dato <<" ,";
tmp = tmp->ant;
}

 //Buscar la lista y dejar un puntero antes
cout<<"Que dato quieres buscar: ";
cin>>datoBusca;
tmp = inicio;
while((tmp != NULL) && (tmp->dato != datoBusca)){
tmp = tmp->sig;
}
if (tmp != NULL)
cout<<"Se encocntro";
else
cout<<"No se encontro";

return 0;
}