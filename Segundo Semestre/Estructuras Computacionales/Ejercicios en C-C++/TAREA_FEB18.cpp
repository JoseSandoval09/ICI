#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct Node {
 int data;
 struct Node* next;
};
int main()
{
 //llenado de null en nodos
 
 Node* one = NULL;
 Node* two = NULL;
 Node* three = NULL;
 Node* four = NULL;
 Node* five = NULL;
 Node* tmp = NULL;
 one = new Node();
 two = new Node();
 three = new Node();
 four = new Node();
 five = new Node();
 tmp = new Node();
 one->data = 10;
 one->next = two;
 two->data = 20;
 two->next = three;
 three->data = 30;
 three->next = four;
 four->data = 40;
 four->next = NULL;
 five->data = 50;
 five->next = NULL;
 tmp->data = 0;
 tmp->next = NULL;
 std::cout << "LISTA DE DATOS" << std::endl;
 
 tmp = one;
 int cont=1;
 while (tmp != NULL) {
 std::cout << "Dato "<< cont<< "en la lista:";
 cout << tmp->data << "\n";
 tmp = tmp->next;
 cont++;
 }
 
 five->next = two->next;
 two->next = five;
 
 std::cout << "LISTA DE DATOS con nodo agregado" << 
std::endl;
 tmp = one;
 cont=1;
 while (one != NULL) {
 std::cout << "Dato "<< cont<<"en la lista:";
 cout << one->data << "\n";
 one = one->next;
 cont++;
 }
 
return 0;
}
