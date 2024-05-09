#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sumanum(); //Funcion sin valor, sin parametros.
void restanum(float num1, float num2); //Funcion sin valor, con parametros.
float multinum(float num1,float num2); //Funcion con valor, con parametros.
float divinum(); //Funcion con valor, sin parametros.

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
		scanf("%d", &op);    
		
		
		switch(op){
			case 1:{
					sumanum();
				break;
			}
			case 2:{
				
				float n1=0,n2=0;
				printf("Dame 2 numeros para restarlos\n");
				printf("Numero 1: ");
				scanf("%f", &n1);
				printf("\nNumero 2: ");
				restanum(n1,n2);
				
				break;
			}
			case 3:{
				
				float n1=0,n2=0,multiplicacion=0;
				printf("Dame 2 numeros para multiplicarlos\n");
				printf("Numero 1: ");
				scanf("%f", &n1);
				printf("\nNumero 2: ");
				scanf("%f", &n2);
				printf("El resultado de la multiplicacion es: %.2f", multinum(n1,n2));
				
				break;
			}
			case 4:{
				
				float res_div=0;
				res_div= divinum();
				printf("El resultado de la division es: %.2f ", res_div);
				 
				break;
			}
		}	
	} while (op!=7);
	
	
	//Funcion sin valor, sin parametros.
	
	void sumanum()
	{
		float num1=0,num2=0,suma=0;
		printf("Introduce 2 numeros para sumarlos\n");
		printf("Numero 1: ");
		scanf("%f", &num1);
		scanf("\nNumero 2: ");
		scanf("%f", &num2);
		suma=num1+num2;
		printf("\nLa suma de los numeros es: %.2f", suma);
	}
	
	//Funcion sin valor, con parametros.
	void restanum(float num1, float num2){

		float resta=0;
		resta= num1-num2;
		printf("El resultado de la resta es: %.2f", resta);
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
		printf("Dame 2 numeros y los dividire (n1/n2)");
		printf("Numero 1: ");
		scanf("%f", &n1);
		printf("Numero 2: ");
		scanf("%f", &n2);
		div= n1/n2;
		return(div);
	}
	
	
	
	
	
	
	
}
