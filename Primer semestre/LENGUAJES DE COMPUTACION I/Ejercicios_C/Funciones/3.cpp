#include <iostream>
#include <conio.h>
using namespace std;

void demo(int &valor)
{
valor=5;
cout<<" Dentro de la funcion a valor le asigno 5" <<endl;
cout<<"valor: "<<valor<<endl;
}

main()
{
  int n=10;
  cout<<"Antes de ir a la funcion, n: "<<n<<endl;
  cout<<" --- n Va a la Funcion demo por Referencia ---" <<endl;
  demo(n);
  cout<<" ---  Regreso de la Funcion demo ---" <<endl;
  cout<<"n: "<<n<<endl;
  getch();
}

//La salida de este programa será: 10  5  5
