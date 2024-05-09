using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A13_MATRICES_GATO
{
    public partial class Form1 : Form
    {

        int index = -1;

        Button[,] boton = new Button[3,3];
        int x = 0;
        int y = 0;
        int width;
        int heigth;

        public Form1()
        {
            InitializeComponent();
            boton[0, 0] = new Button();
            for (int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    boton[i, j] = new Button();
                    this.Controls.Add(boton[i, j]);
                    boton[i, j].Width = 100;
                    boton[i, j].Height = 100;
                    boton[i, j].Location = new Point(x,y);
                    boton[i, j].BackColor = Color.FromArgb(100, 100, 100);
                    boton[i, j].Text = i.ToString() + " " + j.ToString();
                    x += 100;
                    boton[i, j].Click += new System.EventHandler(this.button_clicked); 
                }
                y += 100;
                x = 0;
            }
        }


        private void button_clicked(object sender, EventArgs e)
        {
            Button clickd = sender as Button;
            string index2;

            if (clickd.BackColor != Color.FromArgb(200, 200, 200) && clickd.BackColor != Color.FromArgb(255, 255, 255))
            {
                if (index % 2 == 0)
                {
                    clickd.BackColor = Color.FromArgb(200, 200, 200);
                    index++;
                    index2 = Convert.ToString(index % 2 + 1);
                }
                else
                {
                    clickd.BackColor = Color.FromArgb(255, 255, 255);
                    index++;
                    index2 = Convert.ToString(index % 2 + 1);

                }
                if(boton[0,0].BackColor == boton[1,1].BackColor && boton[0,0].BackColor==boton[2,2].BackColor && boton[0,0].BackColor!= Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[0, 2].BackColor == boton[1, 1].BackColor && boton[0, 2].BackColor == boton[2, 0].BackColor && boton[0, 2].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[0, 0].BackColor == boton[1, 0].BackColor && boton[0, 0].BackColor == boton[2, 0].BackColor && boton[0, 0].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[0, 0].BackColor == boton[0, 1].BackColor && boton[0, 0].BackColor == boton[0, 2].BackColor && boton[0, 0].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[0, 1].BackColor == boton[1, 1].BackColor && boton[0, 1].BackColor == boton[2, 1].BackColor && boton[0, 1].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[0, 2].BackColor == boton[1, 2].BackColor && boton[0, 2].BackColor == boton[2, 1].BackColor && boton[0, 2].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[1, 0].BackColor == boton[1, 1].BackColor && boton[1, 0].BackColor == boton[1, 2].BackColor && boton[1, 0].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
                if (boton[2, 0].BackColor == boton[2, 1].BackColor && boton[2, 0].BackColor == boton[2, 2].BackColor && boton[2, 0].BackColor != Color.FromArgb(100, 100, 100))
                {
                    MessageBox.Show("GANO EL USUARIO " + index2);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
    }
}
