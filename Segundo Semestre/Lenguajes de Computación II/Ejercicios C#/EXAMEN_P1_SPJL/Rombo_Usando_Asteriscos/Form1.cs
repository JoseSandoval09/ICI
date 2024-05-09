using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Rombo_Usando_Asteriscos
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int a;
            a = Convert.ToInt32(Valor.Text);
            if(a%2==0 || a<0 || a>19)
            {
                MessageBox.Show("El numero es par o es menor a 0 o mayor a 19.\nIngresa un valor correcto");

            }
            else
            {
                int p = 1;
                listBox1.Items.Clear();
                for(int i = 1; i < (a / 2) + 1; i++)
                {
                    int x = 1;
                    string sup = "  \t   ";
                    do
                    {
                        sup += "    ";
                        x++;
                    } while ((a - p) / 2 >= x);

                    do
                    {
                        sup += "   *  "; x++;
                    } while ((a + p) / 2 >= x);
                    listBox1.Items.Add(sup);
                    listBox1.Items.Add("\t\n");
                    p+= 2;


                }
                string m = "  \t  ";
                for (int i = 1; i <= a; i++)
                {
                    m += "  *  ";
                }
                listBox1.Items.Add(m);
                listBox1.Items.Add("\t\n");
                for(int i = (a / 2); i > 0; i--)
                {
                    p -= 2;
                    string inf = "  \t  ";
                    int x = 1;
                    do
                    {
                        inf += "    "; x++;

                    } while ((a - p) / 2 >= x);
                    do
                    {
                        inf += "   *  "; x++;

                    } while ((a + p) / 2 >= x);
                    listBox1.Items.Add(inf);
                    listBox1.Items.Add("\n");


                }

            }




            

        }

        
    }
}
