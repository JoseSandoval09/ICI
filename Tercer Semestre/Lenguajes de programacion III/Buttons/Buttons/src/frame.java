import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;



public class frame extends JFrame {

    public JPanel panel;

    public  frame(){
        setSize(500,500);
        setTitle("B U T T O N S");
        crearpanel_y_button();
       
        this.getContentPane().setBackground(Color.LIGHT_GRAY);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void crearpanel_y_button(){
        JPanel panel=new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);
        


        
        JButton boton1=new JButton("Rewind");
        JButton boton2=new JButton("Play");
        JButton boton3=new JButton("Fast foward");
        JButton boton4=new JButton("Stop");
        JButton boton5=new JButton("Eat tape");


        boton1.setBounds(100,100,100,40);
        boton2.setBounds(100,150,100,40);
        boton3.setBounds(100,200,100,40);
        boton4.setBounds(100,250,100,40);
        boton5.setBounds(100,300,100,40);

        panel.add(boton1);
        panel.add(boton2);
        panel.add(boton3);
        panel.add(boton4);
        panel.add(boton5);


    }
    
    

}
