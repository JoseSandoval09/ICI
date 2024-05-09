/*
Universidad Autonoma de Aguascalientes
Programacion Cientifica ICI 4A
Jose Luis Sandoval Perez
Ximena Rivera Delgadillo
Luis Fernando Guiterrez Marfileño

Este programa utiliza el metodo de simpson 1/3 y simpson 3/8 para obtener una aproximacion a la siguiente integral 

f(x)=x*e^2x en un intervalo de (0,3)

*/

#include<iostream>
#include<math.h>

double SacarF(double x);
void simpson1_3();
void simpson3_8();


using namespace std;


int main(){

    int op;


    cout<<"\t--------P R O Y E C T O    F I N A L ---------"<<endl;
    cout<<"Este programa utiliza el metodo de simpson 1/3 y simpson 3/8 para obtener una aproximacion a la siguiente integral f(x)=x*e^2x en un intervalo de (0,3)"<<endl;


    do{

        cout<<"----Selecciona una opcion-----\n1.Simpson 1/3\n2.Simpson 3/8\n3.Salir\nOpcion: ";cin>>op;

        system("pause");
        system("cls");

        switch (op)
        {
            case 1:
                simpson1_3();
            break;

            case 2: 
                simpson3_8();
            break; 

            default: {
                system("pause");
                system("cls");
            }
        }


    } while(op!=3);

    cout<<"----------------------------------C O N C L U S I O N---------------------------------------------\n";
    cout<<"Nos podemos dar cuenta que el metodo de Simpson 1/3 demuestra un porcentaje de error mas bajo en comparacion al metodo 3/8. Por lo tanto podemos concluir que el metodo 1/3 resulta ser mas efectivo a la hora de obtener aproximaciones de integrales.Tambien nos pudimos dar cuenta que la regla simpson 1/3 presenta un menor costo computacional.La regla de 1/3 resulta ser mas precisa para funciones suaves y continuas. Sin embargo, la regla de Simpson 3/8 puede proporcionar una mejor aproximacion en algunos casos, especialmente cuando la funcion presenta oscilaciones o comportamientos no suaves."<<endl;
    cout<<"--------------------------------------------------------------------------------------------------\n";
	cout<<"Programa elaborado por:\nJose Luis Sandoval Perez\nXimena Rivera Delgadillo\n";



   

    
    

    

    








}

double SacarF(double x){
    return x*exp(2*x);
}

void simpson1_3(){

    double a,b,n;

    cout<<"Ingresa el intervalo superior: ";
    cin>>a;
    cout<<"Ingresa el intervalo inferior: ";
    cin>>b;
    cout<<"Ingrese el numero de subintervalos: ";
    cin>>n;



    double h=(a-b)/n;

   double Area=0;

   Area=SacarF(a)+SacarF(b);


   double pinicial=0;



    for(int i=0;i<n-1;i++){
        pinicial=pinicial+h;

        if(i%2==0){
            Area+= 4.0*SacarF(pinicial);
        }else{
            Area+=2.0*SacarF(pinicial);
        }

    }

  


    Area=(h/3)*Area;

    cout<<"La aproximacion de la integral con Simpson 1/3 es :"<<Area<<endl;

    double h4,f4,er,error;
    h4=(h*h*h*h);
    f4=(16*1.5+32)*exp(2*1.5);

    error=h4*f4 / -180;

    cout<<"El error es de:"<<error<<endl;

    system("pause");
    system("cls");

}

void simpson3_8(){


    int a,b,n;

    cout<<"Ingresa el intervalo superior: ";
    cin>>a;
    cout<<"Ingresa el intervalo inferior: ";
    cin>>b;
    cout<<"Ingrese el numero de subintervalos (tiene que ser multiplo de 3 o no se asegura un resultado correcto): ";
    cin>>n;
    

    double h;

    h=(a-b)/3;


   double x[n],fx[n];

    x[0]=0;
    x[n]=3;

   for(int i=1;i<3;i++){
        x[i]=x[i-1]+h;
       
   }

  
   for(int i=0;i<=3;i++){
        fx[i]=SacarF(x[i]);
        
   }

    double sumfx=(fx[1]+fx[2])*3;
    
    double tres=(3*h)/8;

   double area= tres*(fx[0]+sumfx+fx[n]);

    cout<<"La aproximacion de la integral con Simpson 3/8 es :"<<area<<endl;

    double h5,f4,er,error;
    h5=(h*h*h*h*h);
    f4=(16*1.5+32)*exp(2*1.5);

    error=(h5*f4)*-0.0375;

    cout<<"El error es de:"<<error<<endl;

    system("pause");
    system("cls");

}