import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class Arreglo_JFrame extends JFrame {

    //creacion de paneles y de area de texto;
    public void  frame(){
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("ARREGLO");
    }

    private void paneles(){
        JPanel panel= new JPanel();
        this.getContentPane().add(panel);
        panel.setLayout(null);
    }

    public void textbox(){
        JTextField textbox= new JTextField();
        textbox.setBounds(10,10,200,200);
        
        
    }

    public static void main(String args []){
        frame f1= new frame();
        
        
    }

    
    




}