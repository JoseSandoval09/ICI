using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A6nNumerosPares
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int N;
            N = Convert.ToInt32(Num.Text);
            if (N < 3 || N > 100)
            {
                MessageBox.Show("Debes asignar un valor entre 3-100 ");
            }
            else
            {
                MessageBox.Show("Imprimiendo lista ");
                ListaPares.Items.Clear();
                for (int x = 2; x <= N; x++)
                {
                    if (x % 2 == 0)
                    {
                        ListaPares.Items.Add(x.ToString());
                    }
                }
            }

        }
    }
}
