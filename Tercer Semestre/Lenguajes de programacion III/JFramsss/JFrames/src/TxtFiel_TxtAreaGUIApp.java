import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextArea;
import javax.swing.JFrame;
import javax.swing.JTextField;



public class TxtFiel_TxtAreaGUIApp extends JFrame {
    
    private Container contents;
    private JLabel idLabel,passwordLabel,message;
    private JTextField id;
    private JPasswordField pass;
    private JTextArea tyc;
    
    


    public TxtFiel_TxtAreaGUIApp(){
        //call frame constructor 
        super("Login screen");
        contents=getContentPane();
        contents.setLayout(new FlowLayout()); //get layout

        //declare variables
        idLabel= new JLabel("Enter ID");
        id=new JTextField("",12);
        passwordLabel= new JLabel("Enter password ");
        pass=new JPasswordField("",12);
        message= new JLabel("");
        tyc=new JTextArea("Aceptando terminos y condiciones");

        //add variables to panel
        contents.add(idLabel);
        contents.add(id);
        contents.add(passwordLabel);
        contents.add(pass);
        contents.add(message);
        contents.add(tyc);

        
        //declare TextFieldHandler

        TextFieldHandler tfh = new TextFieldHandler();
        //add action listener to the variables "enter"
        id.addActionListener(tfh);
        pass.addActionListener(tfh);
        
        //set window size
        setSize(250,200);
        setVisible(true);

    }

    //private inner class event handler

    private class TextFieldHandler implements ActionListener{

        public void actionPerformed( ActionEvent e){
            if(id.getText().equals("261731") && (new String (pass.getPassword())).equals("Charmander09")){
                message.setForeground(Color.BLACK);
                message.setText("WELCOME!");
            }
            else{
                message.setForeground(Color.RED);
                message.setText("WRONG LOGIN");  
            }
        }

        
    }

    public static void main(String args[]) {
        
        TxtFiel_TxtAreaGUIApp textfield = new TxtFiel_TxtAreaGUIApp();
        textfield.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }


}
