import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.Font; 

public class frame extends JFrame {

    public  frame(){
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("F A C T O R I A L ");
        factorial();
        this.getContentPane().setBackground(Color.LIGHT_GRAY);
    }
    
    public void factorial(){
       
        JPanel panel=new JPanel();

        this.getContentPane().add(panel);

        panel.setLayout(null);

        int num=0;
        int fact=0;
        




        for(int i=0;i<9;i++){
            JLabel zero = new JLabel("\n " + num + " = " + fact + "\n" );
            zero.setBounds(1,1,100,100);
            panel.add(zero);
            num++;


        }
        
        

        /* 
        JLabel one = new JLabel("1! = ");
        JLabel two = new JLabel("2! = "); 
        JLabel three = new JLabel("3! = ");
        JLabel four = new JLabel("4! = ");
        JLabel five = new JLabel("5! = ");
        JLabel six = new JLabel("6! = ");
        JLabel seven = new JLabel("7! = ");
        JLabel eight = new JLabel("8! = ");
        JLabel nine = new JLabel("9! = ");
        JLabel ten = new JLabel("10! = ");
        */

        

        Font fuente = new Font("Helvetica", Font.BOLD,14);
         
        
       
        /* 
        one.setBounds(1,1,100,100);
        two.setBounds(1,1,100,100);
        three.setBounds(1,1,100,100);
        four.setBounds(1,1,100,100);
        five.setBounds(1,1,100,100);
        six.setBounds(1,1,100,100);
        seven.setBounds(1,1,100,100);
        eight.setBounds(1,1,100,100);
        nine.setBounds(1,1,100,100);
        ten.setBounds(1,1,100,100);
        */

    
        
        /* 
        panel.add(one);
        panel.add(two);
        panel.add(three);
        panel.add(four);
        panel.add(five);
        panel.add(six);
        panel.add(seven);
        panel.add(eight);
        panel.add(nine);
        panel.add(ten);
        */



    }

}
