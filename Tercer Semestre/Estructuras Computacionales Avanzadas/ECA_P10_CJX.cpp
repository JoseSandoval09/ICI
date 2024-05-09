#include <iostream>
#include <stdlib.h>
#define V 5
using namespace std;

struct Node
{
    int node = -1;
    int distance = 999;
    Node *root = NULL;Node *left = NULL;Node *right = NULL;
};

void BFS(Node *tree, int matrix[][V]);
void queue(Node *&tale, Node *add);
Node *descolar(Node *&tale);
void printTale(Node *tale);
char letter(int i);
void print(int matrix[][V]);

int matrix[V][V] = {
    {0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0 ,0 ,1 ,0},
};
int matrixTree[V][V] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0,0,0,0,0},
};

int main(int argc, char const *argv[])
{
	Node *TREE = new Node();TREE->node = 0;TREE->distance = 0;TREE->left = NULL;TREE->right = NULL;
	cout << "\t I N T R O D U C C I O N\n";
    cout << "  A traves del siguiente programa podremos realizar la implementacion de un algoritmo que recorre en \n";
    cout << "  anchura a un grafo creando un arbol abarcador.\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    
    BFS(TREE, matrix);
    cout << "\tP A S O S  del   r e c o r r i d o  en a n c h u r a" << endl;
    printTale(TREE);
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    cout << "\tM A T R I Z  del  a r b o l  r e s u l t a n t e" << endl;
    print(matrixTree);
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    cout << "PROGRAMA REALIZADO POR:\n";
    cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    return 0;
}

void BFS(Node *tree, int matrix[][V]){
    Node *cola = new Node();
    int node = tree->node;
    cola->node = tree->node;
    cola->distance = tree->distance;
    bool visit[V] = {0, 0, 0, 0,0};
    visit[node] = 1;
    while (cola != NULL)
    {
        Node *root = descolar(cola);
        if (root == NULL){break;}
        node = root->node;
        for (int i = 0; i < V; i++){
            if (matrix[node][i] != 0 && visit[i] == 0){
                visit[i] = 1;
                Node *adjacent = new Node();
                Node *adjacentCopy = new Node();
                adjacent->node = i;
                adjacentCopy->node = i;
                adjacent->distance = 1 + root->distance;
                adjacentCopy->distance = 1 + root->distance;
                adjacent->right = NULL;
                adjacentCopy->right = NULL;
                queue(cola, adjacent);
                queue(tree, adjacentCopy);
                matrixTree[node][i] = matrix[node][i];
            }
        }
    }
}

void queue(Node *&tale, Node *add){
    if (tale == NULL){
        tale = add;
    }
    else{
        Node *aux = tale;
        while (aux->right != NULL){
            aux = aux->right;
        }
        aux->right = add;
        add->left = aux;
    }
}
Node *descolar(Node *&tale){
    if (tale != NULL){
        Node *aux = new Node();
        aux->distance = tale->distance;
        aux->node = tale->node;
        tale = tale->right;
        delete (tale);
        return aux;
    }
}

void printTale(Node *tale){
    while (tale != NULL)
    {
        cout << "\t\t  El nodo (" << letter(tale->node) << ") con un nivel [" << tale->distance <<"]\n";
        tale = tale->right;
    }
}
char letter(int i){
    switch (i)
    {
    case 0:
        return 'a';
        break;
    case 1:
        return 'b';
        break;
    case 2:
        return 'c';
        break;
    case 3:
        return 'd';
        break;

    default:
        return '0';
        break;
    }
}

void print(int matrix[][V]){
    for (int i = 0; i < V; i++){
        cout<<"\t\t  ";
        for (int j = 0; j < V; j++){
            if (matrix[i][j] == 999){
            	cout << 0 << "\t";
			}   
            else{
            	cout << matrix[i][j] << "\t";
			}   
        }
        cout<<"\n";
    }
}

