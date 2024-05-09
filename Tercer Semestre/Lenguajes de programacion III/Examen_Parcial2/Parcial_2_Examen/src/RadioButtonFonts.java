import javax.swing.*;
import javax.swing.text.AttributeSet.FontAttribute;

import java.awt.*;
import java.awt.event.*;




public class RadioButtonFonts extends JFrame {

    private Container contents;
    private JRadioButton plain, bold, italic,bold_italic;
    private ButtonGroup FontGroup;
    private JTextField textField;
    
    

    public RadioButtonFonts()
    {
        super( "Select Font" );
        contents = getContentPane( );
        contents.setLayout( new FlowLayout( ) );

        plain= new JRadioButton( "plain", true );
        bold = new JRadioButton( "bold" );
        italic = new JRadioButton( "italic" );
        bold_italic=new JRadioButton("bold/italic");

        textField = new JTextField( "Watch my FONT" );
        //(textField.setFont(getFont().deriveFont(Font.ROMAN_BASELINE));

        contents.add(textField);
        contents.add( plain );
        contents.add( bold );
        contents.add( italic );
        contents.add(bold_italic);


        // create button group
        FontGroup = new ButtonGroup( );
        FontGroup.add( plain );
        FontGroup.add( bold );
        FontGroup.add( italic );
        FontGroup.add(bold_italic);

        // create RadioButtonHandler event handler
        // and register it on the radio buttons
        RadioButtonHandler rbh = new RadioButtonHandler( );
        plain.addItemListener( rbh );
        bold.addItemListener( rbh );
        italic.addItemListener( rbh );
        bold_italic.addItemListener(rbh);

        setSize( 225, 200 );
        setVisible( true );
    }

    private class RadioButtonHandler implements ItemListener
    {
       
        public void itemStateChanged(ItemEvent ie){
            Font font = null;
            if(ie.getSource() == plain){
                font = new Font("Serif", Font.PLAIN, 14);
                textField.setFont(font);
            }else if(ie.getSource() == bold){
                font = new Font("Serif", Font.BOLD, 14);
                textField.setFont(font);
            }else if(ie.getSource() == italic){
                font = new Font("Serif", Font.ITALIC, 14);
                textField.setFont(font);
            }else if(ie.getSource() == bold_italic){
                font = new Font("Serif", Font.BOLD + Font.ITALIC, 14);
                textField.setFont(font);
            }
            
        }
    }

    public static void main( String [] args )
    {
        RadioButtonFonts rbf = new RadioButtonFonts( );
        rbf.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
    }
}
