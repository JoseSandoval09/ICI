import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import java.awt.Font; 

public class frame extends JFrame {

    public  frame(){
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("L A B E L S");
        Labels();
        this.getContentPane().setBackground(Color.LIGHT_GRAY);
    }
    
    public void Labels(){
       
        JPanel panel=new JPanel();

        this.getContentPane().add(panel);

        panel.setLayout(null);

        JLabel lefty = new JLabel("Bleading heart");
        JLabel center = new JLabel("Centrist");
        JLabel rigthy = new JLabel("Hardliner!");

        Font fuente = new Font("Helvetica", Font.BOLD,14);
         
        setFont(fuente);
        lefty.setBounds(50,50,100,100);
        center.setBounds(150,150,100,100);
        rigthy.setBounds(300,300,100,100);
        panel.add(lefty);
        panel.add(center);
        panel.add(rigthy);


    }

}
