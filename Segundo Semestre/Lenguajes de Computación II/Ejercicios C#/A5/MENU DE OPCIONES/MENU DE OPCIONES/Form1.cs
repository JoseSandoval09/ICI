using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MENU_DE_OPCIONES
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Cuadrado_Click(object sender, EventArgs e)
        {
            int  cuad,num;
            num= Convert.ToInt32(Numero.Text);
            cuad = num * num;
            Cuadrado.Text = "El cuadrado de tu numero es: " + Convert.ToString(cuad);


        }

        private void button1_Click(object sender, EventArgs e)
        {
            int  cub, num;
            num = Convert.ToInt32(Numero.Text);
            cub = num * num * num;
            Cubos.Text = "El cubo de tu numero es: " + Convert.ToString(cub);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int num;
            num = Convert.ToInt32(Numero.Text);
            if (num % 2 == 0)
            {
                ParImpar.Text = "Tu numero es par";
            }
            else
            {
                ParImpar.Text = "Tu numero es impar";
            }
            
        }
    }
}
