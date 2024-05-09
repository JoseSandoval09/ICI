using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EjercicioFuncion
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float y, x;
            x = Single.Parse(Valor.Text);
            y = (5 * (x * x)) - (3 * x) + 2;
            Resultado.Text = y.ToString();



        }
    }
}
