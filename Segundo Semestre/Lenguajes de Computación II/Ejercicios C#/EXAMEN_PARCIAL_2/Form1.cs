using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EXAMEN_PARCIAL_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        double valor = 0, valor2 = 0, cont = 1;
        double resultado;
        string operador;


        //Indicaciones a los botones 
        private void cero_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "0";
            }
        }

        private void uno_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "1";
            }
        }

        private void dos_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "2";
            }
        }

        private void tres_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "3";
            }
           
        }

        private void cuatro_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "4";
            }
        }

        private void cinco_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "5";
            }
        }

        private void seis_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "6";
            }
        }

        private void siete_Click(object sender, EventArgs e)
        {

            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            { 
                Resu.Text += "7";
            }

        }

        private void ocho_Click(object sender, EventArgs e)
        {

            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "8";
            }

        }

        private void nueve_Click(object sender, EventArgs e)
        {

            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                Resu.Text += "9";
            }

        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            Resu.Text += ".";
        }

        private void suma_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                NumIngre.Text = Resu.Text;
                operador = "+";
                valor = double.Parse(Resu.Text);
                Resu.Clear();
            }
        }

        private void multiplicacion_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                NumIngre.Text = Resu.Text;
                operador = "x";
                valor = double.Parse(Resu.Text);
                Resu.Clear();
            }
        }

        private void resta_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                NumIngre.Text = Resu.Text;
                operador = "-";
                valor = double.Parse(Resu.Text);
                Resu.Clear();
            }
        }

        private void division_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                NumIngre.Text = Resu.Text;
                operador = "/";
                valor = double.Parse(Resu.Text);
                Resu.Clear();
            }
        }

        private void button20_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                NumIngre.Text = Resu.Text;
                operador = "%";
                valor = double.Parse(Resu.Text);
                Resu.Clear();
            }
        }

        private void borrarValor_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                if (Resu.Text.Length >= 1)
                {
                    string aux = Resu.Text;
                    aux = aux.Substring(0, aux.Count() - 1);
                    Resu.Text = aux;
                }
            }
        }

        private void limpiarResu_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {

                Resu.Clear();
            }
        }

        private void igual_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                valor2 = double.Parse(Resu.Text);
                switch (operador)
                {
                    case "+":
                        {
                            Sumar(valor, valor2);
                            break;
                        }
                    case "x":
                        {
                            Multiplicar(valor, valor2);
                            break;
                        }
                    case "-":
                        {
                            Restar(valor, valor2);
                            break;
                        }
                    case "/":
                        {
                            Dividir(valor, valor2);
                            break;
                        }
                    case "%":
                        {
                            Division2(valor, valor2);
                            break;
                        }
                }
                NumIngre.Text = Resu.Text;
            }
        }

        private void factorial_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                valor = double.Parse(Resu.Text);
                Factorial(valor);
            }
        }

        //FUNCIONES DE OPERACIONES
        void Sumar(double n1,double n2)
        {
            resultado = n1 + n2;
            Resu.Clear();
            Resu.Text = resultado.ToString();
        }
        void Restar(double n1,double n2)
        {
            resultado = n1 - n2;
            Resu.Clear();
            Resu.Text = resultado.ToString();
        }
        void Multiplicar(double n1, double n2)
        {
            resultado = n1 * n2;
            Resu.Clear();
            Resu.Text = resultado.ToString();
        }
        void Factorial(double n1)
        {
            int i;
            double fact = 1;
            double x = Convert.ToDouble(n1);
            for (i = 1; i <= x; i++)
            {
                fact *= i;
            }
            Resu.Text = fact.ToString();
        }
        void Dividir(double n1,double n2)
        {
            resultado = n1 / n2;
            Resu.Clear();
            Resu.Text = resultado.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            
            if (cont%2 == 0)
            {
                button2.BackColor = Color.IndianRed;
                button2.Text = "OFF";
                cont++;

            }
            else if(cont%2!=0)
            {
                button2.BackColor = Color.SpringGreen;
                button2.Text = "ON";
                cont++;
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (button2.BackColor == Color.IndianRed)
            {
                MessageBox.Show("LA CALCULADORA ESTA EN OFF");
            }
            else
            {
                int valor = int.Parse(Resu.Text);
                Sumatoria(valor);
            }
        }

        void Division2(double n1, double n2)
        {
            resultado = n1 / n2;
            Resu.Clear();
            Resu.Text = resultado.ToString();
        }

        void Sumatoria(int n1)
        {
            int x,sum=0;
            x = n1;
            for(int i = 1; i <= x; i++)
            {
                sum += i;
            }

            Resu.Text = sum.ToString();
        }

    }
}
