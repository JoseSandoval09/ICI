import java.util.Scanner;


class OperadoresAritmeticosYPrioridadDeSignos{

    public static void main( String arguments[]){

        //Actividad 2.1 Sume dos numeros enteros e imprima el resultado

        int num1=10;
        int num2=30;
        int sumAct1= num1+num2;

        System.out.print("A C T I V I D A D     2.1\n");
        System.out.print("El resultado de la suma de 10 + 30 es: " + sumAct1);

        System.out.print("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");

        //Actividad 2.2  capture 2 numeros de la consola, suma e imprima el resultado
        
        int num3;
        int num4;
        int sumAct2;
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("A C T I V I D A D     2.2\n");

            System.out.print("Introduzca primer numero entero: ");
            num3=input.nextInt();

            System.out.print("\nIntroduzca segundo numero entero: ");
            num4=input.nextInt();

            sumAct2=num3+num4;
            System.out.print("\nLa suma de los 2 numeros ingresados es: " + sumAct2);

            System.out.print("\n- - - - - - - - - - - - - - - - - - - - - - - - -\n");

            //Actividad 2.3 sume 2 numeros enteros y dividalos en n e imprima el resultado

            System.out.print("A C T I V I D A D     2.3\n");

            int divisor;
            

            System.out.print("\nLa suma de estos 2 numeros sera dividida entre un numero n, ingresalo: ");
            divisor=input.nextInt();
            float division = (num3+num4)/divisor;

            System.out.print("La división entre n es : " + division);
        }



        








    }





}
