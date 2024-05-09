using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RECTANGULO_TRIANGULO_AREA
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public class Rectangulo
        {
            public float Area(float Base, float Altura)
            {
                float Area = 0;
                Area = Base * Altura;
                return Area;
            }
        }
        public class Triangulo: Rectangulo
        {
            public float Area(float Base, float Altura)
            {
                float Area = 0;
                Area = (Base * Altura) / 2;
                return Area;

            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(Baser.Text.Length!=0 && Altur.Text.Length!=0 && float.Parse(Baser.Text)!=0 && float.Parse(Altur.Text) != 0)
            {
                Rectangulo rec = new Rectangulo();
                float x = 0, y=0, z = 0;
                x = float.Parse(Baser.Text);
                y = float.Parse(Altur.Text);
                z = rec.Area(x, y);
                base_rectangulo.Text = "La base del rectangulo es: " + Convert.ToString(x) + "cm";
                altura_rectangulo.Text= "La altura del rectangulo es: " + Convert.ToString(y) + "cm";
                area_rectangulo.Text = "El area del rectangulo es: " + Convert.ToString(z) + "cm cuadrados";
            }
            else
            {
                MessageBox.Show("NO DEJES ESPACIOS VACIOS O INGRESES 0");
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Baser.Text = "";
            Altur.Text = "";
            base_rectangulo.Text = "";
            altura_rectangulo.Text = "";
            area_rectangulo.Text = "";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (Baset.Text.Length != 0 && Altut.Text.Length != 0 && float.Parse(Baset.Text) != 0 && float.Parse(Altut.Text) != 0)
            {
                Triangulo tri = new Triangulo();
                float x = 0, y = 0, z = 0;
                x = float.Parse(Baset.Text);
                y = float.Parse(Altut.Text);
                z = tri.Area(x, y);
                base_triangulo.Text = "La base del triangulo es: " + Convert.ToString(x);
                altura_triangulo.Text = "La altura del triangulo es: " + Convert.ToString(y);
                area_triangulo.Text = "El area del rectangulo es: " + Convert.ToString(z);
            }
            else
            {
                MessageBox.Show("NO DEJES ESPACIOS EN BLACO O INGRESES 0");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Baset.Text = "";
            Altut.Text = "";
            base_triangulo.Text = "";
            altura_triangulo.Text = "";
            area_triangulo.Text = "";
        }
    }
}
