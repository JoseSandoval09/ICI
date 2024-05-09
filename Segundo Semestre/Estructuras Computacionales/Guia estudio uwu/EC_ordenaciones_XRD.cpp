#include<iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include<fstream> //Libreria para los ficheros
using namespace std;

int main() {
	Menu_Intercalacion_De_Archivo();
	return 0;
}


class Intercalacion {
private:
	void abrir(fstream* f, string nom, int tip = 1);
	void cerrar(fstream* f);
public:
	void limpiar();
	bool hayDatos(char nom[]);
	void mostrar(char nom[]);
	void insertar(int d, char nom[]);
	void ordenar();
};
//-- Metodos para los ficheros --//
void Intercalacion::abrir(fstream* f, string nom, int tip) {
	if (tip == 1) //LECTURA
		(*f).open(nom, ios::in);//->
  //MODO TEXTO (Acceder a los datos) usaré ">>"
	else if (tip == 2) //ESCRITURA SIN BORRAR
		(*f).open(nom, ios::out | ios::app);	//->
  //MODO TEXTO (Colocar datos y no borrará) usaré "<<"
	else						//ESCRITURA y BORRAR
		(*f).open(nom, ios::out);	//->
  //MODO TEXTO (Colocar datos) usaré "<<"
}
void Intercalacion::cerrar(fstream* f) {
	(*f).close();
}
void Intercalacion::limpiar() {
	fstream F1, F2, F3;
	abrir(&F1, "F1.txt", 3);
	abrir(&F2, "F2.txt", 3);
	abrir(&F3, "F3.txt", 3);
	cerrar(&F1);
	cerrar(&F2);
	cerrar(&F3);
}
bool Intercalacion::hayDatos(char nom[]) {
	fstream F;
	abrir(&F, nom, 1);
	int x = -10001;
	F >> x;
	if (x != -10001)
		return true;
	else
		return false;
	cerrar(&F);
}

