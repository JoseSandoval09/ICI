import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;

public class Dibujo_1 extends JFrame{
    public void paint(Graphics g){
        super.paint(g);

        int x=200;
        int y=10;

        for(int i=0;i<20;i++){
            g.setColor(Color.BLUE);
            g.drawLine(0, 0, x, y);
            x=x-10;
            y=y+10;

        }
    }

        public static void main(String[] args){
            Dibujo_1 d1 = new Dibujo_1();

            d1.setSize(300,300);
            d1.setVisible(true);


    }
}