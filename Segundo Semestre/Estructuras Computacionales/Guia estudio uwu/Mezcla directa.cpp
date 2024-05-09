// UNIVERSIDAD AUTONOMA DE AGUASCALIENTES
// ESTRUCTURAS COMPUTACIONALES II
// PROYECTO FINAL 3ER PARCIAL
// INTEGRANTES: 

// Carlos Leonardo Cruz Ortiz ID: 261696
// Leslie Miroslava Benítez Marín ID: 183817
// César Eduardo Elias del Hoyo ID: 262045

// ACTIVIDA 4
// Método mezcla directa

// ! Aveces ocurre un problema que hace que de pasadas de mas y pone el numero 33554434 varias veces

#include <bits/stdc++.h>
using namespace std;

void Merge(int ,int );

int paso = 0;

bool Validator(){
    ifstream original;  // Archivo de entrada
    int fileSize = 0; // TamaÃ±o del archivo
    string line; // Linea del archivo

    original.open("data.txt", ios::in);

    while (!original.eof())
    {
        do{
            getline(original, line);
        }while(!original.eof() && line == ""); // Ignora lineas vacias

        if(line != "" && !original.eof()) // Si la linea no esta vacia
            fileSize++; // Aumenta el integral para saber el tamaÃ±o del archivo
    }

    int *array = new int[fileSize]; // Crea un arreglo de enteros para guardar los datos del archivo

    original.close();

    original.open("data.txt", ios::in);

    for (int i = 0; i < fileSize; i++) // pasamos los datos del archivo a un arreglo
    {
        original >> array[i];
    }

    original.close();

    for (int i = 0; i < fileSize; i++) // Evaluamos si estan ordenado usando el metodo de la burbuja
    {
        for (int j = i + 1; j <= fileSize; j++)
        {
            if(array[j] > array[i]) // Si ocurre un cambio en vez de hacer el cambio retornamos un false
            {
                return false; // Indicando que no esta ordenado
            }
        }
    }
    // Si esta ordenado retornamos un true
    return true;
}

void Separator(int swept, int bounch){
    ifstream original; // read
    ofstream F1, F2; // write
    string line; // line
    bool flag = false; // Flag para saber cual archivo llenar (F1 == false , F2 == true)
    original.open("data.txt", ios::in);
    F1.open("F1.txt", ios::out);
    F2.open("F2.txt", ios::out);

    bounch = bounch * 2; // Para saber la cantidad de cada paquetito que ira en F1 Y F2, multiplicamos por 2

    if(!original.fail())
    {
        while(!original.eof())
        {
            if(swept <= 1) // Si es la primera pasada significa que agarramos paquetitos de 1
            {
                getline(original, line);

                if(!flag) // Flag para poner uno y uno
                {
                    F1 << line << endl;
                    flag = true;
                }
                else
                {
                    F2 << line << endl;
                    flag = false;
                }
            }
            else // Si estamos en la pasada 2 o mayor utilizamos los paquetitos
            {
                for(int i = 0; i < bounch; i++) // Usamos un for para determinar los paquetitos
                {
                    
                    if(!flag)
                    {
                        getline(original, line);
                        F1 << line << endl;
                    }
                    else
                    {
                        getline(original, line);
                        F2 << line << endl;
                    }

                    if(i == bounch - 1) // Si el paquetito esta completo cambiamos el flag
                    {
                        /* Usamos un operador ternario para cambiar el flag
                            Es como un if pero mas corto
                            ? significa que si se cumple la condicion se ejecuta la primera parte
                            : significa que si no se cumple la condicion se ejecuta la segunda parte
                        */
                        flag ? flag = false : flag = true; 
                    }
                }
            }
        }
    }

    // Cerramos los archivos
    original.close();
    F1.close();
    F2.close();
    paso++; // Aumentamos el paso

    /*  Llamamos a la funcion para unir los archivos F1 Y F2
        Utilizamos el operador ternario para saber en que pasada estamos
        y asi luego saber como se va a evaluar los datos
    */  
    return Merge(swept, ((swept == 1) ? 1 : bounch));
}

