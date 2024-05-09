//JOSE LUIS SANDOVAL PEREZ
//EXAMEN 2



#include <iostream>
#include <stdio.h>
#define SINGLE 0
using namespace std;




int wList[4][4] = 
{   {0,2,1,3},
    {2,3,1,0},
    {1,2,3,0},
    {3,1,0,2}
};
int mList[4][4] =
{
    {2, 1, 0, 3},
    {1,3,0,2},
    {2, 0, 3, 1},
    {0, 1, 2, 3}
};

int mMatch[4] = {0, 0, 0, 0};   
int wMatch[4] = {0, 0, 0, 0}; 
int mProposal[4] = {1,1, 0, 1}; 


int main()
{

    cout<<"PROGRAMA: Crear un programa que utilice el algoritmo de Gale-Shipley para definir una serie de matrimonios estables\n";
    
    bool hombreDisponible = true;
    int m = 0;
    while (hombreDisponible)
    {
        hombreDisponible = false;
        int w = mList[m][mProposal[m]++];
        if (wMatch[w] == SINGLE)
        {
            
            wMatch[w] = m;
            mMatch[m] = w;
        }
        else
        {
            
            bool Mpropuesta = false; 
            for (int i = 0; i < 4; i++)
            {
                if (wList[w][i] == wMatch[w])
                {
                    Mpropuesta = false;
                    break;
                }
                if (wList[w][i] == m)
                {
                    Mpropuesta = true;
                    break;
                }
            }
            if (Mpropuesta)
            {
              
                mMatch[wMatch[w]] = SINGLE;
                wMatch[w] = m;
                mMatch[m] = w;
            }
        }
        // Busca un hombre soltero
        for (int j = 0; j < 4; j++)
        {
            if (mMatch[j] == SINGLE)
            {
                m = j;
                hombreDisponible = true;
                break;
            }
        }
    }


    cout << "Algoritmo Gale-Shapley" << endl;

    cout<<"LA MATRIZ DE PREFERENCIA DE LAS MUJERES SE LEERAN DE ESTA FORMA: \n"<<endl; 
    cout<<"indice 0=DIEGO \nindice 1=JORGE \nindice 2=MATEO \nindice 3=PEDRO\n";
    cout<<"\nLA MATRIZ DE PREFERENCIA DE LOS  HOMBRES SE LEERAN DE ESTA FORMA: \n"<<endl; 
    cout<<"indice 0=ELENA \nindice 1=LAURA \nindice 2=JULIA \nindice 3=PAULA\n";

    cout<<"\nDE ESTA MISMA FORMA SE LEERA LOS MATRIMONIOS ESTABLES\n";
    
    cout << "Matriz de Preferencias de los Hombres: " << endl;
    for (int g = 0; g < 4; g++)
    {
        for (int d = 0; d < 4; d++)
        {
            cout << mList[g][d] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matriz de Preferencias de las Mujeres: " << endl;
    for (int h = 0; h < 4; h++)
    {
        for (int u = 0; u < 4; u++)
        {
            cout << wList[h][u] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\tMatrimonios Estables" << endl;
    for (int k = 0; k < 4; k++)
    {
        cout << "Hombre " << k << " y Mujer " << mMatch[k] << endl;
    }
    return 0;
}