import java.awt.*;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
//import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.image.BufferedImage;



public class ImageChange_FINAL extends JFrame implements ActionListener{

    
    private JMenuBar menubar;
    private JMenu archivo,operadores,bordes,extra;
    private JMenuItem abrir,original,save, gray,negative,binary,claro,obscuro,exit,Lap,Pre,Rob,Sob,Gaus,mirror,blur,rotar;
    private JLabel image;
    
    //private ImageIcon imageo;
    

    File file;
    FileInputStream entrada;
    FileOutputStream salida;
    JFileChooser fileChooser= new JFileChooser();
    byte[] bytesImg;
    

    public ImageChange_FINAL(){

        super("IMAGECHANGE");
        Container contents=this.getContentPane();
        contents.setLayout(new FlowLayout());
        
        menubar= new JMenuBar();
        setJMenuBar(menubar);
        
        image= new JLabel(); 
        image.setBounds(100,100,400,400);  
        contents.add(image);
        //image.setHorizontalAlignment(JLabel.CENTER);
        //image.setVerticalAlignment(JLabel.CENTER);

        archivo= new JMenu("Archivo");
        menubar.add(archivo);
        
        operadores=new JMenu("Operadores");
        menubar.add(operadores);

        bordes=new JMenu("Bordes");
        menubar.add(bordes);

        extra=new JMenu("Extra");
        menubar.add(extra);

        //submenus de archivo

        abrir= new JMenuItem("Abrir foto");
        abrir.addActionListener(this);
        archivo.add(abrir);

        original=new JMenuItem("Regresar a Original");
        original.addActionListener(this);
        archivo.add(original);

        save=new JMenuItem("Guardar foto");
        save.addActionListener(this);
        archivo.add(save);

        exit=new JMenuItem("Salir");
        exit.addActionListener(this);
        archivo.add(exit);

        //submenus de operadores

        gray=new JMenuItem("Escala de Grises");
        gray.addActionListener(this);
        operadores.add(gray);

        negative= new JMenuItem("Negativo");
        negative.addActionListener(this);
        operadores.add(negative);

        binary= new JMenuItem("Binarizacion");
        binary.addActionListener(this);
        operadores.add(binary);

        claro=new JMenuItem("Más brillo");
        claro.addActionListener(this);
        operadores.add(claro);

        obscuro=new JMenuItem("Menos brillo");
        obscuro.addActionListener(this);
        operadores.add(obscuro);

        //submenus de bordes
        Lap=new JMenuItem("Filtro Laplaciano");
        Lap.addActionListener(this);
        bordes.add(Lap);

        Pre=new JMenuItem("Filtro Prewitt");
        Pre.addActionListener(this);
        bordes.add(Pre);

        Rob=new JMenuItem("Filtro Roberts");
        Rob.addActionListener(this);
        bordes.add(Rob);

        Sob=new JMenuItem("Filtro Sobel");
        Sob.addActionListener(this);
        bordes.add(Sob);

        Gaus= new JMenuItem("Gaussiano 3x3");
        Gaus.addActionListener(this);
        bordes.add(Gaus);


        //submenu extra
        mirror= new JMenuItem("MirrorImage");
        mirror.addActionListener(this);
        extra.add(mirror);

        blur=new JMenuItem("BlurImage");
        blur.addActionListener(this);
        extra.add(blur);

        rotar= new JMenuItem("RotarImage Izquierda");
        rotar.addActionListener(this);
        extra.add(rotar);

        setSize(1000,1000);
        setVisible(true);



    }
    public byte[] AbrirImagen(File archivo) {
        byte[] bytesImg = new byte[1000000];
        try {
            entrada = new FileInputStream(archivo);
            entrada.read(bytesImg);
        } catch (Exception e) {
        }
        return bytesImg;
    }

