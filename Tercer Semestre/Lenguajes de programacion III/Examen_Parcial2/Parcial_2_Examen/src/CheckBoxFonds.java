import javax.swing.*;
import java.awt.*;
import javax.swing.JCheckBox;
import java.awt.event.*;


public class CheckBoxFonds extends JFrame {
    
    private Container contents;
    private JCheckBox bold, italic;
    private JTextField text;



    public CheckBoxFonds(){

        super("CheckBoxFonds");
        contents = getContentPane( );
        contents.setLayout( new FlowLayout( ) );

        bold= new JCheckBox("Bold");
        italic= new JCheckBox("Italic");
        
        

        text= new JTextField("Watch the font style",12);

        contents.add(text);
        contents.add(bold);
        contents.add(italic);

        CheckboxHandler cbh= new CheckboxHandler();
        bold.addItemListener(cbh);
        italic.addItemListener(cbh);

        setSize(200,200);
        setVisible(true);

    }

    private class CheckboxHandler implements ItemListener{

        public void itemStateChanged(ItemEvent ie){
            Font font = null;
            if(bold.isSelected() && italic.isSelected()){
                font = new Font("Serif", Font.BOLD + Font.ITALIC, 14);
                text.setFont(font);
            }
            else if(bold.isSelected()){
                font = new Font("Serif", Font.BOLD, 14);
                text.setFont(font);
            }
            else if(italic.isSelected()){
                font = new Font("Serif", Font.ITALIC, 14);
                text.setFont(font);
            }
            else{
                font = new Font("Serif", Font.PLAIN, 14);
                text.setFont(font);
            }
        }


    }

    public static void main(String [] args){
        CheckBoxFonds cbf= new CheckBoxFonds();
        cbf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    }



}
