import java.util.Scanner;

public class Addition_No_GraphicEnviorment{

    public static void main(String Strings[]){

        //create scanner obtain input from command window

        Scanner input = new Scanner(System.in);

        int number1;
        int number2;
        int number3;
        int sum;

        //first number
        System.out.print("Enter first integer: "); //prompt
        number1=input.nextInt(); //read first number from user

        //second number
        System.out.print("Enter second integer: "); //prompt
        number2=input.nextInt(); //read second number from user
        
        //third number
        System.out.print("Enter first integer: "); //prompt
        number3=input.nextInt(); //read third number from user

        sum= number1+number2+number3;

        System.out.println("Sum is: "+sum ); //displays sum
        

    }


}