
import javax.swing.JFrame;
import java.awt.Container;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import java.awt.FlowLayout;
import java.awt.Color;



public class LabelGUIApp extends JFrame{

    private Container contents;//declare contents
    private JLabel labeltext;
    private JLabel labelImage;

    
    //constructor
    public LabelGUIApp(){

        super("What's for dinner?"); //call JFrame constructor
        contents=getContentPane();  //get content pane
        contents.setLayout(new FlowLayout()); //set layout manager

        labeltext= new JLabel("Sushi tonight?"); //use the JLabel constructor with a String argument
        
        //set label properties
        labeltext.setForeground(Color.WHITE);
        labeltext.setBackground(Color.BLUE);
        labeltext.setOpaque(true);

        //use de JLabel constructor with an ImageIcon argument
        labelImage=new JLabel(new ImageIcon("WIN_20221012_08_50_48_Pro.JPG"));

        //set toolip text
        labelImage.setToolTipText("Photo of sushi");
    
        //add two labels 
        contents.add(labeltext);
        contents.add(labelImage);

        setSize(500,500);
        setVisible(true);

    }

    public static void main( String args[]){

        LabelGUIApp basicgui= new LabelGUIApp();
        basicgui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
}