    public void Original(){
        image.setIcon(new ImageIcon(bytesImg));
            try {
                read=ImageIO.read(file);
            } catch (IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
            setSize(read.getWidth(),read.getHeight());
    }
    public void Save(){
        fileChooser.setApproveButtonText("Guardar");
                if (fileChooser.showSaveDialog(null) == JFileChooser.APPROVE_OPTION) {
                    try {
                        file= fileChooser.getSelectedFile();
                        String formato = file.getName().split("\\.")[file.getName().split("\\.").length - 1];
                        ImageIO.write(read, formato, file);
                    } catch (IOException ex) {
                        System.out.println("Error al guardar la imagen");
                    }
                }
    }
    public void GrayScale(){
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color color= new Color(read.getRGB(i, j));
                int rc=color.getRed();
                int gc=color.getGreen();
                int bc=color.getBlue();
                int bw= (rc+gc+bc) / 3;
                color=new Color(bw,bw,bw);
                read.setRGB(i,j,color.getRGB());
            }
        }
        
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void Negative(){
        for(int x=0;x<read.getWidth();x++){
            for(int y=0;y<read.getHeight();y++){

                Color color= new Color(read.getRGB(x, y));
                int rc=255 -color.getRed();
                int gc=255 -color.getGreen();
                int bc=255- color.getBlue();

                color=new Color(rc,gc,bc);

                

                read.setRGB(x, y, color.getRGB());
                

            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void Bina(){
        for(int x=0;x<read.getWidth();x++){
            for(int y=0;y<read.getHeight();y++){

                Color color= new Color(read.getRGB(x, y));
                int rc=color.getRed();
                int gc=color.getGreen();
                int bc=color.getBlue();
                int pr=(rc+gc+bc) /3;
                if(pr>127){
                    color=new Color(255,255,255);
                }else{
                    color=new Color(0,0,0);
                }

                read.setRGB(x, y, color.getRGB());
                

            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void Brightness(){
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color color= new Color(read.getRGB(i, j));
                int rc= (int) (255.0 * Math.pow(Double.valueOf(color.getRed())/255,0.9));
                int gc= (int) (255.0 * Math.pow(Double.valueOf(color.getGreen())/255,0.9));
                int bc= (int) (255.0 * Math.pow(Double.valueOf(color.getBlue())/255,0.9));
                color= new Color(rc,gc,bc);
                read.setRGB(i, j, color.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void LessBrightness(){
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color color= new Color(read.getRGB(i, j));
                int rc= (int) (255.0 * Math.pow(Double.valueOf(color.getRed())/255,1.1));
                int gc= (int) (255.0 * Math.pow(Double.valueOf(color.getGreen())/255,1.1));
                int bc= (int) (255.0 * Math.pow(Double.valueOf(color.getBlue())/255,1.1));
                color= new Color(rc,gc,bc);
                read.setRGB(i, j, color.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void Lapl(){

        int ancho=read.getWidth();
        int alto=read.getHeight();
        
        int[][] MA= new int[ancho][alto];
        int[][] MA2= new int[ancho][alto];

        for(int i=0;i<read.getWidth();i++){
            for(int j=0; j<read.getHeight();j++){
                Color c= new Color(read.getRGB(i, j));
                int rc=c.getRed();
                int gc=c.getGreen();
                int bc=c.getBlue();
                int prom=(rc+gc+bc)/3;
                MA[i][j]=prom;
            }
        }
        for(int i=1;i<read.getWidth()-1;i++){
            for(int j=1;j<read.getHeight()-1;j++){
                int prom=MA[i][j]*8-MA[i-1][j]-MA[i+1][j]-MA[i][j-1]-MA[i][j+1]-MA[i-1][j-1]-MA[i+1][j+1]-MA[i-1][j+1]-MA[i+1][j-1];
                if(prom>255){
                    prom=255;
                }else if(prom<0){
                    prom=0;
                }
                MA2[i][j]=prom;
            }
        }
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color c= new Color(MA2[i][j], MA2[i][j],MA2[i][j]);
                read.setRGB(i, j, c.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
        

    }
    public void Prew(){
        int ancho=read.getWidth();
        int alto=read.getHeight();
        
        int[][] MA= new int[ancho][alto];
        
        int[][] filterX = {
            { -1, 0, 1 },
            { -1, 0, 1 },
            { -1, 0, 1 }
          };
        int[][] filterY = {
            { -1, -1, -1 },
            { 0, 0, 0 },
            { 1, 1, 1 }
        };
        
        
        for(int i=0;i<read.getWidth();i++){
            for(int j=0; j<read.getHeight();j++){
                Color c= new Color(read.getRGB(i, j));
                MA[i][j]=c.getRed();
            }
        }
        for(int i=0;i<read.getWidth()-2;i++){
            for(int j=0;j<read.getHeight()-2;j++){

                int px=(((MA[i][j] * filterX[0][0]) + (MA[i + 1][j] * filterX[0][1]) + (MA[i + 2][j] * filterX[0][2]) +
                (MA[i][j + 1] * filterX[1][0]) + (MA[i + 1][j + 1] * filterX[1][1]) + (MA[i + 2][j + 1] * filterX[1][2]) +
                (MA[i][j + 2] * filterX[2][0]) + (MA[i + 1][j + 2] * filterX[2][1]) + (MA[i + 2][j + 2] * filterX[2][2])));

                int py=(((MA[i][j] * filterY[0][0]) + (MA[i + 1][j] * filterY[0][1]) + (MA[i + 2][j] * filterY[0][2]) +
                (MA[i][j + 1] * filterY[1][0]) + (MA[i + 1][j + 1] * filterY[1][1]) + (MA[i + 2][j + 1] * filterY[1][2]) +
                (MA[i][j + 2] * filterY[2][0]) + (MA[i + 1][j + 2] * filterY[2][1]) + (MA[i + 2][j + 2] * filterY[2][2])));

                int p=(int) Math.sqrt((px*px)/9+(py*py)/9);

                if(p<0){
                    MA[i][j]=0;   
                }else if(p>255){
                    MA[i][j]=255;
                }else{
                    MA[i][j]=p;
                }
            }
        }
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color c= new Color(MA[i][j], MA[i][j],MA[i][j]);
                read.setRGB(i, j, c.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
        
    }
    public void Robe(){
        int ancho=read.getWidth();
        int alto=read.getHeight();
        
        int[][] MA= new int[ancho][alto];
        int[][] filterX = {
            { 1, 0 },
            { 0, -1 }
          };
          int[][] filterY = {
            { 0, 1 },
            { -1, 0 }
          };



        for(int i=0;i<read.getWidth();i++){
            for(int j=0; j<read.getHeight();j++){
                Color c= new Color(read.getRGB(i, j));
                MA[i][j]=c.getRed();
            }
        }
        for(int i=0;i<read.getWidth()-2;i++){
            for(int j=0;j<read.getHeight()-2;j++){

                int px=(MA[i][j] * filterX[0][0]) + (MA[i + 1][j] * filterX[1][0])+
                (MA[i][j + 1] * filterX[0][1]) + (MA[i + 1][j + 1] * filterX[1][1]);

                int py=(MA[i][j] * filterY[0][0]) + (MA[i + 1][j] * filterY[1][0])+
                (MA[i][j + 1] * filterY[0][1]) + (MA[i + 1][j + 1] * filterY[1][1]);

                int p=(int) Math.sqrt(px*px+py*py);

                if(p<0){
                    MA[i][j]=0;   
                }else if(p>255){
                    MA[i][j]=255;
                }else{
                    MA[i][j]=p;
                }
            }
        }
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color c= new Color(MA[i][j], MA[i][j],MA[i][j]);
                read.setRGB(i, j, c.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    public void Sob(){
        int ancho=read.getWidth();
        int alto=read.getHeight();
        
        int[][] MA= new int[ancho][alto];
        int[][] filterX = {
            { -1, 0, 1 },
            { -2, 0, 2 },
            { -1, 0, 1 }
          };
          int[][] filterY = {
            { 1, 2, 1 },
            { 0, 0, 0 },
            { -1, -2, -1 }
          };



        for(int i=0;i<read.getWidth();i++){
            for(int j=0; j<read.getHeight();j++){
                Color c= new Color(read.getRGB(i, j));
                MA[i][j]=c.getRed();
            }
        }
        for(int i=0;i<read.getWidth()-2;i++){
            for(int j=0;j<read.getHeight()-2;j++){

                int px=(MA[i][j] * filterX[0][0]) + (MA[i + 1][j] * filterX[0][1]) + (MA[i + 2][j] * filterX[0][2]) +
                (MA[i][j + 1] * filterX[1][0]) + (MA[i + 1][j + 1] * filterX[1][1]) + (MA[i + 2][j + 1] * filterX[1][2]) +
                (MA[i][j + 2] * filterX[2][0]) + (MA[i + 1][j + 2] * filterX[2][1]) + (MA[i + 2][j + 2] * filterX[2][2]);

                int py=(MA[i][j] * filterY[0][0]) + (MA[i + 1][j] * filterY[0][1]) + (MA[i + 2][j] * filterY[0][2]) +
                (MA[i][j + 1] * filterY[1][0]) + (MA[i + 1][j + 1] * filterY[1][1]) + (MA[i + 2][j + 1] * filterY[1][2]) +
                (MA[i][j + 2] * filterY[2][0]) + (MA[i + 1][j + 2] * filterY[2][1]) + (MA[i + 2][j + 2] * filterY[2][2]);

                int p=(int) Math.sqrt(px*px+py*py);

                if(p<0){
                    MA[i][j]=0;   
                }else if(p>255){
                    MA[i][j]=255;
                }else{
                    MA[i][j]=p;
                }
            }
        }
        for(int i=0;i<read.getWidth();i++){
            for(int j=0;j<read.getHeight();j++){
                Color c= new Color(MA[i][j], MA[i][j],MA[i][j]);
                read.setRGB(i, j, c.getRGB());
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }
    
    public void Mirror()
    {
        for (int j = 0; j < read.getHeight(); j++) {
            int l = 0, r = read.getWidth()-1;
            while (l < r) {
                int pl = read.getRGB(l, j);
                int pr = read.getRGB(r, j);

                read.setRGB(l, j, pr);
                read.setRGB(r, j, pl);

                l++;
                r--;
            }
        }
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }

    private void Blur(){

        BufferedImage buff2 = new BufferedImage(read.getWidth(), read.getHeight(), BufferedImage.TYPE_INT_RGB);
        for (int i = 0; i < image.getWidth(); i++) {
            for (int j = 0; j < image.getHeight(); j++) {
                int r = 0;
                int g = 0;
                int b = 0;
                int cont = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (i + k >= 0 && i + k < read.getWidth() && j + l >= 0 && j + l < read.getHeight()) {
                            Color c = new Color(read.getRGB(i + k, j + l));
                            r += c.getRed();
                            g += c.getGreen();
                            b += c.getBlue();
                            cont++;
                        }
                    }
                }
                r /= cont;
                g /= cont;
                b /= cont;
                Color c2 = new Color(r, g, b);
                buff2.setRGB(i, j, c2.getRGB());
            }
        }
        read=buff2;
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);

    }

    public void Rotar(){
        
        BufferedImage buff2 = new BufferedImage(read.getHeight(), read.getWidth(), BufferedImage.TYPE_INT_RGB);
        for (int i = 0; i < read.getWidth(); i++) {
            for (int j = 0; j < read.getHeight(); j++) {
                Color c = new Color(read.getRGB(i, j));
                buff2.setRGB(j, read.getWidth()-i - 1,   c.getRGB());

            }
        }
        read=buff2;
        ImageIcon icon= new ImageIcon(read);
        image.setIcon(icon);
    }

   
    private BufferedImage read;

    public void actionPerformed(ActionEvent e){
        
            
        if(e.getSource()==abrir){
            if(fileChooser.showOpenDialog(null)==JFileChooser.APPROVE_OPTION){
                file = fileChooser.getSelectedFile();
                if(file.canRead()){
                    try {
                        read=ImageIO.read(file);
                    } catch (IOException e1) {
                        // TODO Auto-generated catch block
                        e1.printStackTrace();
                    }
                    //String path= file.getAbsolutePath();
                    //imageo= new ImageIcon(path);
                    //image=new JLabel(imageo);
                    bytesImg=AbrirImagen(file);
                    image.setIcon( new ImageIcon(bytesImg));
                    setSize(read.getWidth(),read.getHeight());

                    //image.setIcon(new ImageIcon(path)); //agrega la imagen
                }

                
            }
        }else if(e.getSource()==original){
            Original();
        }else if(e.getSource()==save){
            Save();
        }else if(e.getSource()==exit)
        {
            dispose();
        }
        else if(e.getSource()==gray){
            GrayScale();
        }else if(e.getSource()==negative){
            Negative();            
        }else if(e.getSource()==binary){
            Bina();
        }else if(e.getSource()==claro){
            Brightness();
        }else if(e.getSource()==obscuro){
           LessBrightness();
        }else if(e.getSource()==Lap){
            Lapl();
        }else if(e.getSource()==Pre){
            Prew();
        }else if(e.getSource()==Rob){
            Robe();
        }else if(e.getSource()==Sob){
            Sob();
        }
        else if(e.getSource()==mirror){
            Mirror();
        }
        else if(e.getSource()==blur){
            Blur();
        }
        else if(e.getSource()==rotar){
            Rotar();
        }
       
        

        

        
        



    }

    public static void main(String args []){
        ImageChange_FINAL ic = new ImageChange_FINAL();
        ic.setDefaultCloseOperation(EXIT_ON_CLOSE);


    }


    
}