using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VEC_24FEB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public bool Es_Entero (string h)
        {

            try
            {
                Int32.Parse(h);
                return true;
            }
            catch
            {
                return false;
            }

        }

        public static int[] precio = new int[5];
        public static int[] cantidad = new int[5];
        public static int total = 0;


        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();

            Random r = new Random();

            for (int i = 0; i < 5; i++)
            {
                precio[i] = r.Next(100, 1000);
                listBox1.Items.Add(precio[i].ToString());
                listBox1.Items.Add("\n");

            }

            MessageBox.Show("Todo listo");
        }

        private void button2_Click(object sender, EventArgs e)
        {

            string n = Articulos1.Text;

            if(n.Length==0 || (Es_Entero(n)==false )|| int.Parse(n) < 0)
            {
                Articulos1.Text = "0";
                cantidad[0] =0;
                MessageBox.Show("Ingresaste el dato mal");
            }
            else
            {
                cantidad[0] = Convert.ToInt32(n);
            }

            if (n.Length == 0 || (Es_Entero(n) == false) || int.Parse(n) < 0)
            {
                Articulos2.Text = "0";
                cantidad[1] = 0;
                MessageBox.Show("Ingresaste el dato mal");
            }
            else
            {
                cantidad[1] = Convert.ToInt32(n);
            }

            if (n.Length == 0 || (Es_Entero(n) == false) || int.Parse(n) < 0)
            {
                Articulos3.Text = "0";
                cantidad[2] = 0;
                MessageBox.Show("Ingresaste el dato mal");
            }
            else
            {
                cantidad[2] = Convert.ToInt32(n);
            }

            if (n.Length == 0 || (Es_Entero(n) == false) || int.Parse(n) < 0)
            {
                Articulos4.Text = "0";
                cantidad[3] = 0;
                MessageBox.Show("Ingresaste el dato mal");
            }
            else
            {
                cantidad[3] = Convert.ToInt32(n);
            }

            if (n.Length == 0 || (Es_Entero(n) == false) || int.Parse(n) < 0)
            {
                Articulos5.Text = "0";
                cantidad[4] = 0;
                MessageBox.Show("Ingresaste el dato mal");
            }
            else
            {
                cantidad[4] = Convert.ToInt32(n);
            }

            listBox2.Items.Clear();

            for(int i = 0; i < 5; i++)
            {
                int aux = cantidad[i] * precio[i];
                total += aux;
                listBox2.Items.Add(aux.ToString());
                listBox2.Items.Add("\n");
            }

            MessageBox.Show("TOTAL A PAGAR: " + total.ToString());

        }
    }
}
