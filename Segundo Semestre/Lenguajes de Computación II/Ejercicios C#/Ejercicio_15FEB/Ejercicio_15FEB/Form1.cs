using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio_15FEB
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

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int cont, tabla, mul, resta, suma;
            decimal div;

            tabla = Convert.ToInt32(Num.Text);

            for (cont = 1; cont <= 12; cont++)
            {
                //multiplicación 
                mul = tabla * cont;
                listBox1.Items.Add(tabla + " * " + cont + " = " + mul);
                //suma
                suma = tabla + cont;
                listBox2.Items.Add(tabla + " + " + cont + " = " + suma);
                //resta
                resta = tabla - cont;
                listBox3.Items.Add(tabla + " - " + cont + " = " + resta);
                //división
                div = tabla / cont;
                listBox4.Items.Add(tabla + " / " + cont + " = " + div);


            }


        }
    }
}
