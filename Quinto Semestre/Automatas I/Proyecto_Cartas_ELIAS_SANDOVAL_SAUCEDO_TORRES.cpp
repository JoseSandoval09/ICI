#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define N_ESTADOS_NDFA 8
#define N_ESTADOS_NDPDA 5
#define N_PARRAFOS_EJEMPLO 5

struct Nodo{
    int num;
    vector<int>transicion;
};

Nodo ndfa[N_ESTADOS_NDFA];
Nodo ndpda[N_ESTADOS_NDPDA];


string SALUDO[N_PARRAFOS_EJEMPLO] = {
    "Hola, �Como vas? ",
    "Querido/a [Nombre],",
    "Un saludo, [Nombre] ",
    "Buenas tardes, estimado [Nombre]",
    "Me dirijo a usted [Nombre],"};

string FELICIDAD[N_PARRAFOS_EJEMPLO] = {
    "Estoy muy contento de verte despues de tanto tiempo. Me has hecho mucha falta y me alegra saber que estas bien.",
    "Me encanta tu sonrisa y tu forma de ser. Eres una persona muy especial para mi y te quiero mucho.",
    "Eres la mejor compania que puedo tener, y cada paso que damos juntos es una aventura.",
    "Cada vez que leo tus mensajes, siento una alegria enorme. Espero que tu tambien te sientas asi cuando recibes los mios.",
    "Eres una persona muy divertida y original, siempre tienes algo ingenioso que decir. Me encanta pasar tiempo contigo y compartir nuestras bromas."};

string ROMANTICO[N_PARRAFOS_EJEMPLO] = {
    "Te quiero con todo mi corazon, eres la razon de mi existir. Cada dia me enamoro mas de ti, de tu sonrisa, de tu voz, de tu mirada.",
    "Quiero estar a tu lado siempre, abrazarte, besarte, hacerte feliz. Eres mi sue�o hecho realidad, mi alma gemela, mi complemento perfecto.",
    "Me gusta ver como el sol se refleja en tus ojos y como tu sonrisa ilumina tu rostro. Me siento feliz de tenerte a mi lado. ",
    "Me gusta crear un vinculo especial con alguien a traves de las letras, que traspasan el tiempo y el espacio.",
    "Me gusta imaginar la cara de la persona que recibe mi carta, su sonrisa, su emocion, su sorpresa."};

string ENOJO[N_PARRAFOS_EJEMPLO] = {
    "Usted me ha faltado el respeto, me ha mentido y me ha hecho perder el tiempo. No puedo tolerar mis su actitud irresponsable y desconsiderada.",
    "Estoy muy molesto contigo por no responder a mis mensajes. �Que te pasa? �No te importa lo que siento? Me parece una falta de respeto y de \nconsideracion que me ignores asi.",
    "No me parece justo que me dejes plantado/a cada vez que quedamos. Me siento como un/a payaso/a esperando tu llamada o tu mensaje.",
    "Voy a tomar medidas drasticas. Y no me refiero a cortarte el pelo mientras duermes, aunque podria hacerlo",
    "Espero que te sientas orgulloso de tu vida sucia. No quiero volver a estar contigo nunca mas..."};

string TRISTEZA[N_PARRAFOS_EJEMPLO] = {
    "No se que paso, pero algo se rompio entre nosotros. Tal vez fue la distancia, o tal vez fue el tiempo. Lo unico que se es que ya no soy feliz \na tu lado, y creo que tu tampoco lo eres conmigo. ",
    "Tu sabes que yo casi no hangeo ,pero ahora salgo todos los dias para ver si te veo. Aunque sea de lejitos. ",
    "Tantos consejos que yo te he dado y  parece que en mi ya no funcionan",
    "Son mis chistes los que ya no te dan gracia, no soy la razon de tu sonrisa. Donde fue esa mirada? Que con verme todo me decia. ",
    "Yo te juro que no me imaginaba como se sentia ni como seria un verano sin ti."};

string DESPEDIDA[N_PARRAFOS_EJEMPLO] = {
    "Me despido, cordialmente. ",
    "Nos veremos pronto, muy pronto. ",
    "Adios.",
    "Nos vemos despues.",
    "Que tengas un buen dia, ciao."};

