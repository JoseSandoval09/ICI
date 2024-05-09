using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ARREGLOS_16FEB
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public static int[] edad = new int[10];
        public static int reng = 0;


        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            if (reng <= 4)
            {
                edad[reng] = System.Int32.Parse(Val.Text);
                reng++;
                Val.Text = " ";

            };
            if (reng == 10) { Val.Text = "Vector lleno con 10 datos"; };

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //LIMPAR LISTAS
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            //CARGANDO LISTA EDAD CAPTURADA
            for (reng = 0; reng <= 9; reng++)
            {
                listBox1.Items.Add (edad[reng].ToString());
            }
            //CALCULANDO MULTIPLICACION
            for (reng = 0; reng <= 9; reng++)
            {
                edad[reng] = edad[reng] * 10;
            }
            //DESPLEGANDO MULTIPLICACION CICLO FOREACH
            foreach(int r in edad)
            {
                listBox2.Items.Add(r.ToString());
            }
            //DEJANDO LISTO ARREGLO PARA NUEVA CORRIDA 

            for (reng = 0; reng <= 9; reng++)
            {
                edad[reng] = 0;
            }
            reng = 0;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            for (reng = 0; reng <= 9; reng++)
            {
                edad[reng] = 0;
            }
            reng = 0;

        }
    }
}
