/* PRACTICA 4
JOSE LUIS SANDOVAL PEREZ 1°A
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ord,i,j;
	int GradMax=0,GradV;
	const int tam=10;
	int matriz[tam][tam];

printf("A continuacion imprimire la matriz de adyancencia de un grafo cualquiera\nsolo sabiendo si existe adyancencia entre sus vertices");
    printf("\nDame el orden del grafo (<=10): ");
    scanf("%d", &ord);

    for (i=1; i<=ord; i++){
        for (j=1; j<=ord; j++)    
            matriz[i][j] = 0;
	}
    for (i=1; i<=ord; i++)
    {
        for (j=1; j<=ord; j++)
        {
            if (j <= i)
            {
                continue;
            }
            else
            {
                printf("Existe adyacencia entre Vertice(%d) y Vertice(%d)\n[SI=1,N0=0]: ", i,j);
                scanf("%d", &matriz[i][j]);
                matriz[j][i] = matriz[i][j];
            }
        }
    }
    
    printf("\nLa matriz es: \n");
    for (i=1; i<=ord; i++)
    {
        for (j=1; j<=ord; j++)
        {
            printf("%d   ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i=1; i<=ord; i++)
    {
        GradV = 0;
        for (j=1; j<=ord; j++)
        {
            GradV = GradV + matriz[i][j];
        }
        printf("El grado del vertice %d es: %d\n", i,GradV);
        if (GradMax < GradV)
        {
            GradMax = GradV;
        }
    }
    printf("El grado maximo del grafo es: %d\n", GradMax);
}