void generarEjemplo(string cadena){
    if(cadena.size()>6){ cout<<"\n\tLa carta es muy larga para generar un ejemplo."<<endl; return; }

    cout<<"\n\tEjemplo de carta generada\n"<<endl;

    bool utilizado[4][N_PARRAFOS_EJEMPLO];
    for(int i=0;i<4;i++){
        for(int j=0;j<N_PARRAFOS_EJEMPLO;j++){
            utilizado[i][j]= false;
        }//fin for j
    }//fin for establecer a false

    for(auto x:cadena){
        int opcion = rand()%N_PARRAFOS_EJEMPLO;
        if(x=='a'){ cout<<"\n\t"<<SALUDO[opcion]<<endl<<"\n"; }
        if(x=='f'){
            while(utilizado[0][opcion]==true){ opcion = rand()%N_PARRAFOS_EJEMPLO; }
            utilizado[0][opcion] = true;
            cout<<"\t"<<FELICIDAD[opcion]<<endl;
        }//fin if parrafo felicidad
        if(x=='r'){
            while(utilizado[1][opcion]==true){ opcion = rand()%N_PARRAFOS_EJEMPLO; }
            utilizado[1][opcion] = true;
            cout<<"\t"<<ROMANTICO[opcion]<<endl;
        }//fin if parrafo romantico
        if(x=='e'){
            while(utilizado[2][opcion]==true){ opcion = rand()%N_PARRAFOS_EJEMPLO; }
            utilizado[2][opcion] = true;
            cout<<"\t"<<ENOJO[opcion]<<endl;
        }//fin if parrafo enojo
        if(x=='t'){
            while(utilizado[3][opcion]==true){ opcion = rand()%N_PARRAFOS_EJEMPLO; }
            utilizado[3][opcion] = true;
            cout<<"\t"<<TRISTEZA[opcion]<<endl;
        }//din if parrafo triste
        if(x=='b'){ cout<<"\n\t"<<DESPEDIDA[opcion]<<endl; }
    }//fin for cadena
}

void construirNDPDA(Nodo ndpda[]){
    //q0
    ndpda[0].num = 0;
    ndpda[0].transicion.PB(1);

    //q1
    ndpda[1].num = 1;
    ndpda[1].transicion.PB(2);
    ndpda[1].transicion.PB(3);

    //q2
    ndpda[2].num = 2;
    ndpda[2].transicion.PB(2);
    ndpda[2].transicion.PB(3);
    ndpda[2].transicion.PB(4);

    //q3
    ndpda[3].num = 3;
    ndpda[3].transicion.PB(2);
    ndpda[3].transicion.PB(3);
}

void construirNDFA(Nodo ndfa[]){
    //q0
    ndfa[0].num = 0;
    ndfa[0].transicion.PB(1);
    //q1
    ndfa[1].num = 1;
    ndfa[1].transicion.PB(2);
    ndfa[1].transicion.PB(3);
    ndfa[1].transicion.PB(5);
    //q2
    ndfa[2].num = 2;
    ndfa[2].transicion.PB(2);
    ndfa[2].transicion.PB(6);
    ndfa[2].transicion.PB(7);
    //q3
    ndfa[3].num = 3;
    ndfa[3].transicion.PB(3);
    ndfa[3].transicion.PB(4);
    ndfa[3].transicion.PB(7);
    //q4
    ndfa[4].num = 4;
    ndfa[4].transicion.PB(3);
    ndfa[4].transicion.PB(4);
    ndfa[4].transicion.PB(7);
    //q5
    ndfa[5].num = 5;
    ndfa[5].transicion.PB(5);
    ndfa[5].transicion.PB(7);
    //q6
    ndfa[6].num = 6;
    ndfa[6].transicion.PB(6);
    ndfa[6].transicion.PB(7);
}

