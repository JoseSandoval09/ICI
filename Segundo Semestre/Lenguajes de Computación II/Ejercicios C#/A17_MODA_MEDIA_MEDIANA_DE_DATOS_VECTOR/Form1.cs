using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A17_MODA_DE_DATOS_VECTOR
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public static int[] valor = new int[15];
        public static int[] repetidos = new int[15];
        int valores = -1, i = 0, j = 0,cont = 0,mediana=0,moda,repet=1;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            label2.Text = "Valores introducidos";
            label4.Text = "Valores ordenados";
            label6.Text = "Valores repetidos";
            label7.Text = "Repeticiones";
            valores = -1;
            cont = 0;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            int cont1 = 0, cont2 = 0;
            

            for(int i = 0; i < valores; i++)
            {
                for(int j = i + 1; j < valores; j++)
                {
                    if (valor[i] == valor[j])
                    {
                        cont1++;
                        
                    }
                }
                if (cont1 > cont2)
                {
                    cont2 = cont1;
                    moda = valor[i];
                    
                }

                cont1 = 0;
                
            }
            label9.Text = "La moda es: " + moda.ToString();

            
            for(int i = 0; i < valores; i++)
            {
                for(int j = i + 1; j < valores; j++)
                {
                    if (valor[i] == valor[j])
                    {
                        repetidos[i] = valor[i];
                        label6.Text += "\n" + repetidos[i].ToString();

                    }

                }          
                
            }
            

            for (int i = 1; i <= valores; i++)
            {
                if (valor[i] == valor[i - 1])
                {
                    repet++;
                }
                else
                {
                    if (repet > moda)
                    {
                        moda = repet;
                    }
                    label7.Text += "\n" + repet.ToString();
                    repet = 1;
                }
                
            }

            if (valor[valores] == valor[valores - 1])
            {
                if (repet > moda)
                {
                    moda = repet;
                }
                label7.Text += "\n" + repet.ToString();
            }




           
        }

        float media, auxm;


        private void button5_Click(object sender, EventArgs e)
        {
            if (valores%2==0)
            {
                mediana = valor[6];
                label9.Text = label9.Text + "\n" + "La mediana es: " + mediana.ToString();
            }
            else
            {
                mediana = valor[6];
                label9.Text = label9.Text + "\n" + "La mediana es: " + mediana.ToString();
            }


        }

        private void button4_Click(object sender, EventArgs e)
        {
            for (i = 0; i <= valores; i++)
            {
                auxm= auxm + valor[i];
            }
            media = auxm / 2;

            label9.Text = label9.Text + "\n" + "La media es: " + media.ToString();


        }

        private void button2_Click(object sender, EventArgs e)
        {
            //METODO DE BURBUJA  PARA ORDENAR 
            for (i = 0; i < valores; i++)
            {
                for (j = i + 1; j <= valores; j++)
                {
                    if (valor[j] <= valor[i])
                    {
                        int may = valor[j];
                        valor[j] = valor[i];
                        valor[i] = may;
                    }
                }
            }

            for (i = 0; i <= valores; i++)
            {
                label4.Text += "\n" + valor[i].ToString();

            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int x;
            valores++;
            cont++;
            if (valores < 15)
            {
                x = Convert.ToInt32(textBox1.Text);
                valor[valores] = x;
                label2.Text = label2.Text + "\n" + cont.ToString() + "---->" + x.ToString();
                textBox1.Clear();
            }

        }
    }
}
