// JOSE LUIS SANDOVAL PEREZ
// EXAMEN PARCIAL 2
// ARBOL DE EXPANSION MINIMA

#include<bits/stdc++.h>
using namespace std;



int MG[5][5]{

    /*      A    B   C   D    E*/ 
    /*A*/   999, 3,  1,  999, 999,
    /*B*/   3,  999, 7, 5,     1,
    /*C*/   1, 7,   999, 2,999,
    /*D*/   999,5, 2, 999,7,
    /*E*/   999,1,999,7,999

};

int MA[5][5]; 
int padre[5]; 
void Kruskal(int MG[5][5]); 
int encontrar(int i);
int unir(int i, int j);
int op;


int main() {
    
    
    
    cout << "El siguiente programa nos permitira generar un arbol de expansion minima a partir de un grafo dado, asi como el recorrido seguido para la obtencion del mismo\n";
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");

    

    do {
        
        cout<<"\t\tMENU\n";
        
        cout << "1)arbol de expansion minima, recorrido y matriz resultante\n2)Salir" << endl;
        cout << "Ingrese la opcion deseada: "; cin >> op;
        cout << "\n-------------------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
        
        switch (op)
        {
            case 1:{
                
                cout << " ARBOL DE EXPANSION MINIMA" << endl;
                Kruskal(MG);
                cout << "\n-------------------------------------------------------------------------------------------------" << endl;
                system("pause");
                break;
            }   
            default:{
                cout<<"OPCION INVALIDA";
            } 

        }
    } while (op!=2);

    system("cls");
    cout<<"Decidiste salir...";


    return 0;
}

void Kruskal(int MG[5][5]) {
    
    int i=0, j=0, TW = 0, min=999, a=0, b=0, u=0, v=0, costminimo = 0;
    int n = 5; 
    cout << "\n\n";


    cout << "\t Matriz adyacencia del grafo inicial: \n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout << "\t[" << MG[i][j] << "]" << " ";
        }
        cout << "\t";
    }
    cout << "\n";
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;


    cout<<"LAS POSICIONES DE LA MATRIZ SE LEERAN DE ESTA FORMA: \n"<<endl; 
    cout<<"indice 0=NODO A\nindice 1=NODO B\nindice 2=NODO C\nindice 3=NODO D,\nindice 4=NODO E\n";

    cout<<"\n RECORRIDO Y PESOS DE LAS ARISTAS:\n";




   
    for (i = 0; i < 5; i++){for (j = 0; j < 5; j++){MA[i][j] = 999;}}
    
    while (TW < n - 1) { 
        
        for (i = 0, min = 999; i < 5; i++) 
        {
            for (j = 0; j < 5; j++)
            {
                if (MG[i][j] < min)
                {
                    min = MG[i][j]; 
                    a = u = i; 
                    b = v = j;
                }

            }
        }
        
        u = encontrar(u); 
        v = encontrar(v);
       
        if (unir(u, v)) {
            cout << "\n PESO A R I S T A de (" << a << " -> " << b << ") =" << min;
            cout << "\n";
            TW++;
            costminimo += min;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (i == a && j == b) {
                        MA[i][j] = MA[j][i] =MG[a][b];

                    }
                }
            }
        }
        MG[a][b] = MG[b][a] = 999;
    }
    cout << "\n-------------------------------------------------------------------------------------------------" << endl;
    cout << "\n costo minimo del recorrido = " << costminimo<<endl;
    cout << "Matriz adyacencia del arbol resultante : \n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout << "\t[" << MA[i][j] << "]" << " ";
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

