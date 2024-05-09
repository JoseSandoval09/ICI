using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace A5_DECIMA_ROMANO
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int um, cent, dec, uni, r1, cant_org;
            string Romano;
            cant_org= Convert.ToInt32(Decimal.Text);
            if (cant_org < 1 || cant_org > 3999)
            {
                MessageBox.Show("Solo valores entre 1-3999");
            }
            else
            {
                MessageBox.Show("Convirtiendo valor");
                um = cant_org / 1000;
                r1 = cant_org % 1000;
                cent = r1 / 100;
                r1 = r1 % 100;
                dec = r1 / 10;
                uni = r1 % 10;
                Romano = "";

                switch (um)
                {
                    case 1: Romano = "M"; break;
                    case 2: Romano = "MM"; break;
                    case 3: Romano = "MMM"; break;

                }
                switch (cent)
                {
                    case 1: Romano = Romano + "C"; break;
                    case 2: Romano = Romano + "CC"; break;
                    case 3: Romano = Romano + "CCC"; break;
                    case 4: Romano = Romano + "CD"; break;
                    case 5: Romano = Romano + "D"; break;
                    case 6: Romano = Romano + "DC"; break;
                    case 7: Romano = Romano + "DCC"; break;
                    case 8: Romano = Romano + "DCCC"; break;
                    case 9: Romano = Romano + "CM"; break;
                }
                switch (dec)
                {
                    case 1: Romano = Romano + "X"; break;
                    case 2: Romano = Romano + "XX"; break;
                    case 3: Romano = Romano + "XXX"; break;
                    case 4: Romano = Romano + "XL"; break;
                    case 5: Romano = Romano + "L"; break;
                    case 6: Romano = Romano + "LX"; break;
                    case 7: Romano = Romano + "LXX"; break;
                    case 8: Romano = Romano + "LXXX"; break;
                    case 9: Romano = Romano + "XC"; break;
                }
                switch (uni)
                {
                    case 1: Romano = Romano + "I"; break;
                    case 2: Romano = Romano + "II"; break;
                    case 3: Romano = Romano + "III"; break;
                    case 4: Romano = Romano + "IV"; break;
                    case 5: Romano = Romano + "V"; break;
                    case 6: Romano = Romano + "VI"; break;
                    case 7: Romano = Romano + "VII"; break;
                    case 8: Romano = Romano + "VIII"; break;
                    case 9: Romano = Romano + "IX"; break;
                }
                NumRomano.Text = "El numero romano es: " + Romano;

            }

        }
    }
}
