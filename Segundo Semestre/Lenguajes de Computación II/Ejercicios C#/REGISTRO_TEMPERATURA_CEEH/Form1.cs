using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace REGISTRO_TEMPERATURA_CEEH
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //VARIABLES A UTILIZAR
        public static int[] tempe = new int[10];
        int tope = -1, i = 0;


        //BOTON PARA DESPLEGAR DATOS
        private void button2_Click(object sender, EventArgs e)
        {

            //MUESTRA DE VALORES
            for (i = 0; i <= tope; i++)
            {
                TEMP.Text += tempe[i].ToString() + "°C" + "\n";
            }
           
            

            //CREACION DE FECHAS 
            if (Dia.Text.Length!=0 && Mes.Text.Length !=0 && Año.Text.Length!= 0)
            {
                int DD, MM, YYYY;
                DD = int.Parse(Dia.Text);
                MM = int.Parse(Mes.Text);
                YYYY = int.Parse(Año.Text);
                var date = new DateTime(YYYY, MM, DD);
                FDR.Text += date.ToString("d");

                for (i = 1; i < 10; i++)
                {
                    date = date.AddDays(1);
                    FDR.Text += "\n" + date.ToString("d");
                }
            }

            

        }

        private void button4_Click(object sender, EventArgs e)
        {

            moda.Text = "La moda es: ";
            Modaaaaa();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            TEMP.Text = "";
            FDR.Text = "";
            textBox1.Clear();
            Dia.Clear();
            Mes.Clear();
            Año.Clear();
            tope = -1;

            for (i = 0; i < 10; i++)
            {
                tempe[i] = 0;
            }

            moda.Text = "La moda es: ";
        }

        //FUNCION MODA
        public void Modaaaaa()
        {
            //SACAR MODA 
            int frioC = 1, nubladoC = 1, calorC = 1, tropicalC = 1;

            for (i = 0; i < 10; i++)
            {
                if (tempe[i] < 10)
                {
                    frioC++;
                }
                else if (tempe[i] >= 10 && tempe[i] <= 20)
                {
                    nubladoC++;
                }
                else if (tempe[i] > 20 && tempe[i] <= 30)
                {
                    calorC++;
                }
                else if (tempe[i] > 30)
                {
                    tropicalC++;
                }
            }

            //CONDICIONALES PARA MODO
            if (frioC > nubladoC && frioC > calorC && frioC > tropicalC && calorC != 0 && tropicalC != 0 && nubladoC != 0)
            {
                moda.Text += "Clima frío";

            }
            if (nubladoC > frioC && nubladoC > calorC && nubladoC > tropicalC && calorC != 0 && tropicalC != 0 && frioC != 0)
            {
                moda.Text += "Clima Nublado";

            }
            if (calorC > frioC && calorC > nubladoC && calorC > tropicalC && frioC != 0 && tropicalC != 0 && nubladoC != 0)
            {
                moda.Text += "Clima calor";

            }
            if (tropicalC > frioC && tropicalC > calorC && tropicalC > nubladoC && calorC != 0 && frioC != 0 && nubladoC != 0)
            {
                moda.Text += "Clima tropical";

            }
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        //BOTON REGISTRO DE TEMPERATURAS
        private void button1_Click(object sender, EventArgs e)
        {
            int c;
            tope++;
            if (tope < 10)
            {
                c = Convert.ToInt32(textBox1.Text);
                tempe[tope] = c;
                textBox1.Clear();
            }
            if (tope >= 9)
            {
                MessageBox.Show("LIMITE DE 10 VALORES");
            }
        }
    }
}
