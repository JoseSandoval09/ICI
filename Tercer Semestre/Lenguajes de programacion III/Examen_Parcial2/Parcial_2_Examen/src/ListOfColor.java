import javax.swing.JFrame;
import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;


public class ListOfColor extends JFrame{

    private Container contents;
    private JList colors;
    private String[] colorList={

        "Red","Green","Blue","Yellow","Orange"


    };

    private Color[] colors2 = {

        Color.red,Color.GREEN,Color.blue,Color.yellow,Color.ORANGE



    };

    public ListOfColor(){

        super("ListOfColors");
        contents = getContentPane( );
        contents.setLayout( new FlowLayout( ) );

        // instantiate the components

        colors = new JList<>(colorList);
        //contents.setBackground(Color.WHITE);

        //
        colors.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        colors.setSelectedIndex(0);


        contents.add(colors);

        //event hablder
        ListHandler lshl= new ListHandler();
        colors.addListSelectionListener(lshl);


        setSize( 350, 150 );
        setVisible( true );
        

    }

    private class ListHandler implements ListSelectionListener{

        public void valueChanged(ListSelectionEvent lse ){
            contents.setBackground(colors2[colors.getSelectedIndex()]);
        }

    }

    public static void main(String [] args ){

        ListOfColor lof= new ListOfColor();
        lof.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }







}
