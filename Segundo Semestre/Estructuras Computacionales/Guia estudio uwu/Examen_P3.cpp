#include<iostream>
#include<time.h>
#include<chrono>
#include<ctime>


using namespace std;


int Arreglo_A[2000];
int Arreglo_B[500];


void Ordenacion_Lista_A_Quicksort(int a[], int primero, int ultimo){

    int i, j;
    int pivote;

    pivote=a[(primero + ultimo)/2];
    i=primero;
    j=ultimo;

    do{

        while(a[i]<pivote){
            i++;
        }
        while(a[j]>pivote){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }


    }while(i<=j);

    if(primero<j){
        Ordenacion_Lista_A_Quicksort(a,primero,j);
    }
    if(ultimo>i){
        Ordenacion_Lista_A_Quicksort(a,i,ultimo);
    }

    



}


void busqueda_binaria_A(int a[]){

    cout<<"B U S Q U E D A     B I N A R I A   LISTA A"<<endl;


    int min=0, max1=1999, max2=499;
    bool existe= false;
    int mitad1=(min+max1)/2;

    int num1;

    cout<<"Que numero deseas buscar: ";
    cin>>num1;

    //BUSQUEDA BINARIA LISTA A

    clock_t t;

    
    

    while(min<=max1){
        t=clock();
        if(a[mitad1==num1]){
            cout<<"El elemento "<< num1 << " se encuetra dentro de la lista A";
            existe= true;
            break;

        }
        else if(a[mitad1<num1]){
            min=mitad1+1;
        }
        else{
            max1=mitad1-1;
        }
        mitad1=(min+max1)/2;

        t+=clock()-t;
    }
    

    
    
    
    cout<<"\nEl tiempo en hacer la busqueda fue de "<<float(t)/CLOCKS_PER_SEC<<" segundos"<<endl;

    

    


}
void busqueda_secuencial_A(int A[]){
    
    cout<<"B U S Q U E D A   S E C U E N C I A L     LISTA A"<<endl;

    bool existe=false;
    int num;

    cout<<"Que numero quieres buscar: ";
    cin>> num;

   clock_t t;

    
    for(int i=0;i<1999;i++){
        t=clock();
        if(A[i]==num){
            cout<<"El elemento" << num << "se encontro en la lista";
        }
        t+=clock()-t;
    }


    
    cout<<"\nEl tiempo en hacer la busqueda fue de "<<float(t)/CLOCKS_PER_SEC<<" segundos"<<endl;
    

   
}

void busqueda_secuencial_B(int B[]){
    
    cout<<"B U S Q U E D A   S E C U E N C I A L     LISTA B"<<endl;

    unsigned t0,t1;

    bool existe=false;
    int num;

    cout<<"Que numero quieres buscar: ";
    cin>> num;

    clock_t t;

    for(int i=0;i<499;i++){
        t=clock();
        if(B[i]==num){
            cout<<"El elemento" << num << "se encontro en la lista"<<endl;
        }
        t+=clock()-t;
    }
    

    double timeSecuencial_B= (double(t1-t0)/CLOCKS_PER_SEC);

  cout<<"\nEl tiempo en hacer la busqueda fue de "<<float(t)/CLOCKS_PER_SEC<<" segundos"<<endl;

   

}




int main(){

    srand(time(NULL));

    int Arreglo_A[2000];
    int Arreglo_B[500];

    for(int i=0;i<2000;i++){
        Arreglo_A[i]=rand()%1999;
    }
    for(int i=0;i<500;i++){
        Arreglo_B[i]=rand()%1999;
    }

    //Funciones para ordenar listas
    Ordenacion_Lista_A_Quicksort(Arreglo_A,0,1999);
    
    

    busqueda_binaria_A(Arreglo_A);
    busqueda_secuencial_A(Arreglo_A);
    busqueda_secuencial_B(Arreglo_B);




    
   






}




