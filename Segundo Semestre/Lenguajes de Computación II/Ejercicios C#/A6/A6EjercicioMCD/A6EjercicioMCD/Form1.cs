using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A6EjercicioMCD
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void MCD_Click(object sender, EventArgs e)
        {
            int n1, n2,mcd;

            n1 = Convert.ToInt32(Num1.Text);
            n2 = Convert.ToInt32(Num2.Text);

            while (n1 % n2 != 0)
            {
                mcd = n1 % n2;
                n1 = n2;
                n2 = mcd;


            }

            MaximoComunDivisor.Text = "El MCD es: " + Convert.ToString(n2);



        }
    }
}
