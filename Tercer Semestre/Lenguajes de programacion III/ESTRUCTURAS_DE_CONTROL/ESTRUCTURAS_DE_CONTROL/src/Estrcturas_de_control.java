
import java.util.Scanner;

public class Estrcturas_de_control {


    public static void main(String[] args) {

        //variables 2.7
        float n1;
        float n2;
        int op;
        float sum;
        float res;
        float mult;
        float div;
        int opc_s;
        
        try (Scanner entrada = new Scanner(System.in)) {
            //Actividad 2.7
                System.out.println("A C T I V I D A D   2.7");
                System.out.println("------------------------------");
                System.out.println("Ingresa 2 numeros enteros y selecciona una opcion.\n1.suma\n2.Resta\n3.Multiplicacion\n4.Division");
                System.out.println("Numero 1: ");
                n1=entrada.nextInt();
                System.out.println("Numero 2: ");
                n2=entrada.nextInt();

                System.out.println("Operacion a realizar: ");
                op=entrada.nextInt();
            

            switch (op) {
                case 1:
                    sum=n1+n2;
                    System.out.println("La suma de los 2 numeros es " + sum);
                    break;
                case 2:
                    res=n1-n2;
                    System.out.println("La resta del n1 - n2 es: " + res);
                    res=n2-n1;
                    System.out.println("La resta del n2 - n1 es: " + res);
                    break;
                case 3:
                    mult=n1*n2;
                    System.out.println("La multiplicacion de los 2 numeros es: " + mult);
                    break;
                case 4:
                    div=n1/n2;
                    System.out.println("La division de n1/n2 es: " + div );
                    div=n2/n1;
                    System.out.println("La division de n2/n1 es: " + div); 
                    break;   
                default:
                    System.out.println("Opcion invalida");
                    break;
            }

            //Actividad 2.8

            System.out.println(" - - - - - - - - - - - - - - - - - - - - ");
            System.out.println("A C T I V I D A D   2.8");
            System.out.println("- - - - - - - - - - - - - - - - - - - - - - -");

            System.out.println("Serie numerica");

            for (int i = 0; i < 5; i++) {

                System.out.print(i+1 + ", ");
                
            }

            //Actividad 2.9
            System.out.println("\n - - - - - - - - - - - - - - - - - - - - ");
            System.out.println("A C T I V I D A D   2.9");
            System.out.println("- - - - - - - - - - - - - - - - - - - - - - -");

            int num=1;

            while(num<10){
                System.out.println(num);
                num++;
                num++;
            }

            //Actividad 2.10

            System.out.println("\n - - - - - - - - - - - - - - - - - - - - ");
            System.out.println("A C T I V I D A D   2.10");
            System.out.println("- - - - - - - - - - - - - - - - - - - - - - -");

            
            int serie=1000;

            do{
                System.out.println(serie);
                serie=serie-200;
            }while(serie>=0);

            // Actividad 2.11
        
        

            System.out.println("\n - - - - - - - - - - - - - - - - - - - - ");
            System.out.println("A C T I V I D A D   2.11");
            System.out.println("- - - - - - - - - - - - - - - - - - - - - - -");
            
            System.out.print ("Elige opcion a ejecutar: \n\n");
            System.out.print (" 1. Serie 1-10 \n");
            System.out.print (" 2. Serie 1,99,2,9,3,97,4,96,... \n");
            System.out.print (" 3. Serie Fibonacci \n");
            System.out.print ("Opcion: ");

            opc_s=entrada.nextInt();


            System.out.println ("-----------------------------------------------------\n\n");
        
            switch (opc_s){
                case 1: 
                    System.out.println (" SERIE DEL 0-10 \n");
                    for (int x = 0; x <= 10; x++){
                        System.out.println(x);
                    }
                    break;
                case 2:
                    int limite , x = 1, serie_2 = 0;
                    System.out.println ("Ingresa numero limite de la serie:");
                    limite = entrada.nextInt();
                    System.out.println ("-----------------------------------------------------");
                    System.out.println (" SERIE 1,99,2,9,3,97,4,96,... \n");
                    for (int y=1; y<=limite; y++){
                        if (y % 2 != 0){
                            serie = x;
                            System.out.println(serie_2);
                        }
                        else{
                            serie = 100 - x;
                            System.out.println(serie_2);
                            x++;
                        }
                    }
                    break;
                case 3: 
                    int a=0, b=1, c=0, n=0; 
                    System.out.println ("Dame el número límite de la serie:");
                    n = entrada.nextInt();
                    System.out.println ("-----------------------------------------------------");
                    System.out.println (" SERIE FIBONACCI \n");
                    for (int z=0; z<n; z++){
                        System.out.println(a);
                        c = a + b;
                        a = b;
                        b = c;
                    }
                    break;
                default: System.out.println ("--- OPCION NO VALIDA ---\n\n");
                    break; 
            }
        }

        
    
    
    
    }
}