void Intercalacion::mostrar(char nom[]) {
	fstream F;
	abrir(&F, nom, 1);
	int dato;
	F >> dato;
	while (!F.eof()) {
		cout << dato << " ";
		F >> dato;
	}
	cerrar(&F);
}
void Intercalacion::insertar(int d, char nom[]) {
	fstream F;
	abrir(&F, nom, 2);
	F << d << " ";
	cerrar(&F);
}
//-- Metodo propio de Intercalación de Archivo --//
void Intercalacion::ordenar() {
	fstream F1, F2, F3;
	abrir(&F1, R"(F1.txt)", 1);
	abrir(&F2, R"(F2.txt)", 1);
	abrir(&F3, R"(F3.txt)", 3);

	int  r1, r2;
	F1 >> r1;
	F2 >> r2;
	//-- Escribir en orden cuando los dos tengan datos.
	while (!F1.eof() && !F2.eof())
		if (r1 < r2) {
			F3 << r1 << " ";
			F1 >> r1;
		}
		else {
			F3 << r2 << " ";
			F2 >> r2;
		}
	//-- Escribir lo sobrante.
	if (!F1.eof())
		while (!F1.eof()) {
			F3 << r1 << " ";
			F1 >> r1;
		}
	else if (!F2.eof())
		while (!F2.eof()) {
			F2 << r2 << " ";
			F2 >> r2;
		}
	cerrar(&F1);
	cerrar(&F2);
	cerrar(&F3);
}
void Menu_Intercalacion_De_Archivo() {
	Intercalacion A;
	char* z[1];
	char* principal[5]= { "MENU METODO DE INTERCALACION DE ARCHIVO : ","INGRESAR DATOS A UN FICHERO.", "ORDENAR LOS DATOS.","MOSTRAR LOS DATOS DE UN FICHERO.","ATRAS"};
	char* a[4] = { "MENU METODO DE INTERCALACION DE ARCHIVO (INGRESAR):","INGRESAR UN NUMERO.","INGRESAR VARIOS NUMEROS.","ATRAS." };
	char* b[4] = { "MENU METODO DE INTERCALACION DE ARCHIVO: ","FICHERO 1.","FICHERO 2.","FICHERO 3." };

	int op1 = 1, op2, op3, N, dato, mayor1, mayor2;
	char nomFic[7];
	mayor1 = mayor2 = -1001;
	A.limpiar();
	do {
		op1 = construirMenu(principal, 5, op1 + 1);
		switch (op1) {
		case 1:
			op2 = 1;
			do {
				op2 = construirMenu(a, 4, op2 + 1);
				if (op2 != 3) {
					op3 = construirMenu(b, 3);
					if (op3 == 1)
						strcpy(nomFic, "F1.txt");
					else
						strcpy(nomFic, "F2.txt");
				}
				if (op2 == 1 || op2 == 2) { //UNO O VARIOS DATOS.
					N = 1;
					while (op2 == 2 && (N <= 1 || N >= 1000)) {
						z[0] = "Digite cuantos datos desea ingresar:";
						construirMenu(z, 1);
						cin >> N;
					}
					for (int i = 0; i < N; i++) {
						do {
							z[0] = "Digite un dato para colocarlo:";
							construirMenu(z, 1);
							cin >> dato;
							if (op3 == 1 && dato > mayor1)
								mayor1 = dato;
							else if (op3 == 2 && dato > mayor2)
								mayor2 = dato;
							else {
								z[0] = "El dato debe ser mayor.";
								construirMenu(z, 1);
								system("pause>>NULL");
								dato = -10001;
							}
						} while (dato < -10000 || dato>10000);
						A.insertar(dato, nomFic);
						z[0] = "Se ha colocado el dato.";
						construirMenu(z, 1);
						system("pause>>NULL");
					}
				}
			} while (op2 != 3);
			break;
		case 2:
			if (A.hayDatos("F1.txt") && A.hayDatos("F2.txt")) {//Si hay datos.
				z[0] = "Se ha ordenado los ficheros y se ha guardado en el fichero 3.";
				A.ordenar();
			}
			else if (!A.hayDatos("F1.txt"))
				z[0] = "El fichero 1 no se ha ingresado al menos un dato.";
			else
				z[0] = "El fichero 2 no se ha ingresado al menos un dato.";
			construirMenu(z, 1);
			system("pause>>NULL");
			break;
		case 3:
			op3 = construirMenu(b, 4);
			if (op3 == 1)
				strcpy(nomFic, "F1.txt");
			else if (op3 == 2)
				strcpy(nomFic, "F2.txt");
			else
				strcpy(nomFic, "F3.txt");
			if (A.hayDatos(nomFic)) {//Si hay datos.
				z[0] = "Los datos son: ";
				construirMenu(z, 1);
				A.mostrar(nomFic);
			}
			else {
				z[0] = "No hay datos en el fichero.";
				construirMenu(z, 1);
			}
			system("pause>>NULL");
			break;
		}
	} while (op1 != 4);
}
void limpiar() {
	system("cls");
	fflush(stdin);
	cin.clear();
}
void gotoxy(int x, int y) {
	COORD Cursor_Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor_Pos);
}
void texcolor(int x){
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}
int construirMenu(char* opciones[], int can, int seleccion = 2, int X = 15, int Y = 3) {
	bool ban = true;
	int i, lim, tecla, opc = seleccion;
	limpiar();
	do {
		//-- Buscar la frase más larga --//
		for (lim = i = 0; i < can && ban; i++) {
			if (strlen(opciones[i]) > lim)
				lim = strlen(opciones[i]);
		}
		for (i = Y; i <= (can + Y + 1) && ban; i++) {
			gotoxy(X, i);
			//-- Esquinas y lineas verticales del lado izquierdo. --//
			if (i == Y)					cout << "É";
			else if (i != can + Y + 1)	cout << "º";
			else							cout << "È";
			//-- Lineas horizontales y las opciones.--//
			if (i == Y || i == can + Y + 1) {
				for (int j = 0; j < lim + 6; j++) cout << "Í";
			}
			else {
				//-- Cambio de Color --//
				if (opc == i - Y)
					texcolor(4);
				//-- Las letras --//
				if (i - (Y + 1) == 0)
					gotoxy(X + 1 + (lim + 1 - strlen(opciones[i - (Y + 1)])) / 2, i); // Centrado
				else
					gotoxy(X + 1, i);
				cout << "   " << opciones[i - (Y + 1)];
				texcolor(7);
			}
			//-- Esquinas y lineas verticales del lado derecho. --//
			gotoxy(X + lim + 6 + 1, i);
			if (i == Y)					cout << "»";
			else if (i != can + Y + 1)	cout << "º";
			else							cout << "¼";
		}
		//-- Funciones de reconocer las teclas --//
		if (can == 1) {
			gotoxy(X, i);
			return 0;
		}
		else
			tecla = getch();
		if (tecla == 72) {
			if (opc != 2)//-- Flecha Arriba del teclado 
				opc--;
			else
				opc = can;
			ban = true;
		}
		else if (tecla == 80) {//-- Flecha Abajo del teclado
			if (opc != can)
				opc++;
			else
				opc = 2;
			ban = true;
		}
		else
			ban = false;
	} while (tecla != 13);
	return opc - 1;
}
