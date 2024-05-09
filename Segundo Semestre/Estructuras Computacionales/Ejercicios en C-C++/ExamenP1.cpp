/*CAPTURAR DE N TRABAJADORES:
-Nombre []
-Piezas elaboradas por dia de semana inglesa[]
-Cantidad mayor de piezas[]
-Cantidad menor de piezas[]

Calcular
1.El o los trabajadores que obtuvieron el mayor numero de piezas
semanales.[]
2. Indicar de cada trabajador que dia o dias de la semana obtuvo produccion menor.[]
3. Hacer otra version del programa que permita capturar dias de trabajo x trabajador.
4. Eliminar trabajadores 
**NOTA**

Manejar una funcion que reciba al menos como parametro un arreglo.
Agregar de cada punto un autoevaulaucion y tiempo de realizacion.



*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


using namespace std;


struct Informacion{


    char Name[30];
    int diamay=0,diamen=9999;
    int dias[5];
    int totalpiez;


}Trabajadores[100];

void Menu();
void CapturaDeDatos(int *);
void MostrarDatos(int *);
void MayorTrabajadores(int *);
void Captura_Dias( int [], int&);
void EliminarDatos(int *);
int trab, *ntTrab, empExistentes=0;


int MaximoPiezas_Trabajadores=-9999;

int main(){

	int op=0;   

    do{
        
        
        cout<<"Bienvenido usario este programa simulara una registro de n trabajadores.\n";
        cout<<"Los datos que se pediran seran:\n1. Nombre\n2. Piezas elaboradas por dia.\n";
        cout<<"El programa mostrara la base de datos.\n";
        cout<<"Adicionalemente mostrara el dia con menor y mayor produccion de piezas por trabajador.\n";
        cout<<" Y por ultimo el trabajador que mas piezas realizo en la semana.";
        cout<<"\n\t---MENU----"<<endl;
        cout<<"1. Agregar informacion de trabajadores"<<endl;
        cout<<"2. Desplegar informacion de trabajadores"<<endl;
        cout<<"3. Eliminar trabajadores"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Selecciona una opcion: "; 
        cin>>op;
       


		fflush(stdin);

        if(op==1){

            cout<<"Cuantos trabajadores deseas capturar: "<<endl;
            cin>>trab;
            ntTrab= &trab;
            CapturaDeDatos(&trab);
            empExistentes+=trab;
            system("pause");
            system("cls");
            
        }
        if(op==2 && trab>0){
            MostrarDatos(&trab);
            system("pause");
            system("cls");
        }
        else{
            cout<<"Despues de 10 horas de programacion no ingresaste lo correcto, tiene que ser mayor que 0 :)";
        }
       
        if(op==3){
            EliminarDatos(&trab);
            system("pause");
            system("cls");
        }
        
        
    }while(op!=4);

   

}


void CapturaDeDatos(int *ntTrab){

    
    

    cout<<"Perfecto tu registro sera de "<<*ntTrab<<" trabajadores"<<endl;;
    system("pause");
    system("cls");

    cout<<"\n\n-----EMPEZARA LA CAPTURA-----"<<endl;

    for(int i=empExistentes;i<*ntTrab+empExistentes;i++){

        fflush(stdin);

        //Captura informacion trabajadores

        cout<<"Nombre trabajador  "<<i+1<<": "<<endl; 
        gets(Trabajadores[i].Name);

        //Funcion captura piezas por dia de la semana
        Captura_Dias(Trabajadores[i].dias, Trabajadores[i].totalpiez);
    }

    

}


void MostrarDatos(int *ntTrab){

    char ElMejor[30];
    cout<<"-----REGISTRO DE TRABAJADORES-----";
    cout<<"\n\n\n\n";
    for(int i=0;i<empExistentes;i++){

        cout<<"---------------------------------"<<endl;
        cout<<"TRABAJADOR:  "<< i+1<<endl;

        cout<<"Nombre: "<<Trabajadores[i].Name<<endl;
        for(int j=0;j<5;j++){
        
            cout<<"Piezas realizadas en el dia "<<j+1<<" : "<<Trabajadores[i].dias[j]<<endl;
            if(Trabajadores[i].dias[j]>Trabajadores[i].diamay){
                Trabajadores[i].diamay=Trabajadores[i].dias[j];
                Trabajadores[i].dias[j];
            }
            if(Trabajadores[i].dias[j]<Trabajadores[i].diamen){
                Trabajadores[i].diamen=Trabajadores[i].dias[j];
            }
            
            
        }

        cout<<"El dia de mayor producuccion fue: "<<Trabajadores[i].diamay<<endl;
        cout<<"El dia de menor produccion fue: "<<Trabajadores[i].diamen<<endl;
        cout<<"Total de piezas: "<<Trabajadores[i].totalpiez<<endl;

        cout<<"---------------------------------"<<endl;

    }
    MayorTrabajadores(ntTrab);

}

void MayorTrabajadores(int *ntTrab){

    for(int i=0;i<*ntTrab;i++){

        if(Trabajadores[i].totalpiez>MaximoPiezas_Trabajadores){
            MaximoPiezas_Trabajadores=Trabajadores[i].totalpiez;
        }

    }

    cout<<"---------------------------------"<<endl;
    for(int i=0;i<*ntTrab;i++){

        if(Trabajadores[i].totalpiez==MaximoPiezas_Trabajadores){
            cout<<"El de produccion maxima fue: "<<Trabajadores[i].Name<<endl;
        }

    }
    cout<<"---------------------------------"<<endl;    

}
void Captura_Dias(int semana[], int &totalpiezas){

    totalpiezas=0;
    for(int j=0;j<5;j++){
        cout<<"Piezas realizadas en el dia "<<j+1<<" :";
        fflush(stdin);
        cin>>(semana[j]);

        totalpiezas+=semana[j];     
    }

}

void EliminarDatos( int *ntTrab){

    cout<<"A continuacion ingresa el registro del trabajador que quieras eliminar"<<endl;

    for(int i=0;i<empExistentes;i++){
        cout<<i+1<<".  "<<Trabajadores[i].Name<<endl;
    }


    int borrar=0;
    cout<<"Que numero de trabajador quieres borrar"<<endl;
    cin>>borrar;

    if(borrar>empExistentes-1){

        for(int i=borrar-1;i<empExistentes;i++){

            strcpy(Trabajadores[i].Name, Trabajadores[i+1].Name);
            Trabajadores[i].diamay=Trabajadores[i+1].diamay;
            Trabajadores[i].diamen=Trabajadores[i+1].diamen;
            Trabajadores[i].totalpiez=Trabajadores[i+1].totalpiez;
            for(int j=0;j<5;j++){

                Trabajadores[i].dias[j]=Trabajadores[i+1].dias[j];
            }
            

        }
    }
    
    *ntTrab--;

}