void Merge(int swept, int bounch){
    ifstream F1, F2;
    ofstream result;
    string line; // Linea del archivo
    bool flag; // Flag para saber si el archivo original ya esta ordenado o no

    int x, y;// Datos del F1 y F2 respectivamente

    F1.open("F1.txt", ios::in);
    F2.open("F2.txt", ios::in);
    result.open("data.txt", ios::out);

    if(!F1.fail() && !F2.fail() && !result.fail())
    {
        if(swept <= 1) // Si estamos en la primera pasada
        {
            while(!F1.eof() && !F2.eof())
            {
                F1 >> x;
                F2 >> y;

                if(x > y && !F1.eof() && !F2.eof()) // Solo se evaluan dos numeros
                {
                    result << x << endl;
                    result << y << endl;
                }
                else if(x < y && !F1.eof() && !F2.eof())
                {
                    result << y << endl;
                    result << x << endl;
                }
                
            }
        }
        else // Si estamos en la pasada 2 o mayor utilizamos los paquetitos
        {
            F1 >> x; // Leemos el primer dato del F1
            F2 >> y; // Leemos el primer dato del F2

            do
            {
                int counter1, counter2; // Contadores para saber si nos acabamos los datos de cada paquetito de F1 Y F2

                counter1 = counter2 = bounch; // Asignamos la cantidad de paquetitos que tenemos a cada contador
                do{
                    if(x > y) // Se evalua
                    {
                        result << x << endl; // Se guarda en el archivo original

                        do{
                            getline(F1, line);
                        }while(line == "" && !F1.eof()); // Ignora los espacios en blanco
                        
                        if(!F1.eof()) // Si al evaluar espacios en blanco no nos acabamos el archivo, asginamos el dato
                            x = stoi(line);
                        else // Si al evaluar espacios en blanco no nos acabamos el archivo, salimos del do
                            break;

                        counter1--; // Decrementamos el contador al asignar un dato
                    }
                    else // Lo mismo que arriba pero con el F2
                    {
                        result << y << endl;

                        do{
                            getline(F2, line);
                        }while(line == "" && !F2.eof());
                        
                        if(!F2.eof())
                            y = stoi(line);
                        else
                            break;

                        counter2--;
                    }
                }while(counter1 > 0 && counter2 > 0); // Si nos acabamos un paquetito de F1 o F2, salimos del do

                if(counter1 > 0) // Si no acabamos con el paquetito de F1, lo pasamos directo
                {
                    while(counter1 > 0) // Evalua para saber si ya acabamos con el F1
                    {
                        result << x << endl;

                        do{
                            getline(F1, line);
                        }while(line == "" && !F1.eof()); // Ignora espacios en blanco
                        
                        if(!F1.eof())
                            x = stoi(line);
                        else
                            break;

                        counter1--;
                    }
                }
                else if(counter2 > 0) // Si no acabamos con el paquetito de F2, lo pasamos directo  
                {
                    while(counter2 > 0)
                    {
                        result << y << endl;

                        do{
                            getline(F2, line);
                        }while(line == "" && !F2.eof()); // Ignora espacios en blanco
                        
                        if(!F2.eof())
                            y = stoi(line);
                        else
                            break;

                        counter2--;
                    }
                }
            }while (!F1.eof() && !F2.eof()); // Si acabamos con los dos archivos, salimos del do
        }
    
        cout<<endl;

        /*  Lo mismo que hicimos para saber si acabamos con los paquetitos lo hacemos pero
            para saber si acabamos con los archivos F1 y F2, ya que si partimos a la mitad los datos, y al
            pasarlos a F1 y F2 no quedan con la misma cantidad de datos, eso sigifica que al final de un archivo me 
            faltaran datos del otro, por lo tanto tengo que pasar directo los datos sobrantes 
        */
        while(!F2.eof())
        {
            result << y << endl;
            do{
                getline(F2, line);
            }while(line == "" && !F2.eof());

            if(!F2.eof())
                y = stoi(line);
            else
                break;
        }

        while(!F1.eof())
        {
            result << x << endl;

            do{
                getline(F1, line);
            }while(line == "" && !F1.eof());
            
            if(!F1.eof())
                x = stoi(line);
            else
                break;
        }
    }

    // Cerramos los archivos
    F1.close();
    F2.close();
    result.close();

    flag = Validator(); // Evaluamos si ya esta ordenado el archivo original

    cout<<"paso: "<<paso<<endl; // Imprimimos el paso que se realizo
    cout<<"flag: "<<flag<<endl; // Imprimimos el flag

    if(!flag) // Si no esta ordenado, seguimos con la siguiente pasada
        return Separator(swept + 1, bounch);
    else // Si esta ordenado, terminamos
        return;
}

void Restart(){
    ifstream backup; // el backup de los datos
    ofstream original; // el archivo original

    backup.open("data copy.txt", ios::in);
    original.open("data.txt", ios::out);

    if(!backup.fail() && !original.fail()){
        
        while (!backup.eof()) // pasamos los datos del backup al original
        {
            int x; 
            backup >> x;
            original << x << endl;
        }
    }

    backup.close();
    original.close();

    Separator(1, 1);
}

int main(){

    Restart(); // para reiniciar los datos del arichivo princiapal

    //Separator(1, 1); // Iniciamos el algoritmo

    system("pause");
    return 0;
}
