#include <iostream>

#include <Windows.h>

#include <string>





//Recupera un identificador del dispositivo estándar especificado (entrada estándar, salida estándar o error estándar).

//El dispositivo de salida estándar. Inicialmente, este es el búfer de pantalla de la consola activa.

#define STD_OUTPUT_HANDLE ((DWORD)-11)



using namespace std;



//Función gotoxy para coordenadas de posición.

void gotoxy(int x, int y) {

	HANDLE hCon;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;

	dwPos.X = x;

	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);

}



//Estructura de datos con vectores.

struct empleado {

	string nombre[3];

	int edad;

	float sueldo[5];

}empleados[50];



//Prototipos de Funciones.

void dia(int i);

float sueldos(float v[50], int i);

void captura(struct empleado, int emp);



//Función Principal.

int main()

{

	//Declaración de variables.

	string op = "", imprimir = "";

	int emp = 0, y = 7;

	float totalsueldo[50] = { 0 };



	//Ciclo do while para ingresar empleados.

	do {



		//Limpieza de pantalla.

		system("cls");



		//Llamada a la función para captura de datos.

		captura(empleados[emp], emp);



		//Impresión de datos de empleados.

		gotoxy(8, 21);

		cout << "IMPRIMIR BASE DE DATOS : ";

		cin >> imprimir;

		if (imprimir == "SI" || imprimir == "si")

		{

			system("cls");

			gotoxy(30, 0);

			cout << "EMPLEADOS";

			gotoxy(0, 1); cout << "**********************************************************************";

			gotoxy(5, 2); cout << "NOMBRE";

			gotoxy(40, 2); cout << "EDAD";

			gotoxy(50, 2); cout << "SUELDO NETO";

			gotoxy(0, 3); cout << "----------------------------------------------------------------------";



			for (int i = 0; i <= emp; i++)

			{

				gotoxy(5, i + 4);

				cout << empleados[i].nombre[0] + " " + empleados[i].nombre[1] + " " + empleados[i].nombre[2];

				gotoxy(41, i + 4);

				cout << empleados[i].edad;

				gotoxy(54, i + 4);



				//Llamada a la función sueldos para suma de sueldo neto.

				sueldos(totalsueldo, i);

				cout << totalsueldo[i];

				y++;

			}

			gotoxy(21, y);

			cout << "DESEA CAPTURAR OTRO EMPLEADO ? ";

			cin >> op;



			//Se utiliza cuando se lee un string enseguida de un int, ignora el enter en la linea.

			cin.ignore();

		}

		else

		{

			system("CLS");

			gotoxy(21, y);

			cout << "DESEA CAPTURAR OTRO EMPLEADO ? ";

			cin >> op;

			cin.ignore();

		}

		emp++;



	} while (op == "SI" || op == "si" && emp < 50);

	cout << endl << endl;

}



//Funcion sin retorno para el día de la semana.

void dia(int i)

{

	switch (i + 1)

	{

	case 1: cout << "Lunes"; break;

	case 2: cout << "Martes"; break;

	case 3: cout << "Miercoles"; break;

	case 4: cout << "Jueves"; break;

	case 5: cout << "Viernes"; break;

	}

}



//Función sin retorno para capturar datos en estructura.

void captura(struct empleado, int emp)

{

	gotoxy(8, 0);

	cout << "SISTEMA DE EMPLEADOS";

	//Captura de Nombre(s), Apellido Paterno y Apellido Materno.

	for (int i = 0; i < 3; i++)

	{

		if (i == 0)

		{

			cout << "\n\n Ingrese su Nombre : ";

			getline(cin, empleados[emp].nombre[0]);

		}

		else if (i == 1)

		{

			cout << "\n Ingrese su Apellido Paterno : ";

			getline(cin, empleados[emp].nombre[1]);

		}

		else

		{

			cout << "\n Ingrese su Apellido Materno : ";

			getline(cin, empleados[emp].nombre[2]);

		}

	}



	//Captura de Edad.

	cout << "\n Ingrese su edad : ";

	cin >> empleados[emp].edad;



	//Captura de sueldo (Lunes a Viernes).

	for (int i = 0; i < 5; i++)

	{

		cout << "\n Ingrese su sueldo del dia "; dia(i); cout << " : ";

		cin >> empleados[emp].sueldo[i];

	}

}



//Función para suma de sueldos (Lunes a Viernes).

float sueldos(float v[50], int i)

{

	for (int j = 0; j < 5; j++)

	{

		v[i] = v[i] + empleados[i].sueldo[j];

	}

	return v[i];

}

