using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace REGISTRO_CLIMAS_SPJL
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public static int[] tmpa = new int[15];
        int tope = -1, i = 0;

        public void MODA()
        {
            int frioC = 1, nubladoC = 1, calorC = 1, tropicalC = 1;

            for (i = 0; i < 10; i++)
            {
                if (tmpa[i] < 10)
                {
                    frioC++;
                }
                else if (tmpa[i] >= 10 && tmpa[i] <= 20)
                {
                    nubladoC++;
                }
                else if (tmpa[i] > 20 && tmpa[i] <= 30)
                {
                    calorC++;
                }
                else if (tmpa[i] > 30)
                {
                    tropicalC++;
                }
            }

            //CONDICIONALES PARA MODO
            if (frioC > nubladoC && frioC > calorC && frioC > tropicalC && calorC != 0 && tropicalC != 0 && nubladoC != 0)
            {
                label12.Text += "Clima frío";

            }
            if (nubladoC > frioC && nubladoC > calorC && nubladoC > tropicalC && calorC != 0 && tropicalC != 0 && frioC != 0)
            {
                label12.Text += "Clima Nublado";

            }
            if (calorC > frioC && calorC > nubladoC && calorC > tropicalC && frioC != 0 && tropicalC != 0 && nubladoC != 0)
            {
                label12.Text += "Clima calor";

            }
            if (tropicalC > frioC && tropicalC > calorC && tropicalC > nubladoC && calorC != 0 && frioC != 0 && nubladoC != 0)
            {
                label12.Text += "Clima tropical";

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Impresion de valores
            for (i = 0; i <= tope; i++)
            {
                label4.Text += tmpa[i].ToString() + "°C " + "\n";
            }
            //IMPRESION DE FECHAS

            if(dia.Text.Length!=0 && mes.Text.Length!=0 && año.Text.Length != 0)
            {
                int diaa, mess, añoo;
                diaa = int.Parse(dia.Text);
                mess = int.Parse(mes.Text);
                añoo = int.Parse(año.Text);
                var fecha = new DateTime(añoo, mess, diaa);
                label11.Text += fecha.ToString("d");

                for (i = 1; i < 15; i++)
                {
                    fecha = fecha.AddDays(1);
                    label11.Text += "\n" + fecha.ToString("d");
                }

                MODA();

            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (i = 0; i < 15; i++)
            {
                tmpa[i] = 0;
            }
            label4.Text = "";
            label11.Text = "";
            dia.Clear();
            mes.Clear();
            año.Clear();
            tope = -1;
            label12.Text = "La moda es: ";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int tmp;
            tope++;
            if (tope < 15)
            {
                tmp = Convert.ToInt32(temperaturas.Text);
                tmpa[tope]=tmp;
                temperaturas.Clear();
            }
            if (tope>=14)
            {
                MessageBox.Show("Alcanzaste el limite");
            }
            
        }
    }
}
