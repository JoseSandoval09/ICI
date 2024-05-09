using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A11_FEB23
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            int x = listBox1.Items.Count;
            if (x < 20)
            {
                if(Elemento.Text != "")
                {
                    listBox1.Items.Add(Elemento.Text);
                    Elemento.Clear();
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex != 1)
            {
                listBox1.Items.RemoveAt(listBox1.SelectedIndex);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int x = listBox1.Items.Count;
            button4.Text = " Total de elementos = " + x.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
