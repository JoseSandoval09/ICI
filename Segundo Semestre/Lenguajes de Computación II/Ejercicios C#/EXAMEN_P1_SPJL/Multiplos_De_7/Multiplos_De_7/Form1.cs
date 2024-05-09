using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Multiplos_De_7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public static int[] valores = new int[40];
        public static int lim = 0;

        private void button1_Click(object sender, EventArgs e)
        {

            int n;
            n = Convert.ToInt32(Valores.Text);
            valores[lim] = n;
            lim++;
            Valores.Text = " ";

            if (lim == 40)
            {
                MessageBox.Show("YA HAS INTRODUCIDO LOS 40 VALORES");

            }


        }

        private void button2_Click(object sender, EventArgs e)
        {

            int m;

            //Ciclo for para agregar todos los valores del arreglo a los listbox correspondientes
            for (lim = 0; lim < 40; lim++)
            {
                //Agregando valores del arreglo al listbox donde estan todos los numeros
                Vector_40_Valores.Items.Add(Convert.ToString(valores[lim]));

                //Condicional para ver si el numero en la posicion n del arreglo es multiplo de 7 y se agrega al listbox
                if (valores[lim] % 7 == 0)
                {
                    m = valores[lim];
                    Multiplos_De_7.Items.Add(Convert.ToString(m));
                }
               

            }


        }

        private void button3_Click(object sender, EventArgs e)
        {
            //Limpiamos las listas para otra ejecucion del programa

            Vector_40_Valores.Items.Clear();
            Multiplos_De_7.Items.Clear();
            for (lim = 0; lim < 40; lim++)
            {
                valores[lim] = 0;
            }
            lim = 0;

        }
    }
}
