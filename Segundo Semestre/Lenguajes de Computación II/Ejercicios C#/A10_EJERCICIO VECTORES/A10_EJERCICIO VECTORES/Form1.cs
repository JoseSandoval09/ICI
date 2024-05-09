using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A10_EJERCICIO_VECTORES
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public static int[] numeros = new int[15];
        public static int lim = 0;


        private void button1_Click(object sender, EventArgs e)
        {
            int n;
            n = Convert.ToInt32(Val.Text);
            numeros[lim] = n;
            lim++;
            Val.Text = " ";

            if (lim == 15)
            {
                MessageBox.Show("VECTOR LLENO CON 15 VALORES");
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {

            int p, i;
            for (lim = 0; lim < 15; lim++)
            {
                listBox3.Items.Add(Convert.ToString(numeros[lim]));
                if (numeros[lim] % 2 == 0)
                {
                    p = numeros[lim];
                    listBox1.Items.Add(Convert.ToString(p));
                }
                else
                {
                    i = numeros[lim];
                    listBox2.Items.Add(Convert.ToString(i));
                }

            }




        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();
            for (lim = 0; lim <15; lim++) { numeros[lim] = 0; }
            lim = 0;

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }
    }
}
