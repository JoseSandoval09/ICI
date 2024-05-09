using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT
{
    public partial class FormConDigital : System.Windows.Forms.Form
    {
        public FormConDigital()
        {
            InitializeComponent();
        }

        bool esEntero(string Text)
        {
            try{
                Int32.Parse(Text);
                return true;
            }
            catch
            {
                return false;
            }
        }
        char enteroCar(int n)
        {
            switch (n)
            {
                case 0: return '0';
                case 1: return '1';
                case 2: return '2';
                case 3: return '3';
                case 4: return '4';
                case 5: return '5';
                case 6: return '6';
                case 7: return '7';
                case 8: return '8';
                case 9: return '9';
                case 10: return 'A';
                case 11: return 'B';
                case 12: return 'C';
                case 13: return 'D';
                case 14: return 'E';
                case 15: return 'F';
            }
            return ' ';
        }
        string invertirCadena(string h)
        {
            string inversa="";
           
            for (int d = h.Length - 1;  d >= 0; d--)
            {
                inversa += h[d];
            }
            return inversa;
        }
        string decbin(int n)
        {
            string res = "";
                while (n > 0)
                {
                    res += enteroCar(n % 2);
                    n /= 2;
                }
            return invertirCadena(res);
        }
        string decoct(int n)
        {
            string res = "";
            while (n > 0)
            {
                res += enteroCar(n % 8);
                n /= 8;
            }
            return invertirCadena(res);
        }
        string dechex(int n)
        {
            string res = "";
            while (n > 0)
            {
                res += enteroCar(n % 16);
                n /= 16;
            }
            return invertirCadena(res);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if(esEntero(num.Text) == false) { MessageBox.Show("Ingrese un numero entero"); }
            else
            {
                int numero = Convert.ToInt32(num.Text);
                rescon.Text = decbin(numero) + "\n" + decoct(numero) + "\n" + dechex(numero);
            }
            num.Text = "";
        }

        private void gato3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Close();
        }

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAdivinaNum frm2 = new FormAdivinaNum();
            frm2.Show();
            this.Close();
        }

        private void romanoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConRomano frmRom = new FormConRomano();
            frmRom.Show();
            this.Close();
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void mayaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConMaya frmMaya = new FormConMaya();
            frmMaya.Show();
            this.Close();
        }

        private void calculadoraToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormCalculadora frmCl = new FormCalculadora();
            frmCl.Show();
            this.Close();
        }

        private void chinChanPumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormChinChanPum frmCC = new FormChinChanPum();
            frmCC.Show();
            this.Close();
        }

        private void bullyingnatorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormBullying frmBll = new FormBullying();
            frmBll.Show();
            this.Close();
        }
    }
}
