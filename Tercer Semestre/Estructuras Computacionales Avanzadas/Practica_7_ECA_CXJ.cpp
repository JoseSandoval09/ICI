/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Se va a crear un programa para generar un arbol de expansion
minima dado un grafo.

*/

#include<iostream>

using namespace std;

int matriz_grafo[9][9]={

    {0,6,0,10,0,0,8,0,0},
    {6,0,11,0,15,0,0,13,0},
    {0,11,0,0,0,0,0,4,0},
    {10,0,0,0,6,0,0,0,0},
    {0,15,0,6,0,2,0,0,0},
    {0,0,0,0,2,0,4,0,6},
    {8,0,0,0,0,4,0,5,5},
    {0,13,4,0,0,0,5,0,7},
    {0,0,0,0,0,6,5,7,0}

};

int matriz_arbol[9][9];

int padre[9];

void Kruskal(int matriz[9][9]);
int encontrar(int i);
int unir(int i, int j);


int main(){

    int op;

    cout<<"Implementacion Algoritmo Kruskal"<<endl;

    cout<<"\t--------MENU--------"<<endl;
    cout<<"1.Calcular arbol de expansion minima y arbol resultante\n2.Salir"<<endl;
    cout<<"Selecciona una opcion: ";
    cin>>op;

    switch (op)
    {
    case 1:
        Kruskal(matriz_grafo);
        break;
    case 2:
        cout<<"Decidiste salir, hasta pronto!";
        cout << "PROGRAMA REALIZADO POR:\n";
        cout << "Elias Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
        cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
    break;

    default:
        cout<<"Opcion no valida, saliendo...";
        break;
    }
    


}

void Kruskal( int matriz_grafo[9][9]){

    int i,j,T=0,min,a,b,u,v,costminimo=0;
    int n=9; //numero de vertices del grafo
    //leeemos la matriz de adyacencia inicializada y llenamos con peso 999 los caminos con 0
    for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(matriz_grafo[i][j]==0){
			matriz_grafo[i][j]=999;
            }
		}
	}
    //imprimimos matriz de adyacencia generada e inicializada
    cout << "M A T R I Z   de  A D Y A C E N C I A S\n";
    for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout<<"["<<matriz_grafo[i][j]<<"]"<<" ";
        }
        cout << "\t";
    }
    cout<<"\n";

    //llenado matriz arbol resultante con 0
      for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			matriz_arbol[i][j]=0;
		}
	}



    while(T<n-1){ //falta comentario

        for(i=0,min=999;i<9;i++) //recorrido de matriz para ver arista de menor peso
		{
			for(j=0;j <9;j++)
			{
				if(matriz_grafo[i][j] < min)
				{
					min=matriz_grafo[i][j];
					a=u=i;
					b=v=j;
                    
                    matriz_arbol[i][j]=matriz_arbol[j][i]=matriz_grafo[a][b];

    
				}
                
			}
		}
        

        u=encontrar(u);
        v=encontrar(v);
        
        if(unir(u,v)){
            
            cout<<"\nPeso arista de "<<a<<"--->>"<<b<<" ="<<min;
            T++;
            costminimo+=min;
            
        
        }

       
        matriz_grafo[a][b]=matriz_grafo[b][a]=999;
       


        
    }

    

    cout<<"\nCosto minimo de recorrido = "<<costminimo;
    
    cout<<"\n\n";

     for (i = 0; i < n; i++) {
        cout << "\n";
        for (j = 0; j < n; j++) {
            cout<<"["<<matriz_arbol[i][j]<<"]"<<" ";
        }
        cout << "\t";
    }
    




}

int encontrar(int i){

    
    while (padre[i])
    {
        i=padre[i];
        
    }
    return i;
    
    
}

int unir(int i,int j){

    
    if(i!=j){
        padre[j]=i;
        return 1;
    }
    return 0;

    

}

