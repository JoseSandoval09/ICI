using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A6Rombo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int x, r, f, a, esp;
            x = Convert.ToInt32(imp.Text);
            if (x % 2 == 0)
            {
                MessageBox.Show("Tu valor es par, ingresa un valor impar ");
            }
            else
            {
                listBox1.Items.Clear();
                MessageBox.Show("Tu figura ya casi esta lista ");
                r = ((x - 1) / 2);
                int fin;
                String t;
                
                for (f = 0; f < r; f++)
                {
                    fin = r - f;
                   
                    t = " ";
                    for (esp = 0; esp < fin; esp++)
                    {
                        t = t + "   ";
                    }

                    fin = (f * 2) + 1;
                    
                    for (a = 0; a < fin; a++)
                    {
                        t = t + " * ";
                    }
                    listBox1.Items.Add(t);
                    fin = 0;
                }

               
                t = " ";
                for (a = 0; a < x; a++)
                {
                    t = t + " * ";
                }
                listBox1.Items.Add(t);

                
                for (f = 0; f < r; f++)
                {
                    fin = f + 1;
                   
                    t = " ";
                    for (esp = 0; esp < fin; esp++)
                    {
                        t = t + "   ";
                    }

                    fin = ((r - f) * 2) - 1;
                   
                    for (a = 0; a < fin; a++)
                    {
                        t = t + " * ";
                    }
                    listBox1.Items.Add(t);
                    fin = 0;
                }
            }

        }
    }
}
