import java.util.Scanner;

public class Op_Relacionales_Logicos{

public static void main(String[] agrs){

    String Name;
    int Old;
    int Clave;

    try (Scanner entrada= new Scanner (System.in);) {
        System.out.println("A C T I V I D A D   2.6\n");
        System.out.println("C O C A   C O L A   C O M P A N Y ");
        System.out.println("--------------------------------------");
        System.out.println("\nBienvenido al sistema de calculo de vacaciones...");
        System.out.println("Ingresa los datos del trabajador para calcular sus dias de vacaciones\n1.Nombre\n2.Antiguedad\n3.Clave");
        System.out.println("\n---------------------------------------------------------\n");


        //Ingresar nombre trabajador
        System.out.println("Ingresa el nombre del trabajador: ");
        Name=entrada.nextLine();
        //Ingresar Antiguedad trabajador
        System.out.print("Ingresa la antiguedad del trabajador: ");
        Old=entrada.nextInt();
        //Ingresar clave del trabajador
        System.out.println("Ingresa clave del trabajador\n1.Atencion a clientes\n2.Logistica\n3.Gerencia\n");
        System.out.println("Clave: ");
        Clave=entrada.nextInt();
    }

    

    //condicionales if´s

    //clave 1
    if(Clave==1){
        if(Old==1){
            System.out.println("El trabajador con clave 1  ," + Name + " con 1 year de antiguedad recibe 6 dias de vacaciones.");
        }
        else if(Old>=2 && Old<=6){
            System.out.println("El trabajador con clave 1  ," + Name + " con " + Old +  " years de antiguedad recibe 14 dias de vacaciones.");
        }
        else if(Old>=7){
            System.out.println("El trabajadorccon clave 1 ," + Name + " con " + Old + " years de antiguedad recibe 22 dias de vacaciones.");
        }
    }
    //clave 2
    else if(Clave==2){
        if (Old==1) {
            System.out.println("El trabajador con clave 2 ," + Name + " con 1 year de antiguedad recibe 7 dias de vacaciones.");
        }
        else if(Old>=2 && Old<=6){
            System.out.println("El trabajador con clave 2 ," + Name + " con " + Old  + " years de antiguedad recibe 15 dias de vacaciones.");
        }
        else if(Old>=7){
            System.out.println("El trabajador con clave 2  ," + Name + " con " + Old + " years de antiguedad recibe 22 dias de antiguedad.");
        }
    }
    //clave 3
    else if(Clave==3){
        if (Old==1) {
            System.out.println("El trabajador con clave 3 ," + Name + " con 1 year de antiguedad recibe 7 dias de vacaciones.");
        }
        else if(Old>=2 && Old<=6){
            System.out.println("El trabajador con clave 3 ," + Name + " con " + Old  + "years de antiguedad recibe 20 dias de vacaciones.");
        }
        else if(Old>=7){
            System.out.println("El trabajador con clave 3 ," + Name + " con " + Old + " years de antiguedad recibe 30 dias de antiguedad.");
        }

    }

    
    




}


    

    
}