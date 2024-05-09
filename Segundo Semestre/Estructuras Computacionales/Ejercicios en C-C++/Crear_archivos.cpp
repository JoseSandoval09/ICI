
#include <iostream>

#include <stdlib.h>

#include <fstream>  //Libreria especifica para archivos

using namespace std;



//Funcion para escribir en un blog de notas

//Forma sencilla

void escribir() {

    ofstream archivo;

    string nombreArchivo, frase;



    cout << "Digite el nombre del archivo (termine con .txt): ";

    getline(cin, nombreArchivo);



    archivo.open(nombreArchivo.c_str(), ios::out); // ios::out si existe el archivo lo remplaza o si no existe lo crea



    if (archivo.fail()) {   //.fail() fallo, manda un true o false, true = existe un error

        cout << "No se pudo abrir el archivo";

        exit(1); // sirve para salir del programa en caso de falla

    }

    cout << endl << "Digite el texto del archivo: ";

    getline(cin, frase);

    archivo << frase;   // tiene la misma funcion que cout y el cin

    archivo.close(); //cerrar el archivo

}



int main()

{

    escribir();



    system("pause");

    return 0;

}