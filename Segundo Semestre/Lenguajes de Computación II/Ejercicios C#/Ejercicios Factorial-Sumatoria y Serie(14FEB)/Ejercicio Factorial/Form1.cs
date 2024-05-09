using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio_Factorial
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = "RESULTADO DEL FACTORIAL: ";
            int i, fact = 1, x;
            x = Convert.ToInt32(num.Text);
            for (i = 1; i <= x; i++)
            {
                fact *= i;
            }

            label2.Text= label2.Text + "" + fact.ToString();



        }

        private void button2_Click(object sender, EventArgs e)
        {
            label2.Text = "RESULTADO DEL LA SUMATORIA: ";
            int i, sum = 0, x;
            x = Convert.ToInt32(num.Text);
            for (i = 1; i <= x; i++)
            {
                sum += i;
            }

            label2.Text = label2.Text + "" + sum.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label2.Text = "RESULTADO DE LA SERIE ";
            int i, pares = 0, x = 0;
            x = Convert.ToInt32(num.Text);

            for (i = 0; i <= x; i++)
            {

                if (i % 2 == 0)
                {
                    pares += i;
                }


            }

            label2.Text = label2.Text + "SUMA DE PARES " + pares.ToString();

        }
    }
}
