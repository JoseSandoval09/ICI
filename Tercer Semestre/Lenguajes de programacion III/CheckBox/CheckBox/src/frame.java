import java.awt.Color;


import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JPanel;



public class frame extends JFrame {

    public JPanel panel;

    public  frame(){
        setSize(500,500);
        setTitle("C H E C K   B O X ");
        crearpanel_y_checkbox();
       
        this.getContentPane().setBackground(Color.LIGHT_GRAY);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void crearpanel_y_checkbox(){
        JPanel panel=new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);
        


        
        JCheckBox check1=new JCheckBox("Tarea 1");
        JCheckBox check2=new JCheckBox("Tarea 2 ");
        JCheckBox check3=new JCheckBox("Tarea 3");
        JCheckBox check4=new JCheckBox("Tarea 4");
        JCheckBox check5=new JCheckBox("Tarea 5");


        check1.setBounds(100,100,100,40);
        check2.setBounds(100,150,100,40);
        check3.setBounds(100,200,100,40);
        check4.setBounds(100,250,100,40);
        check5.setBounds(100,300,100,40);

        panel.add(check1);
        panel.add(check2);
        panel.add(check3);
        panel.add(check4);
        panel.add(check5);


    }
    
    

}

