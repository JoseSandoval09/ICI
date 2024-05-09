//Jose Luis Sandoval Perez 1°A ICI
//Calculadora con funciones.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sumanum(); //Funcion sin valor, sin parametros.
void restanum(float num1, float num2); //Funcion sin valor, con parametros.
float multinum(float num1,float num2); //Funcion con valor, con parametros.
float divinum(); //Funcion con valor, sin parametros.
void potencianum(float num, int pot); //Funcion sin valor, sin parametros.
void factnum(); //Funcion sin valor, sin parametros

int op=0;


int main(){
	

	 
	do{
		
		
		printf("Este programa simulara una calculadora basica, haciendo las operaciones con 2 numeros\n");
		printf("Seleccione la opcion deseada");
		printf("\n1. SUMA");
		printf("\n2. RESTA");
		printf("\n3. MULTIPLICACION");
		printf("\n4. DIVISION");
		printf("\n5. POTENCIA");
		printf("\n6. FACTORIAL");
		printf("\n7. SALIR");
		printf("\nQue opcion eliges? : ");
		scanf("\n%d", &op);    
		
		
		switch(op){
			case 1:{
				
				system("color D");	
					
				system("cls");
				sumanum();
				printf("\n");
				system("pause");
				system("cls");
					
				continue;
			}
			case 2:{
				
				system("cls");
				
				system("color B");	
				
				float n1=0,n2=0;
				printf("Dame 2 numeros para restarlos\n");
				printf("Numero 1: ");
				scanf("%f", &n1);
				printf("Numero 2: ");
				scanf("%f", &n2);
				restanum(n1,n2);
				printf("\n");
				
				system("pause");
				system("cls");
				
				continue;
			}
			case 3:{
				
				system("cls");
				
				system("color C");	
				
				float n1=0,n2=0,multiplicacion=0;
				printf("Dame 2 numeros para multiplicarlos\n");
				printf("Numero 1: ");
				scanf("%f", &n1);
				printf("Numero 2: ");
				scanf("%f", &n2);
				printf("El resultado de la multiplicacion es: %.1f", multinum(n1,n2));
				
				printf("\n");
				system("pause");
				system("cls");
				
				continue; 
			}
			case 4:{
				
				system("cls");
				
				system("color A");	
				
				float res_div=0;
				res_div= divinum();
				printf("El resultado de la division es: %.1f ", res_div);
				
				printf("\n");
				system("pause");
				system("cls");
				
				continue;
			}
			case 5:{
				
				system("cls");
				
				system("color E");	
				
				float n=0,p=0;
				printf("Dame 1 numero y lo elevare a la potencia deseada\n");
				printf("Numero : ");
				scanf("%f", &n);
				printf("Potencia: ");
				scanf("%f", &p);
				potencianum(n,p);
				printf("\n");
				
				system("pause");
				system("cls");
				
				
				continue;	
			}
			case 6:{
				
				system("cls");
				factnum();
				printf("\n");
				system("pause");
				system("cls");
				
				continue;
			}
			case 7:{
				
				printf("Decidiste salir usuario, vuelve pronto!");
				
				break;
			}
			default:
			printf("Opcion incorrecta, intente de nuevo\n");
			system("pause");
			system("cls");
			break;
		}
	}while (op!=7);
	
	
	
	
}

//Funcion sin valor, sin parametros.
	
	void sumanum(){
		float num1=0,num2=0,suma=0;
		printf("Introduce 2 numeros para sumarlos\n");
		printf("Numero 1: ");
		scanf("%f", &num1);
		printf("Numero 2: ");
		scanf("%f", &num2);
		suma= num1+num2;
		printf("La suma de los 2 numeros es: %.1f", suma);
	}
	
	//Funcion sin valor, con parametros.
	void restanum(float num1, float num2){

		float resta=0;
		resta= num1-num2;
		printf("El resultado de la resta es: %.1f", resta);
	}
	
	//Funcion con valor, con parametros.
	float multinum(float num1, float num2){
	
		float multi=0;
		multi= num1*num2;
		return(multi);
	}
	
	//Funcion con valor, sin parametros.
	float divinum()
	{
		float n1=0,n2=0,div=0;
		printf("Dame 2 numeros y los dividire (n1/n2)\n");
		printf("Numero 1: ");
		scanf("%f", &n1);
		printf("Numero 2: ");
		scanf("%1f", &n2);
		div= n1/n2;
		return(div);
	}
	
	//Funcion sin valor, sin parametros.
	void potencianum(float num,int pot){
		
		float resultado=0;
		resultado= pow(num,pot);
		printf("El resultado de elevar %.1f a la potencia %d es: %.1f ",num,pot,resultado);
	}
	
	//Funcion sin valor, sin parametros
	void factnum(){
		
		int n=0,i=0,fact=1;
		
		printf("Ingresa un numero y te dire su factorial\n");
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			fact=fact*i;
		}
		printf("El resultado del factorial es: %d\n", fact);
	}
