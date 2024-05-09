//JOSE LUIS SANDOVAL PEREZ 2A ICI
// TAREA APUNTADORES,MEMORIA DINAMICA Y VECTORES CON APUNTADORES.


#include<stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <new>

int main (){
    int* p;
    int i, j,cam;
    int row , mat[100][100];
    std::cout << "El programa que he decidido desarrollar consiste en crear una matriz de un tamano inicial rellena de 0\n";
    std::cout << "Para posteriormente con la ayuda de los apuntadores permitir que el usuario modifique el tamano de esta\n";
    std::cout << "Asi como permitir que elimine dicha matriz\n";
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    std::cout <<"\tF O R M A R  M A T R I Z  I N I C I A L\n";
    std::cout << "Ingresa el tamano que deseas que tenga la matriz original:\n";
    std::cin >> row;
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    if (row<=0){
    	std::cout << "ERROR...El valor ingresado no es valido\n";
    }else{
    	 mat[row][row];

    for (i = 0; i < row; i++) 
    {
        for(j = 0; j < row; j++) 
        {
            mat[i][j] = 0;
        }
    }

    std::cout << "M A T R I Z  O R I G I N A L\n";
   
    for (i = 0; i < row; i++) 
    {
        for(j = 0; j < row; j++) 
        {
            std::cout<< "\t "<<mat[i][j]<<" ";
        }
        std::cout <<"\t\n";
    }
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    std::cout <<"\tM E N U matriz\n";
    std::cout <<"Selecciona una opcion:\n";
    std::cout <<"1.Modificar matriz original\n";
    std::cout <<"2.Continuar con la matriz original\n";
    std::cout <<"3.Eliminar matriz original\n";
    std::cout <<"4.Salir\n";
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    std::cout <<"Ingresa una opcion:\n";
    std::cin >>cam;
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    system("cls");
    p=&row;
    if(cam==1){
    	std::cout <<"Ingresa el nuevo tamano de la matriz\n";
    	std::cin >>*p;
    	std::cout << "M A T R I Z  R E S U L T A N T E\n";
    	for (i = 0; i < *p; i++) {for(j = 0; j < *p; j++) {mat[i][j] = 0;}}
      for (i = 0; i < *p; i++) 
      {
        for(j = 0; j < *p; j++) 
        {
            std::cout<< "\t "<<mat[i][j]<<" ";
        }
        std::cout <<"\t\n";
      }
    }
    if(cam==2){
    	std::cout <<"OHHH...al parecer la matriz continua igual...\n\n";
    	std::cout <<"La M A T R I Z  O R I G I N A L es la siguiente\n";
    	for (i = 0; i < *p; i++) {for(j = 0; j < *p; j++) {mat[i][j] = 0;}}
      for (i = 0; i < *p; i++) 
      {
        for(j = 0; j < *p; j++) 
        {
            std::cout<< "\t "<<mat[i][j]<<" ";
        }
        std::cout <<"\t\n";
      }
    }
    if(cam==3){
    	std::cout <<".....borrando matriz\n";
    	printf("\t\t G R A C I A S \n");
      printf("---------------------------------------------------------------------------------------------------------------------------\n");
      printf("\nHecho por: Ximena Rivera Delgadillo\n");
      system("color 0B");
      delete[]mat;
    }
    if(cam!=1&&cam!=2&&cam!=3&&cam!=4){
    	std::cout <<"ERROR...El valor ingresado no es valido\n"; 
    }
    
}
    std::cout << "\n----------------------------------------------------------------------------------------------------------------------------------------------------\n";
    system("pause");
    system("cls");
}


    
