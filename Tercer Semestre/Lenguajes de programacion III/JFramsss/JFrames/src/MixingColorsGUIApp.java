import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MixingColorsGUIApp extends JFrame
{
 private Container contents;
 private JCheckBox red, green, blue;
 private int redValue,greenValue,blueValue;
private JLabel label;

 public MixingColorsGUIApp( )
 {
  super( "Selecting a color" );
  contents = getContentPane( );
  contents.setLayout( new FlowLayout( ) );

  red = new JCheckBox( "red");
  green = new JCheckBox( "green" );
  blue = new JCheckBox( "blue" );

  label = new JLabel( "Watch my background" );
  label.setForeground( Color.GRAY );
  label.setOpaque( true );
  label.setBackground(new Color(0,0,0) );

  contents.add( red );
  contents.add( green );
  contents.add( blue );
  contents.add( label );

  // create checkboxHandler event handler
  //and register it on the checkboxes

  // create RadioButtonHandler event handler
  // and register it on the radio buttons
  CheckBoxHandler cbh = new CheckBoxHandler();
  red.addItemListener( cbh );
  green.addItemListener( cbh );
  blue.addItemListener( cbh );

  setSize( 225, 200 );
  setVisible( true );
 }

 private class CheckBoxHandler implements ItemListener
 {
  public void itemStateChanged( ItemEvent ie )
  {
        if(ie.getSource()==red){
            if(ie.getStateChange()==ItemEvent.SELECTED){
                redValue=225;
            }else{
            redValue=0;
            }
        }else if(ie.getSource()==green){
            if(ie.getStateChange()==ItemEvent.SELECTED){
                greenValue=225;
            }else{
                greenValue=0;
            }
        }else if(ie.getSource()==blue){
            if(ie.getStateChange()==ItemEvent.SELECTED){
                blueValue=225;
            }else{
                blueValue=0;
            }
        }
        label.setBackground( new Color (redValue,greenValue,blueValue));
    }
}

 public static void main( String [] args )
 {
  MixingColorsGUIApp cc = new MixingColorsGUIApp( );
  cc.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
 }
}