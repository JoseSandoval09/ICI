#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int op=0,i=0,j=0,k=0,a=0,b=0;
	int dis[j][k];
	int true=1;
	int false=0;
	int cont=0;
	int cases=0;
	
	


	printf("Este programa nos permitira mostrar tablas de verdad de una conjuncion y disyuncion\n");
	printf("Si decicides mostrar la tabla de verdad de la conjuncion se hara con 3 variables de entrada (p,q,r)\n");
	printf("En dado caso de seleccionar la tabla de verdad de la disyuncion solo sera con 2 variables de entrada (q,r)\n");
	
	printf("------MENU------n");
	printf("Seleccione una opcion\n");
	printf("1.TABLA DE VERDAD CONJUNCION\n");
	printf("2.TABLA DE VERDAD DISYUNCION\n");
	printf("OPCION: \n");
	scanf("%d", &op);
	
	switch(op){
		case 1:{
			
			printf("Decidiste seleccionar la tabla de verdad de la conjuncion, !Buena eleccion usuario!");
			printf("Aqui esta la tabla de verdad: \n");
			
			for(i=0;i<=1;i++){
				for(j=0;j<=1;j++){
					for(k=0;k<=1;k++){
						
					}
				}
			}
			
			
			
			
			break;
		}
		case 2:{
			
			a=0,b=0,j=3,k=4;
			int dis[j][k];
			
			
			
			printf("Decidiste seleccionar la tabla de verdad de la disyuncion, !Buena eleccion usuario!");
			printf("Aqui esta la tabla de verdad: \n");
			printf("p\tq\tp v q\n");
			
			printf("%d\t%d",false,false);
			if(false || false){
				printf("\n\t\t%d",false);
			}
			printf("\n%d\t%d",false,true);
			printf("\n%d\t%d",true,false);
			printf("\n%d\t%d",true,true);
			
			if(false || false){
				printf("\n\t\t");
			}
			
			
			
			
				
			
			
			
			break;
		}	
	}
	
	
	
	
	
}