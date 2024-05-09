/*
Universidad Autonoma De Aguascalientes
Ingeniería en Computacion Inteligencia
Estructuras Computacionales Avanzadas

Elías Del Hoyo Cesar Eduardo 262045
Rivera Delgadillo Ximena    261261
Sandoval Perez Jose Luis    261731

Profesor: Luis Fernando Gutierrez Marfileño

Crear un programa que ejecute el desarrollo de todos
los subconjuntos de un conjunto de n elementos.
*/

#include <iostream>
#include <string>
using namespace std;

string conversor(int c); //funcion string para convertir nuestros numeros enteros a binario

int main() {
	string binary; //string para el conteo en binario de los subconjuntos
	int const n = 6; //constante n=6 para que nos permita recorrer el string y realizar movimientos
	string word[] = { "r","e","z","a","g","o" }; //string de la palabra "REZAGO" conformada por 6 letras

	cout << "I N T R O D U C C I O N  del  p r o g r a m a" << endl;
	cout << "El siguiente programa nos permitira desarrollar todos los subconjuntos de un conjunto de N elementos." << endl;
	cout << "\tDonde en este caso seleccionamos un conjunto string de 6 elementos con R E Z A G O para con el desplegar" << endl;
	cout << "\tel conteo en binario y en la siguiente columna a la derecha todos los subconjuntos del conjunto." << endl;
	cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	system("cls");

	//ciclo for que vaya de 0 a 63 que es el numero max de subconjuntos
	cout << "D e s a r r o l l o   de   subconjuntos" << endl;
	for (int i = 0; i <= 63; i++) {
		binary = conversor(i); //igualamos nuestro string binario con la funcion conversor con la entrada de nuestro contador
		cout << binary << " - {"; //escribimos el valor el binario con la ayuda de nuestro string binario
		for (int i = 0; i < n; i++) { //abrimos un segundo ciclo for que recorra nuestro conjunto
			if (binary[i] == '1') { //abrimos un ciclo if que nos permita agregar comas en caso de que nuestro conjunto no este vacio
				cout << word[i] << ", "; //y escribir el acomodo de nuestro subjconjunto
			}
		}
		cout << "}\n"; //generamos un salto de linea y un cierre de corchetes para cerrar nuestros subconjuntos
	}
	cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	system("cls");

	//salida
	cout << "PROGRAMA REALIZADO POR:\n";
	cout << "Elías Del Hoyo Cesar Eduardo 262045\nRivera Delgadillo Ximena    261261\nSandoval Perez Jose Luis    261731\n";
	cout << "\n--------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	return 0;

}
//desarrollo de nuestra funcion conversor para convertir nuestro contador a entero
string conversor(int c) {
	string b; //llamamos a la funcion con b
	int binario[6]; //inicializamos un arreglo de 6 elementos
	for (int i = 0; i < 6; i++)//abrimos un primer ciclo for para recorrer el arreglo
	{
		binario[i] = c % 2;
		c /= 2;
	}
	for (int i = 5; i >= 0; i--) //abrimos un segundo ciclo for para recorrer el arreglo
	{
		b += binario[i] + '0';
	}
	return b;//regresamos b
}

