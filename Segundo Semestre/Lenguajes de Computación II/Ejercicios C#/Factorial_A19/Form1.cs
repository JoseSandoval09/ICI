using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Factorial_A19
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



        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
        public static int num = 0;

        private void button1_Click(object sender, EventArgs e)
        {
            int x = 0;
            Random rand = new Random();
            if (num < 10)
            {
                x = rand.Next(1, 8);
                listBox1.Items.Add(x);
                num++;
                factorial(x);
            }
            else
            {
                MessageBox.Show("Limite de numeros 10");
            }
        }

            public static int res = 1;

        public void factorial(int n) {

            for (int i = 1; i <= n; i++) {
                res = res * i;
            }
            listBox2.Items.Add(res);
            res = 1;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            num = 0;
        }
    }
}
