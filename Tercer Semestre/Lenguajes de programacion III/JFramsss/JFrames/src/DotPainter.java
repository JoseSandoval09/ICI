import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.plaf.basic.BasicTabbedPaneUI.MouseHandler;

import org.w3c.dom.events.MouseEvent;


public class DotPainter extends JFrame {
    private int x=-10, y=-10;
    private MouseHandler mouseh;

    public DotPainter(){
        super("D O T    P A I N T E R ");
        getContentPane();
        mouseh= new MouseHandler();
        addMouseListener(mouseh);
        setSize(500,500);
        setVisible(true);
    }

    private class MouseHandler extends MouseAdapter{

        public void mouseclicked(MouseEvent event){
            
        }


    }
    
}
