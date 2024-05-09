import javax.swing.JOptionPane;

public class Comparasion{


    public static void main(String args[]){

        String Number1;
        String Number2;

        int num1;
        int num2;

        Number1 = JOptionPane.showInputDialog("Ingresa numero 1: ");
        Number2 = JOptionPane.showInputDialog("Ingresa numero 2:");

        num1 = Integer.parseInt(Number1);
        num2 = Integer.parseInt(Number2);

        if(num1==num2 || num2==num1){
            JOptionPane.showMessageDialog(null, num1 + "=" + num2 +"\n"+ num1 + "<=" + num2, "Comparasion results", JOptionPane.INFORMATION_MESSAGE);
           
        }
        
        if(num1<num2){
            JOptionPane.showMessageDialog(null, num1 + "!=" + num2 +"\n"+ num1 + "<=" + num2 + "\n" + num1 + "<" + num2, "Comparasion results", JOptionPane.INFORMATION_MESSAGE);
           
        }
        if(num1>num2){
            JOptionPane.showMessageDialog(null, num1 + "!=" + num2 +"\n"+ num1 + ">=" + num2 + "\n" + num1 + ">" + num2, "Comparasion results", JOptionPane.INFORMATION_MESSAGE);
           
        }

       
        if(num2<num1){
            JOptionPane.showMessageDialog(null, num2 + "!=" + num1 +"\n"+ num2 + ">=" + num1 + "\n" + num2 + ">" + num1, "Comparasion results", JOptionPane.INFORMATION_MESSAGE);
        }
        if(num2>num1){
            JOptionPane.showMessageDialog(null, num2 + "!=" + num1 +"\n"+ num2 + ">=" + num2 + "\n" + num1 + ">" + num2, "Comparasion results", JOptionPane.INFORMATION_MESSAGE);
        }
        
    }




}
