#include<iostream>
#include<fstream>

using namespace std;

string linea_s;
string texto;

int main(){

    //mostrar lo que hay dentro del archivo
    ifstream archivo("documento.txt");
    while(getline(archivo.linea)){
        texto+= linea_s + "\n";
    }
    //cerrar archivo
    archivo.close();
    cout<<texto<<endl;


    //agregar texto a archivo ya creado o crear archivo
    ofstream archivo2("documento.txt");
    archivo2 << texto << "nueva linea de texto";
    system("pause");
    return 0; 

    

}