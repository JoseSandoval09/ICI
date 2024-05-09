import javax.swing.JFrame;

public class Visual_1 extends JFrame{

    public void paint(Graphics g){

        super.paint((java.awt.Graphics) g);
        int y=10;
        int x=200;

        for(int i=0;i<20;i++){
            g.drawLine(0, 0, x,y);
            x=x-10;
            y=y+10;
        }
        


    }

    
}

