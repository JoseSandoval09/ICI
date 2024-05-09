import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.awt.image.*;
import javax.imageio.ImageIO;

public class beto extends JFrame {
    private JMenuBar arc;
    private JMenu uno, dos;
    private JMenuItem u1, u2, u3, u4, d1, d2, d3, d4, d5;
    private Container contents, contens2;
    private JLabel imagen;
    private Color mc[][];
    private BufferedImage bf;

    // Archivos
    FileInputStream entrada;
    FileOutputStream salida;
    JFileChooser seleccionado = new JFileChooser();
    File archivo;
    byte[] bytesImg;

    public beto() {
        super("Cheems PhotoShop");
        contents = getContentPane();
        contents.setLayout(new FlowLayout());

        contens2 = getContentPane();
        contens2.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));

        imagen = new JLabel();
        imagen.setLayout(new FlowLayout(FlowLayout.LEFT, 0, 0));
        PHandler phan = new PHandler();

        arc = new JMenuBar();
        uno = new JMenu("Archivo");
        uno.setLocation(2, 10);
        u1 = new JMenuItem("Abrir");
        u1.addActionListener(phan);
        u2 = new JMenuItem("Original");
        u2.addActionListener(phan);
        u3 = new JMenuItem("Guardar como");
        u3.addActionListener(phan);
        u4 = new JMenuItem("Salir");
        u4.addActionListener(phan);

        dos = new JMenu("Pre-procesamiento");
        dos.setLocation(2, 10);
        d1 = new JMenuItem("Negativo");
        d1.addActionListener(phan);
        d2 = new JMenuItem("Grises");
        d2.addActionListener(phan);
        d3 = new JMenuItem("Brillantar");
        d3.addActionListener(phan);
        d4 = new JMenuItem("Oscurecer");
        d4.addActionListener(phan);
        d5 = new JMenuItem("Binarizacion");
        d5.addActionListener(phan);

        contens2.add(arc);
        arc.add(uno);
        uno.add(u1);
        uno.add(u2);
        uno.add(u3);
        uno.add(u4);

        arc.add(dos);
        dos.add(d1);
        dos.add(d2);
        dos.add(d3);
        dos.add(d4);
        dos.add(d5);

        contents.add(imagen);
        setSize(500, 400);
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

    public String GuardarImagen(File archiov, byte[] bytesImg) {
        String respuesta = null;
        try {
            salida = new FileOutputStream(archiov);
            salida.write(bytesImg);
            respuesta = "Se guardo con exito la imagen";
        } catch (Exception e) {
        }
        return respuesta;
    }

    private class PHandler implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == u1) {
                if (seleccionado.showDialog(null, "Abrir") == JFileChooser.APPROVE_OPTION) {
                    archivo = seleccionado.getSelectedFile();
                    if (archivo.canRead()) {
                        if (archivo.getName().endsWith("jpg") || archivo.getName().endsWith("png")
                                || archivo.getName().endsWith("jpng")) {
                            try {
                                bf = ImageIO.read(archivo);
                            } catch (FileNotFoundException ex) {
                                System.out.println("No se encontro el archivo");
                            } catch (IOException ex) {
                                System.out.println("Error al leer el archivo");
                            }
                            bytesImg = AbrirImagen(archivo);
                            imagen.setIcon(new ImageIcon(bytesImg));
                            mc = new Color[bf.getWidth()][bf.getHeight()];
                            for (int i = 0; i < bf.getWidth(); i++) {
                                for (int j = 0; j < bf.getHeight(); j++) {
                                    mc[i][j] = new Color(bf.getRGB(i, j));
                                }
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "Por favor seleccione un archivo de imagen");
                        }
                    }
                }
            } else if (e.getSource() == u2) { // Abrir original
                imagen.setIcon(new ImageIcon(bytesImg));
            } else if (e.getSource() == u3) { // Guardar imagen modificada
                if (seleccionado.showDialog(null, "Guardar") == JFileChooser.APPROVE_OPTION) {
                    archivo = seleccionado.getSelectedFile();
                    if (archivo.getName().endsWith("jpg") || archivo.getName().endsWith("png")
                            || archivo.getName().endsWith("jpng")) {
                        String respuesta = GuardarImagen(archivo, bytesImg);
                        if (respuesta != null) {
                            JOptionPane.showMessageDialog(null, respuesta);
                        } else {
                            JOptionPane.showMessageDialog(null, "Error al guardar");
                        }
                    } else {
                        JOptionPane.showMessageDialog(null, "El formato de archivo no es compatible");
                    }
                }
            } else if (e.getSource() == u4) { // Salir
                System.exit(0);
            } else if (e.getSource() == d1) { // Negativo
                for (int i = 0; i < bf.getWidth(); i++) {
                    for (int j = 0; j < bf.getHeight(); j++) {
                        int r = 255 - mc[i][j].getRed();
                        int g = 255 - mc[i][j].getGreen();
                        int b = 255 - mc[i][j].getBlue();
                        Color c = new Color(r, g, b);
                        bf.setRGB(i, j, c.getRGB());
                    }
                }
                imagen.setIcon(new ImageIcon(bf));
            } else if (e.getSource() == d2) { // Grises
                for (int i = 0; i < bf.getWidth(); i++) {
                    for (int j = 0; j < bf.getHeight(); j++) {
                        int r = mc[i][j].getRed();
                        int g = mc[i][j].getGreen();
                        int b = mc[i][j].getBlue();
                        int prom = (r + g + b) / 3;
                        Color c = new Color(prom, prom, prom);
                        bf.setRGB(i, j, c.getRGB());
                    }
                }
                imagen.setIcon(new ImageIcon(bf));
            } else if (e.getSource() == d3) { // Brillantar
                for (int i = 0; i < bf.getWidth(); i++) {
                    for (int j = 0; j < bf.getHeight(); j++) {
                        int r = mc[i][j].getRed();
                        int g = mc[i][j].getGreen();
                        int b = mc[i][j].getBlue();
                        int prom = (r + g + b) / 3;
                        if (prom > 127) {
                            r = r + 50;
                            g = g + 50;
                            b = b + 50;
                        } else {
                            r = r - 50;
                            g = g - 50;
                            b = b - 50;
                        }
                        Color c = new Color(r, g, b);
                        bf.setRGB(i, j, c.getRGB());
                    }
                }
                imagen.setIcon(new ImageIcon(bf));
            } else if (e.getSource() == d4) { // Se modifica la imagen para que sea mas oscura
                for (int i = 0; i < bf.getWidth(); i++) {
                    for (int j = 0; j < bf.getHeight(); j++) {
                        int r = mc[i][j].getRed();
                        int g = mc[i][j].getGreen();
                        int b = mc[i][j].getBlue();
                        int prom = (r + g + b) / 3;
                        if (prom > 0) {
                            prom = prom - 10;
                        }
                        Color c = new Color(prom, prom, prom);
                        bf.setRGB(i, j, c.getRGB());
                    }
                }
                imagen.setIcon(new ImageIcon(bf));
            } else if (e.getSource() == d5) { // Se modifica la imagen para que sea binarizada
                for (int i = 0; i < bf.getWidth(); i++) {
                    for (int j = 0; j < bf.getHeight(); j++) {
                        int r = mc[i][j].getRed();
                        int g = mc[i][j].getGreen();
                        int b = mc[i][j].getBlue();
                        int prom = (r + g + b) / 3;
                        if (prom > 127) {
                            prom = 255;
                        } else {
                            prom = 0;
                        }
                        Color c = new Color(prom, prom, prom);
                        bf.setRGB(i, j, c.getRGB());
                    }
                }
                imagen.setIcon(new ImageIcon(bf));
            }
        }
    }
    public static void main(String args[]) {
        beto bm = new beto();
        bm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
