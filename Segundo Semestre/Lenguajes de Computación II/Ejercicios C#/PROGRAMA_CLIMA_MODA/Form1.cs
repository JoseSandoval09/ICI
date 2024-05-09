using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PROGRAMA_CLIMA_MODA
{
    public partial class Form1 : Form
    {
        

        public static int[] temp = new int[5];
        int valores = -1, i = 0, j = 0, cont = 0, mediana = 0, moda=0;

        //ORDENAR CLIMAS 
        private void button3_Click(object sender, EventArgs e)
        {
            for (i = 0; i < valores; i++)
            {
                for (j = i + 1; j <= valores; j++)
                {
                    if (temp[j] < temp[i])
                    {
                        int may = temp[j];
                        temp[j] = temp[i];
                        temp[i] = may;
                    }
                }
            }

            for(i=0; i <= valores; i++)
            {
                OR.Text += temp[i].ToString();
            }
        }



        //CAPTURA DE CLIMAS EN VECTOR

        private void button1_Click(object sender, EventArgs e)
        {
            int x;
            valores++;
            if (valores < 5)
            {
                x = Convert.ToInt32(textBox1.Text);
                temp[valores] = x;
                SO.Text+= x.ToString() + "\n";
                textBox1.Clear();

            }
            if (valores == 5)
            {
                MessageBox.Show("ALCANZASTE EL LIMITE");
            }

           

        }
    }
}
