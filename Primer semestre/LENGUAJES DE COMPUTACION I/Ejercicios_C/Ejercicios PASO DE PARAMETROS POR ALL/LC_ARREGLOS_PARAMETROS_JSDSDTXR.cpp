#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*
EJERCICIO: Funciones (Paso de Arreglos Por Valor; Pasar de arreglos por referencia)
Lenguajes de Computación 1°E  (PARCIAL 3)
Ximena Rivera Delgadillo ID:261261
José Luis Sandoval Perez ID: 261731
Diego Emanuel Saucedo Ortega ID:261230
Carlos Daniel Torres Macias ID:244543
*/

void insertarArticulo(char A[][20],int N[],int &articulos);
void quitarArticulo(char A[][20],int N[],int quitar,int &articulos);

int main(){
    system("color 70");
    setlocale(LC_ALL,"spanish");

    int articulos=0,op=0;

    char art[20][20];
    int num[20];

    do{
        printf("----Lista de compras----\n");
        if(articulos==0){printf("No tienes articulos en tu lista :p\n");}
        else{
            for(int i=0;i<articulos;i++){
                printf("%d.%s     Cantidad:%d\n",i+1,art[i],num[i]);
            }
        }

        printf("\n--->Opciones<---\n");
        printf("1.Insertar articulo a la lista\n");
        printf("2.Borrar articulo de la lista\n");
        printf("3.Salir\n");
        printf("¿Qué desea hacer?: ");
        scanf("%d",&op);

        if(op==1){insertarArticulo(art,num,articulos);}

        if(op==2){
            int q;
            printf("Ingrese articulo a eliminar: ");
            scanf("%d",&q);
            quitarArticulo(art,num,q,articulos);
        }

        system("pause");
        system("cls");
    }while(op!=3);

    printf("Goodbye!\n");

    printf("Hecho por:\nXimena Rivera Delgadillo ID:261261\n");
    printf("José Luis Sandoval Perez ID: 261731\n");
    printf("Diego Emanuel Saucedo Ortega ID:261230\n");
    printf("Carlos Daniel Torres Macias ID:244543\n");
    system("pause");
return 0;
}

void insertarArticulo(char A[][20],int N[],int &articulos){
    printf("\nIngrese el nombre del articulo: ");
    scanf("%s",&A[articulos]);
    printf("Ingrese la cantidad a comprar: ");
    scanf("%d",&N[articulos]);
    printf("%d %s agregados.\n",N[articulos],A[articulos]);
    articulos++;
}

void quitarArticulo(char A[][20],int N[],int quitar,int &articulos){
    printf("Se elimino: %s\n",A[quitar-1]);
    while(quitar<articulos){
        memcpy(A[quitar-1],A[quitar],sizeof(A[quitar]));
        N[quitar-1]=N[quitar];
        quitar++;
    }
    articulos--;
}

