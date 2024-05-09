import javax.swing.JOptionPane;


public class Addition{
    //main method begins execution of Java Application

    public static void main( String args []){

        String firstNumber; //first string enter by user
        String secondNumber; //second string enter by user
        int number1;        //first numer to add
        int number2;        //second number to add
        int sum;            //sum of both numbers

        //read first number

        firstNumber =JOptionPane.showInputDialog("Enter first integer:");
        secondNumber = JOptionPane.showInputDialog("Enter second integer:"); 
        
        //convert numbers from type string to int
        number1= Integer.parseInt(firstNumber);
        number2= Integer.parseInt(secondNumber);

        sum=number1+number2;

        //display results

        JOptionPane.showMessageDialog(null, "The sum is "  + sum  ,"Results", JOptionPane.INFORMATION_MESSAGE);
        //JOptionPane.WARNING_MESSAGE
        //JOptionPane.INFORMATION_MESSAGE
        //JOptionPane.ERROR_MESSAGE
        //JOptionPane.QUESTION_MESSAGE
        //JOptionPane.PLAIN_MESSAGE

        System.exit(0); //terminate application




    }

}