bool verificarCarta(string cadena){
    int nodo_actual = 0;
    string tipo_carta = "Carta rechazada";
    for(auto x:cadena){
        //q0
        bool hay_transicion = false;
        if(x=='a' && nodo_actual==0){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q0,a,q1

        //q1
        if(x=='f' && nodo_actual==1){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q1,f,q2
        if(x=='e' && nodo_actual==1){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
            tipo_carta = "enojo";
        }//fin transicion q1,e,q3
        if((x=='r' || x=='f') && nodo_actual==1){
            nodo_actual = ndfa[nodo_actual].transicion[2];
            hay_transicion = true;
        }//fin transicion q1,r,q5 - q1,f,q5

        //q2 felicidad
        if(x=='f' && nodo_actual==2){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q2,f,q2
        if((x=='t' || x=='r') && nodo_actual==2){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
        }//fin transicion q2,t,q6 - q2,r,q6
        if(x=='b' && nodo_actual==2){
            nodo_actual = ndfa[nodo_actual].transicion[2];
            hay_transicion = true;
            tipo_carta = "felicidad";
        }//fin transicion q2,b,q7

        //q3 enojo
        if(x=='e' && nodo_actual==3){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
            tipo_carta = "enojo";
        }//fin transicion q3,e,q3
        if(x=='t'&& nodo_actual==3){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
        }//fin transicion q3,t,q4
        if(x=='b' && nodo_actual==3){
            nodo_actual = ndfa[nodo_actual].transicion[2];
            hay_transicion = true;
        }//fin transicion q3,b,q7

        //q4 decepcion
        if(x=='e' && nodo_actual==4){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q4,e,q3
        if(x=='t'&& nodo_actual==4){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
        }//fin transicion q4,t,q4
        if(x=='b' && nodo_actual==4){
            nodo_actual = ndfa[nodo_actual].transicion[2];
            hay_transicion = true;
            tipo_carta = "decepcion";
        }//fin transicion q4,b,q7

        //q5 romantico
        if((x=='r' || x=='f') && nodo_actual==5){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q5,r,q5 - q5,f,q5
        if(x=='b'&& nodo_actual==5){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
            tipo_carta = "romantico";
        }//fin transicion q5,b,q7

        //q6 anoranza
        if((x=='r' || x=='t') && nodo_actual==6){
            nodo_actual = ndfa[nodo_actual].transicion[0];
            hay_transicion = true;
        }//fin transicion q5,r,q5 - q5,f,q5
        if(x=='b'&& nodo_actual==6){
            nodo_actual = ndfa[nodo_actual].transicion[1];
            hay_transicion = true;
            tipo_carta = "anoranza";
        }//fin transicion q5,b,q7

        if(hay_transicion==false){
            cout<<"\n\tLa estructura de la carta fue rechazada.\n";
            return false;
        }//no hubo transicion posible, se rechaza

    }//fin for cadena

    if(nodo_actual==7 || nodo_actual==3){
        cout<<"\n\t   La estructura de la carta fue aceptada.";
        cout<<"\n\t   El tipo de carta es: "<<tipo_carta<<endl;
        return true;
    }//if termina en estado final [q3,q7]

    cout<<"\n\t   La estructura de la carta fue rechazada.\n";
    return false;
}

void estructura(){
	cout<<" ESTRUCTURA PARA LAS CARTAS: \n";
	cout<<" \n ----------------------------------------- \n";
	cout<<" LENGUAJE ACEPTADO PARA LA CREACION DE CARTAS \n L={aff^n ub, aevb, arwb :n>=0,u={t,r}*,u>=|0|, v={e,t}*, v>=|0|, w={r,f}*, w>=|0|}\n\n";
	cout<<" LENGUAJE ACEPTADO PARA LA VALIDACION DE CARTAS \n L={awb : w={e,f,t,r}*, (n_f (w)+n_r (w))>0(n_e (w)+ n_t (w))}\n\n";
	cout<<" Toda carta debe contener la estructura awb, donde a es un saludo y b una despedida\n";
	cout<<" w se conforma de lo siguiente: ";
	cout<<" \n\t f -> felicidad\n\t e -> enojo \n\t r -> romantico \n\t t -> tristeza";
	cout<<" \n ----------------------------------------- \n";
}

void validarAnimo(string cadena){

    stack<char>pila;
    pila.push('z');

    int estado_actual = 0;
    int i = 0;

    //si el siguiente caracter ya es el ultimo
    //que tome la tranisicion lambda
    bool transicion_lambda = false;


    while(i<cadena.size()){

        if(i==cadena.size()-1){ transicion_lambda = true; }

        bool hay_transicion = false;
        char x = cadena[i];
        //cout<<estado_actual<<" "<<x<<" "<<pila.top()<<endl;
        //q0
        if(x=='a' && pila.top()=='z' && estado_actual==0){
            estado_actual = ndpda[estado_actual].transicion[0];
            pila.pop();
            pila.push('z');
            hay_transicion = true;
        }//q0,a,z,z,q1

        //q1
        else if(estado_actual==1){
            if((x=='r' || x=='f') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('z');
                pila.push('1');
                hay_transicion = true;
            }//q1,r,z,1z,q2 - q1,f,1z,q2

            else if((x=='e' || x=='t') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                pila.push('z');
                pila.push('2');
                hay_transicion = true;
            }//q1,e,z,2z,q3 - q1,t,z,2z,q3
        }//transiciones q1

        //q2
        else if(estado_actual==2){
            //se mantiene en q2
            if((x=='r' || x=='f') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('z');
                pila.push('1');
                hay_transicion = true;
            }//q2,r,z,1z,q2 - q2,f,z,1z,q2

            else if((x=='r' || x=='f') && pila.top()=='2'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                hay_transicion = true;
            }//q2,r,z,*,q2 - q2,f,z,*,q2

            else if((x=='r' || x=='f') && pila.top()=='1'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('1');
                pila.push('1');
                hay_transicion = true;
            }//q2,r,1,11,q2 - q2,f,z,11,q2

            //transiciona a q3
            else if((x=='e' || x=='t') && pila.top()=='1'){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                hay_transicion = true;
            }//q2,e,1,*,q3 - q2,t,1,*,q3

            else if((x=='e' || x=='t') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                pila.push('z');
                pila.push('2');
                hay_transicion = true;
            }//q2,e,z,2z,q3 - q2,t,z,2z,q3

            else if(x=='b' && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[2];
                pila.pop();
                pila.push('z');
                hay_transicion = true;
            }//q2,b,z,lambda,q4

            else if(x=='b' && pila.top()=='1'){
                estado_actual = ndpda[estado_actual].transicion[2];
                pila.pop();
                pila.push('1');
                hay_transicion = true;
            }//q2,b,1,lambda,q4

        }//transiciones q2


        //q3
        else if(estado_actual==3){
            //transicionan a q2
            if((x=='f' || x=='r') && pila.top()=='2'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                hay_transicion = true;
            }//q3,r,2,lambda,q2 - q3,f,2,lambda,q2

            else if((x=='f' || x=='r') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('z');
                pila.push('1');
                hay_transicion = true;
            }//q3,r,z,1z,q2 - q3,f,z,1z,q2

            else if(pila.top()=='z' && transicion_lambda==true){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('z');
                hay_transicion = true;
                //cout<<"transicion lambda z"<<endl;
                i--;
            }//q3,lambda,1,lambda,q2

            else if(pila.top()=='1' && transicion_lambda==true){
                estado_actual = ndpda[estado_actual].transicion[0];
                pila.pop();
                pila.push('1');
                hay_transicion = true;
                //cout<<"transicion lambda 1"<<endl;
                i--;
            }//q3,lambda,1,lambda,q2

            //se mantiene en q3

            else if((x=='e' || x=='t') && pila.top()=='z'){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                pila.push('z');
                pila.push('2');
                hay_transicion = true;
            }//q3,e,z,2z,q3 - q3,t,z,2z,q3

            else if((x=='e' || x=='t') && pila.top()=='2'){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                pila.push('2');
                pila.push('2');
                hay_transicion = true;
            }//q3,e,2,22,q3 - q3,t,z,22,q3

            else if((x=='e' || x=='t') && pila.top()=='1' && transicion_lambda==false){
                estado_actual = ndpda[estado_actual].transicion[1];
                pila.pop();
                hay_transicion = true;
            }//q3,e,1,lambda,q3 - q3,t,1,lambda,q3

        }//transiciones q3
        i++;
    }//fin while cadena


    if(estado_actual == 4 && !pila.empty()){

        if(pila.top()=='1'){ cout<<"\n\t   La carta tiene un animo mayormente positivo.\n"; }
        else{ cout<<"\n\t   La carta tiene un animo neutro.\n"; }

        //vaciar pila
        while(!pila.empty()){ pila.pop(); }
        return;
    }//fin if es aceptada

    //vaciar pila
    while(!pila.empty()){ pila.pop(); }
    cout<<"\n\t   La carta tiene un animo mayormente negativo.\n"; return;
}


void generarCarta(int tipo){
    string estructura = "a";
    int nodo_actual = 1;
    int num_parrafos;

    //carta de felicidad
    if(tipo==1){
        do{
            cout<<"\n\tIngrese numero de parrafos de la carta--->"; cin>>num_parrafos;
            if(num_parrafos<3){ cout<<"\n\tEl numero de parrafos debe ser minimo de 3"; }
        }while(num_parrafos<3);
        //limita el numero de parrafos
        num_parrafos--;

        do{
            estructura.PB('f');
            num_parrafos--;
        }while(num_parrafos>1);

        estructura.PB('b');
        num_parrafos--;

    }//fin carta felicidad

    //carta de anoranza
    if(tipo==2){
        do{
            cout<<"\n\tIngrese numero de parrafos de la carta--->"; cin>>num_parrafos;
            if(num_parrafos<4){ cout<<"\n\tEl numero de parrafos debe ser minimo de 4"; }
        }while(num_parrafos<4);
        //limita el numero de parrafos
        num_parrafos--;

        int lim_parrafos = 1 + rand()%(num_parrafos-2);
        num_parrafos -= lim_parrafos;
        do{
            estructura.PB('f');
            lim_parrafos--;
        }while(lim_parrafos>num_parrafos);
        //fin parrafos feliz

        do{
            int elegir_transicion = rand()%2;

            if(elegir_transicion==0){ estructura.PB('r'); }
            else{ estructura.PB('t'); }
            num_parrafos--;
        }while(num_parrafos>1);

        estructura.PB('b');
        num_parrafos--;

    }//fin carta anoranza


    //carta de enojo
    if(tipo==3){
        do{
            cout<<"\n\tIngrese numero de parrafos de la carta--->"; cin>>num_parrafos;
            if(num_parrafos<3){ cout<<"\n\tEl numero de parrafos debe ser minimo de 3"; }
        }while(num_parrafos<3);
        //limita el numero de parrafos
        num_parrafos--;

        int hacer_despedida = rand()%2;
        do{
            estructura.PB('e');
            num_parrafos--;
        }while(num_parrafos>hacer_despedida);

        if(num_parrafos>0){
            estructura.PB('b');
            num_parrafos--;
        }//si se decide despedir

    }//fin carta enojo

    //carta de decepcion
    if(tipo==4){
        do{
            cout<<"\n\tIngrese numero de parrafos de la carta--->"; cin>>num_parrafos;
            if(num_parrafos<4){ cout<<"\n\tEl numero de parrafos debe ser minimo de 4"; }
        }while(num_parrafos<4);
        //limita el numero de parrafos
        num_parrafos--;

        int lim_parrafos = 1 + rand()%(num_parrafos-2);
        for(int i=0;i<lim_parrafos;i++){
            estructura.PB('e');
            num_parrafos--;
        }//fin for enojo

        while(num_parrafos>1){
            estructura.PB('t');
            num_parrafos--;
        }//fin while tristeza

        estructura.PB('b');
        num_parrafos--;

    }//fin carta decepcion

    //carta romantica
    if(tipo==5){
        do{
            cout<<"\n\tIngrese numero de parrafos de la carta--->"; cin>>num_parrafos;
            if(num_parrafos<3){ cout<<"\n\tEl numero de parrafos debe ser minimo de 3"; }
        }while(num_parrafos<3);
        //limita el numero de parrafos
        num_parrafos--;

        estructura.PB('r');
        num_parrafos--;

        do{
            int elegir_transicion = rand()%2;
            if(elegir_transicion==0){ estructura.PB('r'); }
            else{ estructura.PB('f'); }
            num_parrafos--;
        }while(num_parrafos>1);

        estructura.PB('b');
        num_parrafos--;
    }//fin carta romantica

    cout<<"\n\tEstructura Generada: "<<estructura<<endl;
    bool aceptada = verificarCarta(estructura);

    if(aceptada == true){ generarEjemplo(estructura); validarAnimo(estructura); }
}

 

void menu(){
	cout<<"\n ------------------------------------------\n";
    cout<<"\t CARTAMATIC 7000 ";
    cout<<"\n ------------------------------------------\n";
    cout<<"\n\n ESTE PROGRAMA PERMITE REALIZAR UNA DE LAS SIGUIENTES INSTRUCCIONES\n Selecciona una de ellas \n";
    cout<<"\n -------------------------------------------------------";
    cout<<"\n |       1.Validar la estructura de una carta          |";
    cout<<"\n -------------------------------------------------------";
	cout<<"\n |       2.Generar una carta                           |";
    cout<<"\n -------------------------------------------------------";
    cout<<"\n |       3.Validar el animo de una carta               |";
    cout<<"\n -------------------------------------------------------";
    cout<<"\n |       4.Salir del programa                          |";
    cout<<"\n -------------------------------------------------------";
    cout<<"\n\n SELECCION --->  ";
}

int main(){
    srand(time(NULL));
    setlocale(LC_ALL, "spanish");
    //construir ndfa para verificar cadenas
    construirNDFA(ndfa);
    construirNDPDA(ndpda);

    int seleccion;
    //inicio();
    do{
    	system("cls");
        menu();
        cin>>seleccion;
        cout<<"\n\n PRESIONE ENTER PARA CONTINUAR A LA PANTALLA DE LA SELECCION QUE HA TOMADO\n ";
		system("pause");

            if(seleccion==1){
            string cadena;
            system("cls");
            cout<<"\n ------------------------------------------------------------------------------ \n";
            cout<<"\t\t VALIDACION DE UNA CARTA";
            cout<<"\n ------------------------------------------------------------------------------ \n";
            estructura();
            cout<<"\n\tIngrese cadena de la estructura de la carta: \n\t";
            cin>>cadena;


			cout<<"\n\n\tValidacion de la carta\n\t----------------------------------------------  ";
            bool aceptada = verificarCarta(cadena);
			cout<<"\t---------------------------------------------- \n\n\n ";

            if(aceptada==true){
                cout<<"\n\tValidacion del estado de animo de la carta\n\t----------------------------------------------  ";
				validarAnimo(cadena);
				cout<<"\t---------------------------------------------- \n\n\n ";
				generarEjemplo(cadena);
            }//si se acepta

           }//validar una cadena

           if(seleccion==2){
           		system("cls");
            	cout<<"\n ------------------------------------------------------------------------------ \n";
            	cout<<"\t\t GENERAR UNA CARTA";
            	cout<<"\n ------------------------------------------------------------------------------ \n";
                cout<<"\n\n Elige tipo de carta que quieres obtener:\n";
                cout<<"\n\t1.Carta de felicidad.";
                cout<<"\n\t2.Carta de anoranza.";
                cout<<"\n\t3.Carta de enojo.";
                cout<<"\n\t4.Carta de decepcion.";
                cout<<"\n\t5.Carta romantica.";

                int tipo;
                do{
                    cout<<"\n\n\tIngrese tipo de carta a generar --->"; cin>>tipo;
                    if(tipo<1 || tipo>5){ cout<<"\n\tIngrese una opcion valida\n"; }
                }while(tipo<1 || tipo>5);

                generarCarta(tipo);

           }//generar carta

           if(seleccion==3){
                string cadena;
                system("cls");
                cout<<"\n ------------------------------------------------------------------------------ \n";
            	cout<<"\t\t VALIDAR ESTADO DE ANIMO DE LA CARTA";
            	cout<<"\n ------------------------------------------------------------------------------ \n\n";
            	estructura();
                cout<<"\n\n\tIngrese cadena de la estructura de la carta: ";
                cin>>cadena;
                if(cadena[0]!='a' || cadena[cadena.size()-1]!='b'){
                	cout<<"\n\t----------------------------------------------  ";
                    cout<<"\nLa estructura de la carta fue rechazada\n.";
                    cout<<"\t---------------------------------------------- \n\n\n ";
                }//que se rechace si la carta no empieza con un saludo y una despedida
                else{
                	cout<<"\n\t----------------------------------------------  ";
                    validarAnimo(cadena);
                    cout<<"\t---------------------------------------------- \n\n\n ";
					//generarEjemplo(cadena);
                }//tiene saludo y despedida
           }//fin opcion validar animo

            cout<<"\n\n\n\n";
            system("pause");
            system("cls");
    }while(seleccion!=4);

    cout<<"\n\t------------PROYECTO REALIZADO POR------------\n";
    cout<<"\n\tCESAR EDUARDO ELIAS DEL HOYO";
    cout<<"\n\tJOSE LUIS SANDOVAL PEREZ";
    cout<<"\n\tDIEGO EMANUEL SAUCEDO ORTEGA";
    cout<<"\n\tCARLOS DANIEL TORRES MACIAS\n";

	return 0;
}
