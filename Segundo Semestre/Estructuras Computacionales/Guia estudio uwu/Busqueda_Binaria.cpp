// UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
// ESTRUCTURAS COMPUTACIONALES II
// PROYECTO FINAL 3ER PARCIAL
// INTEGRANTES: 

// Carlos Leonardo Cruz Ortiz ID: 261696
// Leslie Miroslava Ben�tez Mar�n ID: 183817
// C�sar Eduardo Elias del Hoyo ID: 262045

// ACTIVIDA 5
// Busqueda Binaria

#include<iostream>
#include<time.h>
using namespace std;

int main(){

    // Busqueda binaria
    int array[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        array[i] = rand()%1000 + 1;
        if(i < 9)
        {
            cout<<array[i]<<", ";
        }
        else
        {
            cout<<array[i];
        }
    }

    int num, low = 0, high = 9;

    cout<<"\nNumero a buscar: "; cin>>num;

    bool found = false;

    int mid = (low + high) / 2;

    while(low <= high)
    {
        if(array[mid] == num)
        {
            cout<<"El numero "<<num<<" se encuentra en la posicion "<<mid + 1<<endl;
            found = true;
            break;
        }
        else if(array[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    if(!found)
    {
        cout<<"El numero "<<num<<" no se encuentra en el arreglo"<<endl;
    }

    system("pause");

    return 0;
}
