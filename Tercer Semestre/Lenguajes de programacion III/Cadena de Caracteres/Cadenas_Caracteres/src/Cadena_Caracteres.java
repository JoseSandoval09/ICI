import java.util.Scanner;

public class Cadena_Caracteres{

   
    public static void main(String[] args){

        String Name1,Name2;
      
        //A C T I V I D A D E S  2.12 - 2.15

        Scanner input = new Scanner(System.in);
            

            System.out.println("A C T I V I D A D   2.12 \n-----C O M P A R A R     N A M E  -----");
            System.out.println("Ingresa 2 nombres: ");
            System.out.print("\nN A M E     1 : ");
            Name1=input.nextLine();
            System.out.print("N A M E     2 : ");
            Name2=input.nextLine();

            if(Name1.equals(Name2)){
                System.out.println("\nLOS NOMBRE SON IGUALES");
            }else{
                System.out.println("\nLOS NOMBRES NO SON IGUALES");
            }


            String username="Pechocho09";
            String password="guapo123";
            String passbyuser="";
            String namebyuser="";

            System.out.println("\nA C T I V I D A D   2.13 \n----- USERNAME&PASSWORD-----");
            
            System.out.print("Ingresa username: ");
            namebyuser=input.nextLine();

            System.out.print("Ingresa password:");
            passbyuser=input.nextLine();

            if(namebyuser.equals(username)&&passbyuser.equals(password)){
                System.out.println("USER Y PASSWORD CORRECTOS");
            }else{
                System.out.println("USER Y PASSWORD INCORRECTOS");
            }

            System.out.println("\nA C T I V I D A D   2.14 \n----- PESO DE CADENA-----");

            String cadeaxuser;
            int pesocadena;
            int numcadena;

            System.out.println("Ingresa una cadea y te dire el peso: ");
            cadeaxuser=input.nextLine();

            pesocadena=cadeaxuser.length();

            System.out.println("El peso de la cadena es " + pesocadena + " letras");
        
            System.out.println("Ingresa el numero del caracter hasta donde deseas obtener la cadena: ");
            numcadena=input.nextInt();

            for(int i=0;i<numcadena;i++){
                System.out.print(cadeaxuser.charAt(i));
            }

            Scanner input2=new Scanner(System.in);

            System.out.println("\nA C T I V I D A D   2.15 \n----- NOMBRE Y APELLIDO-----");

            String fullname;
        
            System.out.print("Ingresa nombre y apellido con espacios:");
            fullname=input2.nextLine();
        

            System.out.println("Su apellido es : " + fullname.substring(fullname.indexOf(' '),fullname.length()));

            input.close();
            input2.close();




        
    }    
}