//Jose Luis Sandoval Perez ICI 1A
//PRACTICA 5
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int op=0,p=0,q=0,r=0;
	int i=0,n=3,j=0,n2=7;

	
	
	do{
		
	printf("Este programa nos permitira mostrar la tabla de verdad de una conjuncion con 3 valores de entrada (p,q,r)");
	printf("\nAsi como nos permitira mostrar la tabla de verdad de una disyuncion con 2 valores de entrada (p,q)");
	
	printf("\nQue operacion deseas hacer\n"); 
	printf("1.- Tabla de verdad de conjuncion\n");
	printf("2.- Tabla de verdad de disyuncion\n");
	printf("3.- Salir\n");
	printf("Inserta opcion deseada:  ");
	scanf("%d", &op);
		
	int p=0,q=0,r=0;
	
	
	switch(op){ 
		case 1: { 
			printf("TABLA DE VERDAD COJUNCION\n");

		    
		    printf("p\tq\tr\tp^q\tp^q^r\n");
			for(i=0;i<n2+2;i++){ 
		    for(j=0;j<n2;j++) 
		    {       //columna 0 fila 0 
		        if (i==0 && j==0){
					printf("%d",p);
				}
		        //columna 0 fila 1
		        if (i==0 && j==1){
					printf("\t%d ",q);
				}
		         //columna 0 fila 2
		        if (i==0 && j==2){
					printf("\t%d ",r);
				}
		        //columna 0 fila 3
		        if (i==0 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 0 fila 4
		        if (i==0 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		        	     
		        //columna 1 fila 0 
		        if (i==1 && j==0){
					printf("%d ",p);
				}
		        //columna 1 fila 1
		        if (i==1 && j==1){
					printf("\t%d ",q);
				}
		        //columna 1 fila 2
		        if (i==1 && j==2){
					r++;
					printf("\t%d ",r);
				}
		        //columna 1 fila 3
		        if (i==1 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 1 fila 4
		        if (i==1 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		   	     
		        //columna 2 fila 0 
		        if (i==2 && j==0){
					printf("%d ",p);
				}
		        //columna 2 fila 1
		        if (i==2 && j==1){
				q++;
					printf("\t%d ",q);
				}
		        //columna 2 fila 2
		        if (i==2 && j==2){
					r--;
					printf("\t%d ",r);
				}
		        //columna 2 fila 3
		        if (i==2 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 2 fila 4
		        if (i==2 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		        	     
		        //columna 3 fila 0 
		        if (i==3 && j==0){
					printf("%d ",p);
				}
		        //columna 3 fila 1
		        if (i==3 && j==1){
					printf("\t%d ",q);
				}
		        //columna 3 fila 2
		        if (i==3 && j==2){
					r++;
					printf("\t%d ",r);
				}
		         //columna 3 fila 3
		        if (i==3 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 3 fila 4
		        
		    	if (i==3 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		        //columna 4 fila 0 
		        if (i==4 && j==0){
					p++;
					printf("%d ",p);
				}
		        //columna 4 fila 1
		        if (i==4 && j==1){
					q--;
					printf("\t%d ",q);
				}
		        //columna 4 fila 2
		        if (i==4 && j==2){
					r--;
					printf("\t%d ",r);
				}
		        //columna 4 fila 3
		        if (i==4 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 4 fila 4
		        
		        if (i==4 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		        //columna 5 fila 0 
		        if (i==5 && j==0){
					printf("%d ",p);
				}
		        //columna 5 fila 1
		        if (i==5 && j==1){
					q++;
					printf("\t%d ",q);
				}
		        //columna 5 fila 2
		        if (i==5 && j==2){
					printf("\t%d ",r);
				}
		        //columna 5 fila 3
		        if (i==5 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 5 fila 4
		        if (i==5 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
		        //columna 6 fila 0 
		        if (i==6 && j==0){
					printf("%d ",p);
				}
		        //columna 6 fila 1
		        if (i==6 && j==1){
					printf("\t%d ",q);
				}
		        //columna 6 fila 2
		        if (i==6 && j==2){
					r++;
					printf("\t%d ",r);
				}
		        //columna 6 fila 3
		        if (i==6 && j==3){
					printf("\t%d ",p&&q);
				}
		        //columna 6 fila 4
		        if (i==6 && j==4){
					printf("\t%d\n",p&&q&&r);
				}
			}
		    }
			printf("\n");
			break;
		}
		
		case 2:{ 
			printf(" TABLA DE VERDAD DISYUNCION\n");
		    
		    printf("p\tq\tpvq \n");
			for(i=0;i<n+1;i++){ //columnas
		      for(j=0;j<n;j++) //filas
		       {       //columna 0 fila 0 
		        	if (i==0 && j==0){
					 printf("%d ",p);
					}
		        	if (i==0 && j==1){
						printf("\t%d ",q);
					}
		        	if (i==0 && j==2){
						printf("\t%d\n",p||q);
					}
		        	if (i==1 && j==0){
						printf("%d ",p);
					}
		        	if (i==1 && j==1){
						q++;
						printf("\t%d ",q);
					}//columna 1 fila 2
		        	if (i==1 && j==2){
						printf("\t%d\n",p||q);
					}
					if (i==2 && j==0){
						p++;
						printf("%d",p);
					}
		        	//columna 2 fila 1
		        	if (i==2 && j==1){
						q--;
						printf("\t%d ",q);
					}
		        	//columna 2 fila 2
		        	if (i==2 && j==2){
						printf("\t%d\n",p||q);
					}
		    		//columna 3 fila 0
		        	if (i==3 && j==0){
						printf("%d ",p);
					}
		        	//columna 3 fila 1
		        	if (i==3 && j==1){
						q++;printf("\t%d ",q);
					}
		        	//columna 3 fila 2
		        	if (i==3 && j==2){
						printf("\t%d\n",p||q);
					}
		        }
				}
		    printf("\n");
			break;
		}
		case 3:{
			printf("Decidiste salir, gracias usuario\n");
			break;
		}
	    default:
	    	printf("Opcion invalida intentelo de nuevo\n");
	    break;
	}
	system("pause");
	system("cls");
}while(op!=3);

	printf("Espero y te haya gustado, vuelve pronto!");
}
	


