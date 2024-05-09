import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FASE_1_CEEH extends JFrame implements ActionListener {
    private Container contents;
    private JMenuBar bm;
    private JMenu archivo, operadores;
    private JMenuItem ai,gi,s,n,eg,p,b;
    private JLabel labelImage;
    private BufferedImage buf;
    byte[] bytesImg;

    JFileChooser jf = new JFileChooser();
    File rfile;
    
    public FASE_1_CEEH() {
    // Crear Label para colocar imagen en el JFrame    
        super ("PROYECTO FINAL - FASE 1");
        contents = getContentPane();
        contents.setLayout(new FlowLayout());
        
    // Colocar barra de menu
        setLayout (null);
        bm = new JMenuBar();
        setJMenuBar(bm);
        labelImage = new JLabel();
        labelImage.setSize(800,800);
        contents.add(labelImage);

    // Menu 1 ( Archivo )
        archivo = new JMenu("Archivo");
        bm.add(archivo);

        // Item 1 - Menu 1 ( Abrir Imagen )
        ai = new JMenuItem("Abrir Imagen");
        ai.addActionListener(this);
        archivo.add(ai);

        // Item 2 - Menu 1 ( Guardar Imagen )
        gi = new JMenuItem("Guardar Imagen");
        gi.addActionListener(this);
        archivo.add(gi);

        // Item 3 - Menu 1 ( Salir )
        s = new JMenuItem("Salir");
        s.addActionListener(this);
        archivo.add(s);

    // Menu 2 ( Operadores )
        operadores = new JMenu("Operadores");
        bm.add(operadores);

        // Item 1 - Menu 2 ( Negativo )
        n = new JMenuItem("Negativo");
        n.addActionListener(this);
        operadores.add(n);

        // Item 2 - Menu 2 ( Escala de Grises )
        eg = new JMenuItem("Escala de Grises");
        eg.addActionListener(this);
        operadores.add(eg);

        // Item 3 - Menu 2 ( Potencia )
        p = new JMenuItem("Potencia");
        p.addActionListener(this);
        operadores.add(p);

        // Item 4 - Menu 2 ( Binarización )
        b = new JMenuItem("Binarizacion");
        b.addActionListener(this);
        operadores.add(b);

        setSize(1000,1000);
        setVisible(true);
    }

    FileInputStream entrada;
    FileOutputStream salida;

    public byte[] AbrirImagen(File archivo) {
        byte[] bytesImg = new byte[1000000];
        try {
            entrada = new FileInputStream(archivo);
            entrada.read(bytesImg);
        } catch (Exception e) {
        }
        return bytesImg;
    }
    

    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub

        // Abrir Imagen
        if (e.getSource() == ai){
            FileNameExtensionFilter filtrado = new FileNameExtensionFilter ("JPG, PNG & GIF","jpg","png","gif");
            jf.setFileFilter(filtrado);
            if (jf.showOpenDialog(null) == JFileChooser.APPROVE_OPTION){
                rfile = jf.getSelectedFile();
                if (rfile.canRead()){
                    try{
                        buf=ImageIO.read(rfile);
                    } catch (IOException e1){
                        e1.printStackTrace();
                    }
                }
                bytesImg=AbrirImagen(rfile);
                labelImage.setIcon(new ImageIcon(bytesImg));

                setSize(buf.getWidth(),buf.getHeight());
            }
        }    

        // Guardar Imagen
        else if (e.getSource() == gi){
            
        }
        // Salir
        else if (e.getSource() == s){
            
        }
        // Negativo
        else if (e.getSource() == n){
            
        }
        // Escala de Grises
        else if (e.getSource() == eg){
            for (int c=0; c<buf.getWidth(); c++){
                for (int f=0; f<buf.getHeight(); f++){ //tenias c++ en vez de f++
                    Color color = new Color (buf.getRGB(c,f));
                    int r = color.getRed();
                    int g = color.getGreen();
                    int b = color.getBlue();
                    int gris = (r+g+b)/3;
                    color=new Color(gris,gris,gris);
                    buf.setRGB(c,f,color.getRGB());
                }
            }
            
            ImageIcon mIconeg = new ImageIcon (buf);
            labelImage.setIcon(mIconeg);
        }
        // Potencia
        else if (e.getSource() == p){
            
        }
        // Binarizacion
        else if (e.getSource() == b){

        }
    }
    
    public static void main(String[] args) {
        FASE_1_CEEH p1 = new FASE_1_CEEH();
       // p1.setLocationRelativeTo(null);
        p1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        
    }
}