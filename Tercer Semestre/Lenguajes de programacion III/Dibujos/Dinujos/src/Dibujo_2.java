import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;


public class Dibujo_2 extends JFrame{
    
    public void paint(Graphics g){
        super.paint(g);
        int x=200;
        int y=10;
       
        
        for (int i=0;i<20;i++){

            g.drawLine(0,0,x,y);
            g.drawLine(200,200,y,x);
            g.drawLine(0,200,y,y);
            g.drawLine(200,0,y,y);
            y=y+10;
            x=x-10;

        }
    }

    public static void main(String [] args){
        Dibujo_2 d2= new Dibujo_2();
        d2.setSize(300,300);
        d2.setVisible(true);
    }

    
}



