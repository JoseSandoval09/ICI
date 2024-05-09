#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string postfijo;
int tope=0;

class Operandos{
    public:
    char simbolo;
    int jerarquia;
};

Operandos pila[10];
Operandos parIzq;
Operandos parDer;
Operandos suma;
Operandos resta;
Operandos multiplicacion;
Operandos division;
Operandos potencia;

void Push(Operandos operador){
    if(tope==0){
        pila[tope].jerarquia=operador.jerarquia;
        pila[tope].simbolo=operador.simbolo;
        tope++;
    }else{
        //Insertar comprobacion de parentesis cerrado
        if(operador.simbolo==41){
            int tmp= tope-1;
            while(pila[tmp].simbolo!=40){
                postfijo+=pila[tmp].simbolo;
                tmp--;
            }
            tope=tmp;
        }else{
            if(operador.jerarquia>pila[tope-1].jerarquia || (operador.jerarquia==3 && (operador.jerarquia==pila[tope-1].jerarquia))|| operador.jerarquia==0){
                pila[tope].jerarquia=operador.jerarquia;
                pila[tope].simbolo=operador.simbolo;
                tope++;
            }else{
                if(operador.jerarquia==pila[tope-1].jerarquia){
                    postfijo+=pila[tope-1].simbolo;
                    pila[tope-1].simbolo=operador.simbolo;
                }else{
                    while(pila[tope-1].jerarquia > operador.jerarquia){
                        postfijo+=pila[tope-1].simbolo;
                        tope--;
                    }
                    if(operador.jerarquia==pila[tope-1].jerarquia){
                        postfijo+=pila[tope-1].simbolo;
                        pila[tope-1].simbolo=operador.simbolo;
                    }else{
                        pila[tope].jerarquia=operador.jerarquia;
                        pila[tope].simbolo=operador.simbolo;
                        tope++;
                    }
                }
            }
        }
       
    }
}

bool Comprobar(char valor){
    if((valor>96 && valor<125)||(valor>64 && valor<91)|| valor==40 || valor== 41 || valor== 42 || valor== 43 ||valor== 45 || valor== 47 || valor== 94)
        return true;
    else
        return false;
}

void Posicionar(char valor){
    if((valor>96 && valor<125)||(valor>64 && valor<91))
        postfijo+=valor;
    else{
        switch (valor)
        {
            case 40:
                Push(parIzq);
                break;
            case 41:
                Push(parDer);
                break;
            case 43:
                Push(suma);
                break;
            case 45:
                Push(resta);
                break;
            case 42:
                Push(multiplicacion);
                break;
            case 47:
                Push(division);
                break;
            case 94:
                Push(potencia);
                break;
        }
    }
}

int main(){
    char infijo[50];

    //Parentesis izquierdo
    parIzq.jerarquia=0;
    parIzq.simbolo=40;
    //Parentesis derecho  
    parDer.jerarquia=0;
    parDer.simbolo=41;
    //Suma
    suma.jerarquia=1;
    suma.simbolo=43;
    //Resta
    resta.jerarquia=1;
    resta.simbolo=45;
    //Multiplicacion
    multiplicacion.jerarquia=2;
    multiplicacion.simbolo=42;
    //Division
    division.jerarquia=2;
    division.simbolo=47;
    //Potencia
    potencia.jerarquia=3;
    potencia.simbolo=94;

    cout<<"\nExpresion infija: ";
    cin>>infijo;
    cout<<endl;

    for(int i=0; i<strlen(infijo);i++){
        if(Comprobar(infijo[i])){
            Posicionar(infijo[i]);
        }else{
            cout<<"\n Valor "<<infijo[i]<<" incorrecto";
        }
    }

    //Concatenar lo que queda en la pila
    for(int i=tope;i>=0;i--){
        if(pila[i].simbolo!=40)
            postfijo+= pila[i].simbolo;
    }

    cout<<"\nPostfijo: "<<postfijo<<"\n";
}