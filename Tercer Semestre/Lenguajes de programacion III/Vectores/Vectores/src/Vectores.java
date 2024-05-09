import java.util.Scanner;

public class Vectores {


    
    public static void main(String[] args) throws Exception {
        
        int vect1[]={5,10,15,20,25};

        System.out.println("\nA C T I V I D A D   2.16 \n----- VECTOR 5 POSICIONES-----");

        System.out.println("EL VECTOR EN EL SISTEMA ES: ");

        for(int i=0;i<5;i++){
            System.out.print("   " + vect1[i]);
        }

        System.out.println("\nA C T I V I D A D   2.17 \n----- VECTOR x USUARIO-----");

        int lenght;
        

        Scanner input= new Scanner(System.in);

        System.out.println("Ingresa tamaño del vector: ");
        lenght=input.nextInt();
        int [] vect2= new int [lenght];

        System.out.println("Ingresa los valores del vector: ");


        for(int i=0;i<lenght;i++){
            System.out.print("Numero  " + (i+1) + " :" );
        
            vect2[i]=input.nextInt();
        }

        for(int i=0;i<lenght;i++){
            System.out.print("[" +vect2[i]+"]" );
        }

        

        input.close();




    }
}
