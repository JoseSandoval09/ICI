
import javax.swing.JFrame;
import java.awt.Container;


public class GUIApp extends JFrame{

    private Container contents;//declare contents

    
    //constructor
    public GUIApp(){

        //call JFrame constructor with tittle bar
        super("A shell GUI Application");
        //get container for components
        contents=getContentPane();

        //set layout manager
        //instantiate GUI components
        //add GUI components and other instance variables
        // add GUI components to the content pane
        
        //set original size to the window
        setSize(600,400);

        //make window visible
        setVisible(true);

    }

    public static void main( String args[]){

        GUIApp basicgui= new GUIApp();
        basicgui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    }
    
}