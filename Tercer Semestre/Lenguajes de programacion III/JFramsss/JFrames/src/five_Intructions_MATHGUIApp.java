import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class five_Intructions_MATHGUIApp extends JFrame {

    private Container contents;
    private JLabel pow, negative, sqrt , cos, tan;
    private JTextField rPow,rNegative, rSqrt, rTan, rCos;
    private double rpow, rnegative,rsqrt,rcos,rtan;
    
    public five_Intructions_MATHGUIApp(){

        super(" 5 MATH INSTRUCTIONS");
        contents=getContentPane();
        contents.setLayout(new FlowLayout());

        pow=new JLabel("Pow of 5 to 5 = ");
        negative=new JLabel("\nNegative of 10 = ");
        sqrt=new JLabel("\nSqrt of 125 = ");
        cos=new JLabel("\nCos of 36.54 = ");
        tan= new JLabel("\nTan of 45.23 = "); 

        rpow=Math.pow(5, 5);
        rPow=new JTextField(String.valueOf(rpow));

        rnegative = Math.negateExact(10);
        rNegative=new JTextField(String.valueOf(rnegative));

        rsqrt=Math.sqrt(125);
        rSqrt=new JTextField(String.valueOf(rsqrt));

        rcos=Math.cos(36.54);
        rCos=new JTextField(String.valueOf(rcos));

        rtan=Math.tan(45.23);
        rTan=new JTextField(String.valueOf(rtan));

        //
        contents.add(pow);
        contents.add(rPow);
        contents.add(negative);
        contents.add(rNegative);
        contents.add(sqrt);
        contents.add(rSqrt);
        contents.add(cos);
        contents.add(rCos);
        contents.add(tan);
        contents.add(rTan);

        setSize(200,300);
        setVisible(true);



    }

    public static void main(String [] args){

        five_Intructions_MATHGUIApp fi= new five_Intructions_MATHGUIApp();
        fi.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    


    
}
