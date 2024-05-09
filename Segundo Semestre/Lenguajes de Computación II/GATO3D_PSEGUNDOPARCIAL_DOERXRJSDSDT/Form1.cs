using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT
{
    
    public partial class Form1 : Form
    {
        int dimension_boton = 50;
        int padding = 10;
        public static Button[,,] boton = new Button[3, 3, 3];
        public static int index = 0;
        int x = 0;
        int y = 0;
        int l = 0;
        int height = 0;
        int width = 0;

        public Form1()
        {
            InitializeComponent();

            boton[0, 0, 0] = new Button();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        boton[i, j, k] = new Button();
                        this.Controls.Add(boton[i, j, k]);
                        boton[i, j, k].Width = dimension_boton;
                        boton[i, j, k].Height = dimension_boton;
                        boton[i, j, k].Location = new Point(x + l + padding, y + l + padding);
                        boton[i, j, k].BackColor = Color.FromArgb(100, 100, 100);
                        boton[i, j, k].BackgroundImage = ((System.Drawing.Image)(Properties.Resources.kimk));
                        boton[i, j, k].Text = "";
                        x += dimension_boton;
                        boton[i, j, k].Click += new System.EventHandler(this.button_Clicked);
                    }//fin for k
                    y += dimension_boton;
                    x = 0;
                }//fin for j
                l += dimension_boton * 3 + padding;
                y = 0;
            }//fin for i

            boton[1, 1, 1].BackColor = Color.FromArgb(0, 0, 0);
        }

        public static void limpiar()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        boton[i, j, k].BackColor = Color.FromArgb(100, 100, 100);
                        boton[i, j, k].BackgroundImage = ((System.Drawing.Image)(Properties.Resources.kimk));
                    }//fin for k
                }//fin for j
            }//fin for i

            boton[1, 1, 1].BackColor = Color.FromArgb(0, 0, 0);
            index = 0;
        }
        private void button_Clicked(object sender, EventArgs e)
        {
            Button clickd = sender as Button;
            
            if (index % 2 == 0 && clickd.BackColor==Color.FromArgb(100,100,100)) {
                clickd.BackColor = Color.FromArgb(1, 1, 1);
                clickd.BackgroundImage= ((System.Drawing.Image)(Properties.Resources.yethebest));
                index++;
            }
            else if(clickd.BackColor == Color.FromArgb(100, 100, 100))
            {
                clickd.BackColor = Color.FromArgb(255,255,255);
                clickd.BackgroundImage = ((System.Drawing.Image)(Properties.Resources.peteloser));
                index++;
            }

            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++)
                {
                    //Verticales
                    if (boton[i, 0, j].BackColor == boton[i, 1, j].BackColor && boton[i, 1, j].BackColor == boton[i, 2, j].BackColor && boton[i, 0, j].BackColor != Color.FromArgb(100, 100, 100))
                    {
                        if (boton[i, 0, j].BackColor == Color.FromArgb(1, 1, 1)) { MessageBox.Show("Ye gana!!!"); }
                        if (boton[i, 0, j].BackColor == Color.FromArgb(255, 255, 255)) { MessageBox.Show("Pete gana, bruh"); }
                        limpiar();
                        turno.Text = "YE VS PETE";
                    }
                    //Horizontales
                    if (boton[i, j, 0].BackColor == boton[i, j, 1].BackColor && boton[i, j, 1].BackColor == boton[i, j, 2].BackColor && boton[i, j, 0].BackColor != Color.FromArgb(100, 100, 100))
                    {
                        if (boton[i, j, 0].BackColor == Color.FromArgb(1, 1, 1)) { MessageBox.Show("Ye gana!!!"); }
                        if (boton[i, j, 0].BackColor == Color.FromArgb(255, 255, 255)) { MessageBox.Show("Pete gana, bruh"); }
                        limpiar();
                        turno.Text = "YE VS PETE";
                    }
                    
                }//fin for j

                    //Diagonales derecha
                    if (boton[i, 1, 1].BackColor == boton[i, 0, 0].BackColor && boton[i, 1, 1].BackColor == boton[i, 2, 2].BackColor && boton[i, 1, 1].BackColor != Color.FromArgb(100,100,100))
                    {
                        if (boton[i, 1, 1].BackColor == Color.FromArgb(1, 1, 1)) { MessageBox.Show("Ye gana!!!"); }
                        if (boton[i, 1, 1].BackColor == Color.FromArgb(255, 255, 255)) { MessageBox.Show("Pete gana, bruh"); }
                        limpiar();
                        turno.Text = "YE VS PETE";
                }
                //Diagonales izquierda
                    if (boton[i, 1, 1].BackColor == boton[i, 0, 2].BackColor && boton[i, 0, 2].BackColor == boton[i, 2, 0].BackColor && boton[i, 1, 1].BackColor != Color.FromArgb(100, 100, 100))
                    {
                        if (boton[i, 1, 1].BackColor == Color.FromArgb(1, 1, 1)) { MessageBox.Show("Ye gana!!!"); }
                        if (boton[i, 1, 1].BackColor == Color.FromArgb(255, 255, 255)) { MessageBox.Show("Pete gana, bruh"); }
                        limpiar();
                        turno.Text = "YE VS PETE";
                }
            }//fin for i
            

            turno.Text = "Turno Jugador " + (index % 2 + 1).ToString();
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void reiniciar_Click(object sender, EventArgs e)
        {
            limpiar();
            turno.Text = "YE VS PETE";
        }

        private void salir_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
