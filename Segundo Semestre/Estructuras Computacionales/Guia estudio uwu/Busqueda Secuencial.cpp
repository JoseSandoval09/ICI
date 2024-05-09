// UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
// ESTRUCTURAS COMPUTACIONALES II
// PROYECTO FINAL 3ER PARCIAL
// INTEGRANTES: 

// Carlos Leonardo Cruz Ortiz ID: 261696
// Leslie Miroslava Benítez Marín ID: 183817
// César Eduardo Elias del Hoyo ID: 262045

// ACTIVIDA 5
// Busqueda Secuencial

#include <bits/stdc++.h>
using namespace std;

int main(){
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
    
    int num;

    cout<<"\nNumero a buscar: "; cin>>num;

    bool found = false;

    for (int i = 0; i < 10; i++)
    {
        if (array[i] == num)
        {
            cout<<"El numero "<<num<<" se encuentra en la posicion "<<i + 1<<endl;
            found = true;
        }
    }
    
    if(!found)
    {
        cout<<"El numero "<<num<<" no se encuentra en el arreglo"<<endl;
    }

    system("pause");

    return 0;
}
