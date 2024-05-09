using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BubbleMetodo_A16
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public static int[] valor = new int[5];
        int valores = -1, i = 0, j = 0, temp, cont = 0;

        private void button2_Click(object sender, EventArgs e)
        {
            //METODO DE BURBUJA
            for(i=0; i < valores; i++)
            {
                for (j = i + 1; j <= valores; j++)
                {
                    if (valor[j] < valor[i])
                    {
                        temp = valor[j];
                        valor[j] = valor[i];
                        valor[i] = temp;
                    }
                }
            }
            for (i = 0; i <= valores; i++)
            {
                if (valor[i] % 2 == 0)
                {
                    cadena = cadena + valor[i].ToString() + "\n";
                }
            }
            label3.Text = cadena;
        }

        String cadena = "Valores ordenados multiplos de 2 \n";


        private void button1_Click(object sender, EventArgs e)
        {
            int x;
            valores++;
            cont++;
            if (valores < 5)
            {
                x = Convert.ToInt32(textBox1.Text);
                valor[valores] = x;
                label2.Text = label2.Text + "\n" + cont.ToString() + "---> " + x.ToString();
                textBox1.Clear();
            }

        }
    }
}
