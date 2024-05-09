
#include<iostream>
using namespace std;

//d e c l a r a c i o n  m a t r i z  g r a f o
int matriz_grafo[9][9] = {
    {999,6,999,10,999,999,8,999,999},
    {6,999,11,999,15,999,999,13,999},
    {999,11,999,999,999,999,999,4,999},
    {10,999,999,999,6,999,999,999,999},
    {999,15,999,6,999,2,999,999,999},
    {999,999,999,999,2,999,4,999,6},
    {8,999,999,999,999,4,999,5,5},
    {999,13,4,999,999,999,5,999,7},
    {999,999,999,999,999,6,5,7,999}
};
//i n i c i a l i z a r  variables
int matriz_arbol[9][9]; //matriz del arbol
int padre[9]; //vector padre auxiliar
void Kruskal(int matriz[9][9]); //funcion de kruskal con paso de la matriz inicial
int encontrar(int i); // funcion encontrar
int unir(int i, int j);//funcion unir


int main() {
    //i n i c i a l i z a r  variables
    int op; //opcion menu
    //i n t r o d u c c i o n  del  p r o g r a m a
    cout << "\tI N T R O D U C C I O N  del  p r o g r a m a" << endl;
    cout << "El siguiente programa nos permitira generar a partir de un grafo conexo, no dirigido y con pesos en los arcos,\n";
    cout << "un arbol de expansion minima compuesto por todos los nodos y cuya suma de sus arcos es la de menor peso.\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");

    //m e n u  p r i n c i p a l
    do {
        //o p c i o n e s  del  m e n u
        cout << "\tM  E  N  U    K  r  u  s  k  a  l \n";
        cout << "1)CALCULAR a r b o l de expansion minima y a r b o l resultante\n2)Salir" << endl;
        cout << "Ingrese la opcion seleccionada: "; cin >> op; //leer seleccion menu
        cout << "\n-------------------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
        //f u n c i o n  s w i t c h  para desarrollar las opciones
        switch (op)
        {
        case 1:
            //o p c i o n  1  algoritmo
            cout << " I m p l e m e n t a c i o n   A l g o r i t m o   K r u s k a l" << endl;
            Kruskal(matriz_grafo);
            cout << "\n-------------------------------------------------------------------------------------------------" << endl;
            system("pause");
            system("cls");
            break;
        case 2:
            //o p c i o n  1  salir
            cout << "S A L I R  S A L I R  S A L I R" << endl;
            cout << "PROGRAMA REALIZADO POR:\n";
            cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
            cout << "\n-------------------------------------------------------------------------------------------------" << endl;
            system("pause");
            system("cls");
            return 0;
            break;
        default:
            cout << "E R R O R  E R R O R  E R R O R" << endl;
            cout << "\n-------------------------------------------------------------------------------------------------" << endl;
            system("pause");
            system("cls");
            break;
        };
    } while (op!=2);

    cout << "S A L I R  S A L I R  S A L I R" << endl;
    cout << "PROGRAMA REALIZADO POR:\n";
    cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
    return 0;
}
//f u n c i o n   K R U S K A L
void Kruskal(int matriz_grafo[9][9]) {
    //i n i c i a l i z a r  variables
    int i=0, j=0, T = 0, min=999, a=0, b=0, u=0, v=0, costminimo = 0;
    int n = 9; //numero de vertices del grafo
    //imprimimos matriz de adyacencia generada e inicializada
    cout << "\n\n";

    // i m p r i m i r  matriz grafo inicial
    cout << "\t M A T R I Z   de  A D Y A C E N C I A S  g r a f o  i n i c i a l\n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout << "\t[" << matriz_grafo[i][j] << "]" << " ";
        }
        cout << "\t";
    }
    cout << "\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;

    //i n i c i a l i z a c i o n  matriz arbol
    for (i = 0; i < 9; i++){for (j = 0; j < 9; j++){matriz_arbol[i][j] = 999;}}
    //c i c l o  mientras T sea menor a n-1 donde n =9
    while (T < n - 1) { 
        //r e c o r r e r   matriz para obtener la de menor peso 
        for (i = 0, min = 999; i < 9; i++) //inicializacion minimo como 999
        {
            for (j = 0; j < 9; j++)
            {
                if (matriz_grafo[i][j] < min)//si el valor de la matriz de pesos es menor al valor anterior seleccionado como minimo 
                {
                    min = matriz_grafo[i][j]; //el nuevo valor toma el valor de minimo
                    a = u = i; //copiar la variable renglon (i) a las variables (u) y (a)
                    b = v = j;//copiar la variable columna (j) a las variables (u) y (a)
                }

            }
        }
        //igualamos los valores (u) y (v) a la fucnion encontrar 
        u = encontrar(u); v = encontrar(v);
        //condicion donde si los valores que guardamos de (u)
        if (unir(u, v)) {
            cout << "\n PESO A R I S T A de (" << a << " a " << b << ") =" << min;
            cout << "\n";
            T++;
            costminimo += min;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (i == a && j == b) {
                        matriz_arbol[i][j] = matriz_arbol[j][i] = matriz_grafo[a][b];

                    }
                }
            }
        }
        matriz_grafo[a][b] = matriz_grafo[b][a] = 999;
    }
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    cout << "\n C O S T O  m i n i m o  de  r e c o r r i d o = " << costminimo;
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n";
    cout << "     M A T R I Z   de  A D Y A C E N C I A S  a r b o l  r e s u l t a n t e\n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout << "\t[" << matriz_arbol[i][j] << "]" << " ";
        }
        cout << "\t";
    }
}

int encontrar(int i) {
    while (padre[i])
    {i = padre[i];}
    return i;
}
int unir(int i, int j) {
    if (i != j) {
        padre[j] = i;
        return 1;
    }
    return 0;
}

