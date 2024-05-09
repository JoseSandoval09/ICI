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
    public partial class FormAdivinaNum : System.Windows.Forms.Form
    {
        public FormAdivinaNum()
        {
            InitializeComponent();
        }

        public static int adivina,intentos=0;
        bool esEntero(string text)
        {
            try
            {
                Int32.Parse(text);
                return true;
            }
            catch
            {
                return false;
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (esEntero(textBox1.Text) == false)
            {
                MessageBox.Show("Ingrese un numero entero entre 1 y 99");
            }
            else
            {
                int guess = Convert.ToInt32(textBox1.Text);
                if (guess == adivina)
                {
                    MessageBox.Show("Has acertado en "+intentos.ToString()+" intentos.");
                    button1.Enabled = false;
                    button2.Enabled = true;
                    intentos = 0;
                    label3.Text = "WALTER DICE:\nAdivina el número que\npienso entre el 1 y el 99";
                }
                else if (guess > adivina)
                {
                    label3.Text = "WALTER DICE:\nEs un numero menor";
                    intentos++;
                }
                else
                {
                    label3.Text = "WALTER DICE:\nEs un numero mayor";
                    intentos++;
                }
            }
            textBox1.Text = " ";
        }

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void juegosToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void chinChanPum3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormChinChanPum frmCC = new FormChinChanPum();
            frmCC.Show();
            this.Close();
        }

        private void gato3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Close();
        }

        private void digitalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConDigital frmDig = new FormConDigital();
            frmDig.Show();
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

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void bullyingnatorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormBullying frmBll = new FormBullying();
            frmBll.Show();
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            adivina = r.Next(1, 99);
            button2.Enabled = false;
            button1.Enabled = true;
        }
    }
}
