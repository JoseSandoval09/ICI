using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SerieFibonacci
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        public int Serie(int n)
        {
            int res = 0;
            if(n==0 || n == 1)
            {
                res = n;
            }
            else
            {
                res = Serie(n - 1) + Serie(n - 2);
            }

            return res;

        }

        


        private void button2_Click(object sender, EventArgs e)
        {
            int tope = Convert.ToInt32(textBox1.Text);
            if (tope > 15)
            {
                MessageBox.Show("El tope es de 15 sumas");
                textBox1.Clear();
            }
            else
            {
                for (int i = 0; i <= tope; i++)
                {
                    label3.Text = label3.Text + Serie(i).ToString() + " ,";
                }
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label3.Text = "Serie Fibonacci: ";
            textBox1.Clear();
        }
    }
}
