import java.util.Scanner;

public class EstructuraCondicional_IF_ELSE{

    public static void main(String arguements[]){


        // Actividad 2.4 Realizar un programa que calcule el promedio de tres materias y que el programa
        //nos indique si el alumno aprobo o reprobo.

        //Calificaciones 

        

        float Math= 5;
        float Biology= 8;
        float Chemistry = 7;
        float Final_Grade;

        System.out.println("A C T I V I D A D           2.4");
        

        System.out.println("Las calificaciones del alumno son:\nMath=5\nBio=8\nChemistry=7\n");

        Final_Grade=(Math+Biology+Chemistry)/3;
        System.out.println("Calificacion global: " +Final_Grade);

        if(Final_Grade>=6.5){
            System.out.println("El alumno aprueba");
        }else{
            System.out.println("El alumno no aprueba");
            
        }

        System.out.println("\n- - - - - - - - - - - - - - - - - - - - -\n");

        System.out.println("A C T I V I D A D           2.5");

        int num1;
        int num2;
        int op;
        int suma;
        int res;
        int mult;
        int divi;

        try (Scanner input = new Scanner(System.in)) {
            System.out.println("Ingresa 2 numeros enteros\n");
            System.out.println("Numero 1: ");
            num1=input.nextInt();
            System.out.println("Numero 2: ");
            num2=input.nextInt();

            System.out.println("AHORA SELECCIONA UNA OPCION: \n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\nOpcion: ");
            op=input.nextInt();
        }

        if(op==1){
            suma=num1+num2;
            System.out.println("\nElegiste suma, la suma es: "+ suma);
        }
        else if(op==2){
            res=num1-num2;
            System.out.println("\nElegiste resta, la resta es: "+ res);
        }
        else if(op==3){
            mult=num1*num2;
            System.out.println("\nElegiste multiplicacion, la multiplicacion es: "+ mult);
        }
        else if(op==4){
            divi=num1-num2;
            System.out.println("\nElegiste division, la division es: "+ divi);
        }
        

        



        



    }

    
}