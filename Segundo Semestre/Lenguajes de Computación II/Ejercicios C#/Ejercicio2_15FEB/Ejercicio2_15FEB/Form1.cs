using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio2_15FEB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int cont, mul1, mul2, mul3, mul4, tabla;


            tabla = Convert.ToInt32(Num.Text);

            for (cont = 1; cont <= 15; cont++)
            {
                //multiplicaciones
                mul1 = tabla * cont;
                listBox1.Items.Add(tabla + " * " + cont + " = " + mul1);

                mul2 = tabla * (cont + 15);
                listBox2.Items.Add(tabla + " * " + (cont+15) + " = " + mul2);

                mul3 = tabla * (cont + 30);
                listBox3.Items.Add(tabla + " * " + (cont+30) + " = " + mul3);

                mul4 = tabla * (cont + 45);
                listBox4.Items.Add(tabla + " * " + (cont+45) + " = " + mul4);


            }
        }
    }
}
