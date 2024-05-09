using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A6TablasMultilplicar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           


        }

        private void TablaM_Click(object sender, EventArgs e)
        {
            int num, res, ite;
            Multi.Items.Clear();

            num = Convert.ToInt32(Num.Text);

            for (ite = 0; ite <= 10; ite++)
            {
                res = num * ite;

                Multi.Items.Add(num.ToString() + "x" + ite.ToString() + "=" + res.ToString());

            }
        }
    }
}
