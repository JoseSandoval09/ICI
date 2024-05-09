/* Using GridLayout to organize our window
   Anderson, Franceschi
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GridChangeColor extends JFrame
{
 public static final int SIDE = 8;
 private Container contents;
 private JButton [][] squares;
 private String [][] names =
  { 
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" },
    { "green","red","green","red","green","red", "green", "red" }, 
    };

 public GridChangeColor( )
 {
  super( "Click a square to reveal its position" );
  contents = getContentPane( );

  // set layout to an 8-by-8 Grid
  contents.setLayout( new GridLayout( SIDE, SIDE ) );

  squares = new JButton[SIDE][SIDE];

  ButtonHandler bh = new ButtonHandler( );

  for ( int i = 0; i < names.length; i++ )
  {
   for ( int j = 0; j < SIDE; j++ )
   {
    // instantiate JButton array
    squares[i][j] = new JButton( );
    squares[i][j].setBackground(Color.WHITE);

    // make every other square red
   
    // add the JButton
    contents.add( squares[i][j] );

    // register listener on button
    squares[i][j].addActionListener( bh );
   }
  }

  setSize( 400, 400 );
  setVisible( true );
 }

 private class ButtonHandler implements ActionListener
 {
  public void actionPerformed( ActionEvent ae )
  {
    for ( int i = 0; i < SIDE; i++ )
    {
      for ( int j = 0; j < SIDE; j++ )
      {
        if ( ae.getSource( ) == squares[i][j] )
        {
          squares[i][j].setText( names[i][j] );
            if ( (j ) % 2 == 0 )
                squares[i][j].setBackground( Color.GREEN );
            else{
                squares[i][j].setBackground(Color.RED);
        }
          return;
        }
      }
    }
  }
 }

 public static void main( String [] args )
 {
   GridChangeColor myGame = new GridChangeColor( );
   myGame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
 }
}