//JOSE LUIS SANDOVAL PEREZ 2°A ICI
//EXAMEN PARCIAL 2 ESTRUCTURAS COMPUTACIONALES II 
//PROBLEMA 12.5



#include<iostream>
#include<stdlib.h>

using namespace std;


struct Carritos{
    int num_car;
    Carritos *sig;
    Carritos *ant;
};

struct caja{
    int cajas;
    caja *sig;
    caja *ant;
};

//FUNCIONES
void insertarcliente(int,int,int);
void pagarCliente(int);

Carritos *frentec=NULL;
Carritos *finc=NULL;

caja *frenteca=NULL;
caja *finca=NULL;

int cont_cli=0;
int cliente=0,carrito=1;
int contcaj1=0,contcaj2=0,contcaj3=0;
int caja1=0,caja2=0,caja3=0;
int cajapagada;

void Menu(){

    int cajasec, opcion;
    

    do{
        cout<<"S U P E R W I C H O"<<endl;

        cout<<"1. Insertar cliente."<<endl;
        cout<<"2. Pagar cliente"<<endl;
        cout<<"3. Cierre de supermercado"<<endl;
        cout<<"Selecciona opcion: ";
        cin>>opcion;

        /*
        cout<<"\n\n";
        system("pause");
        system("cls");
        */
    
        switch(opcion){
            case 1:{
            cout<<"Bienvendidos al super W I C H O "<<endl;
            /*
            cout<<"Selecciona a que caja quieres pasar entre 1-2-3";
            cout<<"Caja seleccionada: ";
            cin>>cajasec;
            */
            cont_cli=caja1+caja2+caja3;
            cliente=cont_cli;

           if(cont_cli >= 25){
            cout<<"NUMERO MAXIMO DE CARRITOS OCUPADOS ESPERE A QUE SE DESOCUPE UN CARRITO ";
            }
            else{
            cout<<"Eres el cliente "<<cliente+1<<" formado "<<endl;

            cout<<"C A J A 1 ------> "<<caja1<<" clientes"<<endl;
            cout<<"C A J A 2 ------> "<<caja2<<" clientes"<<endl;
            cout<<"C A J A 3 ------> "<<caja3<<" clientes"<<endl;
                        

            cout<<"En que caja deseas pagar (1 , 2 , 3) :  ";
            cin>>cajasec;

            
            if(cajasec==1){
                contcaj1++;
                caja1++;
            }
            else if(cajasec==2){
                contcaj2++;
                caja2++;
            }
            else if(cajasec==3){
                contcaj3++;
                caja3++;
            }




            cliente++;
            cont_cli++;
            carrito++;
            insertarcliente(cliente,cont_cli,cajasec);
            }

            
            system("pause");
            system("cls");

            break;
                    
            }
            case 2:
            {
                

                
                cout<<"EN QUE CAJA PAGARA EL CLIENTE: ";
                cin>>cajapagada;
                /*
                if(caja1==0 && cajapagada==1){
                    cout<<"No hay clientes en la caja 1";
                }
                else{
                    pagarCliente(cajapagada);
                    cont_cli--;
                    if(cont_cli<10){
                    cout<<"Pueden pasar mas clientes"<<endl;
                    }
                }
                
                if(caja2==0 && cajapagada==2){
                    cout<<"No hay clientes en la caja 2";
                }
                else{
                    pagarCliente(cajapagada);
                    cont_cli--;
                    
                }
                if(caja3==0 && cajapagada==3){
                    cout<<"No hay clientes en la caja 3";
                }
                else{
                    pagarCliente(cajapagada);
                    cont_cli--;
                    if(cont_cli<10){
                    cout<<"Pueden pasar mas clientes"<<endl;
                    }
                }
                */

               pagarCliente(cajapagada);
               cont_cli--;
                


                break;
            }
            
            
        }
        



    }while(opcion!=3);

}

void insertarcliente(int c,int cont_cli,int cajasec){

    

        if(frentec==NULL && finc==NULL){
            finc=new Carritos();
            frentec= new Carritos;
            finc->num_car=c;
            finc->sig=NULL;
            finc->ant=NULL;
            frentec=finc;
            
        }
        else if(finc==frentec){

            finc=new Carritos;
            finc->num_car=c;
            finc->sig=NULL;
            finc->ant=frentec;
            frentec->sig=finc;
        }
        
        else{

            Carritos *nuevo = new Carritos();
            nuevo->num_car=c;
            nuevo->ant=finc;
            nuevo->sig=NULL;
            finc->sig=nuevo;
            finc=nuevo;
            

        }

    
    

}
void pagarCliente(int cp){

    

        if(frentec=finc){
            frentec=NULL;
            finc=NULL;

        }
        else if(finc->ant == frentec || frentec->sig== finc){
            frentec->sig=NULL;
            finc=frentec;
        }
        else{
            Carritos *borrar= new Carritos();
            borrar=finc;
            finc= finc->ant;
            finc->sig=NULL;
            delete borrar; 
        }

        if(cp==1){
            caja1--;
        }
        else if(cp==2){
            caja2--;
        }
        else if(cp==3){
            caja3--;
        }

    
    
}




int main(){

    Menu();
    return 0;



}