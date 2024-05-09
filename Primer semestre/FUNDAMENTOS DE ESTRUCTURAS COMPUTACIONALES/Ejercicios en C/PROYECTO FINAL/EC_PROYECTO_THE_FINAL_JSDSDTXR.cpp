#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

/*
PROYECTO FINAL
Solicita la matriz de adyacencia al
usuario y se determina si es un grafo
bipartito, en caso de que sea se imprimen
los conjuntos.
Ximena Rivera Delgadillo ID:261261
José Luis Sandoval Perez ID: 261731
Diego Emanuel Saucedo Ortega ID:261230
Carlos Daniel Torres Macias ID:244543
*/

void askyFullofStars();
void cambiarTemaConsola();

int a[20],b[20],ady[20][20];
int main(){

    setlocale(LC_ALL,"spanish");
    askyFullofStars();
    cambiarTemaConsola();

    int op=-1;
    do{
        printf("PROYECTO FINAL: A partir de una matriz de adyacencia\n");
        printf("determina si se trata de un grafo bipartito.\n\n");

        printf("¿Qué desea hacer ahora?\n");
        printf("1. Ingresar un grafo.\n");
        printf("2. Cambiar el tema.\n");
        printf("3. Salir.\n");
        printf("Opción: ");
        scanf("%d",&op);

    if(op==1){
        int n;//numero de nodos

        printf("Ingrese el numero de nodos del grafo: ");
        scanf("%d",&n);
        printf("A continuación, ingrese las adyacencias del grafo.\n");
        printf("Ingrese (1) si existe un enlace entre los nodos.\n");
        printf("Ingrese (0) en caso de que los nodos no tengan relación.\n\n");
        system("pause");
        system("cls");

        printf("M A T R I Z  D E  A D Y A C E N C I A\n\n");

        int bipartito=1;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int p;
                printf("Nodo[%d] y Nodo[%d],¿Tienen relación?: ",i+1,j+1);
                scanf("%d",&p);
                if(p==1){
                    ady[i][j]=1;
                    ady[j][i]=1;
                    if(a[i]==1){b[j]=1;}
                    else if(a[j]==1){b[i]=1;}
                    else if(b[i]==1){a[j]=1;}
                    else if(b[j]==1){a[i]=1;}
                    else{a[i]=1; b[j]=1;}
                }
            }//fin for i
        }//fin for j

        system("pause");
        system("cls");

        printf("Matriz de Adyacencia generada:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("\t%d",ady[i][j]);
            }
            printf("\n");
        }

            for(int i=0;i<n;i++){
                if(a[i]==1 && b[i]==1){bipartito=0; break;}
                if(a[i]==0 && b[i]==0){bipartito=0; break;}
            }

        if(bipartito==1){
            printf("\nEl grafo es bipartito.\nA:");
            for(int i=0;i<n;i++){
                if(a[i]==1){printf("\t%d",i+1);}
            }

            printf("\nB:");
            for(int i=0;i<n;i++){
                if(b[i]==1){printf("\t%d",i+1);}
            }
        }
        else{printf("El grafo no es bipartito.\n");}

        printf("\n\n");
    }//fin caso1

    if(op==2){cambiarTemaConsola();}

    system("pause");
    system("cls");

    }while(op!=3);

    system("cls");
    printf("Goodbye!\n");
    printf("Hecho por:\nXimena Rivera Delgadillo ID:261261\n");
    printf("José Luis Sandoval Perez ID: 261731\n");
    printf("Diego Emanuel Saucedo Ortega ID:261230\n");
    printf("Carlos Daniel Torres Macias ID:244543\n");
    system("pause");

return 0;
}

void askyFullofStars(){
int t=3;//veces que se muestran estrellas
    do{
    char skyFullofStars[10][21]={
    "....................","....................",
    "....................","....................",
    "....................","....................",
    "....................","....................",
    "....................","...................."};

    for(int k=0;k<(rand()%10)+7;k++){//numero de estrellas min 7
        int i=(rand()%9)+1;
        int j=(rand()%19)+1;
        skyFullofStars[i][j]='*';
    }//fin for k

    for(int i=0;i<10;i++){
        printf("%s\n",skyFullofStars[i]);
    }//fin for i

    printf("............WELCOME!\n");
    Sleep(600);//segundos entre cada pantalla
    system("cls");
    t--;
    }while(t>0);
}

void cambiarTemaConsola(){
    system("cls");
    int op=-1;
    do{
        printf(" T E M A S\n");
        printf("1.System Default\n");
        printf("2.Cherry\n");
        printf("3.MatrixEyes\n");
        printf("4.Aqua\n");
        printf("5.Hazard\n");
        printf("6.Guardar y salir\n");
        printf("---------------------------\n");
        printf("Seleccione una opción\n");
        scanf("%d",&op);
        system("cls");
        switch(op){
            case 1://System Default
                printf("SYSTEM DEFAULT\n");
                printf("------------------\n");
                system("color 0C");
            break;
            case 2://Cherry
                printf("SYSTEM CHERRY\n");
                printf("------------------\n");
                system("color 4F");
            break;
            case 3://MatrixEyes
                printf("SYSTEM MATRIX EYES\n");
                printf("------------------\n");
                system("color 02");
            break;
            case 4://Aqus
                printf("SYSTEM AQUS\n");
                printf("------------------\n");
                system("color B0");
            break;
            case 5://Hazard
                printf("SYSTEM HAZARD\n");
                printf("------------------\n");
                system("color E0");
            break;
            case 6:
                printf("Cambios guardados\n");
                printf("------------------\n");
            break;
            default:
                printf("Tema No disponible\n");
                printf("------------------\n");
            break;
        }//fin switch

    }while(op!=6);
}