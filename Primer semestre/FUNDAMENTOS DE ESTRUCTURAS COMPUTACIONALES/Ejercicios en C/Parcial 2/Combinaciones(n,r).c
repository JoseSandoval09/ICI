#include<stdio.h>
//El siguiente programa mostrara las combinaciones de "n,2", 
//en donde n es un numero dado por el usuario, diciendo cuantas son en total.

//Sandoval Perez Jose Luis 1° A ICI

int main(){

    int n,i=0,j=0,c=0,d=0;

    printf("Este programa muentras las combinaciones de (n,2), \n en donde n es el numero que introduciras a continuacion\n");
    printf("Introduce n:\n");
    scanf("%d", &n);
    while (i<n){
        i++;
        j=i+1;
        while (j<n){
            c++;
            printf("%d,%d,d& \n", i,j,d);
            j++;
        }
    }
    printf("Son %d combinaciones en total",c);
return 0;

}

