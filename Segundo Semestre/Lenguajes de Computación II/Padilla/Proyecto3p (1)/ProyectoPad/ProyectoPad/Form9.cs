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
    public partial class FormBullying : Form
    {
        public FormBullying()
        {
            InitializeComponent();
        }

        private void calculadoraToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormCalculadora frmcl = new FormCalculadora();
            frmcl.Show();
            this.Close();
        }

        private void gato3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Close();
        }

        private void chinChanPumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormChinChanPum frmCCC = new FormChinChanPum();
            frmCCC.Show();
            this.Close();
        }

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAdivinaNum frmAd = new FormAdivinaNum();
            frmAd.Show();
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

        private void mayaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConMaya frmMaya = new FormConMaya();
            frmMaya.Show();
            this.Close();
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        public static string[] apodos =
        {
                "Pandete rojete", "Rockerito", "El chocolatozo",
                "Reine del oriente", "El cuchi cu", "Dr. Sexy", "El metro y sexual",
                "El pelos", "El popos", "El comal", "El power ranger", "El patas", "El chicharito",
                "El tortilla volteada", "El mata viejitas", "El nene", "El bicho, SIUUU", "Winnie Pooh",
                "El chemo", "La chimenea", "La vaca", "El motorola", "El manteca", "El autogol", "El tilin",
                "El cagalubias"
        };

        private void button1_Click(object sender, EventArgs e)
        {
            string nickname;
            nickname = Convert.ToString(name.Text);
            Random auxnickname = new Random();
            int index = auxnickname.Next(apodos.Length);

            MessageBox.Show("Hola cabeza de chorlito !!!");
            MessageBox.Show(" Tu  nuevo apodo sera: " + nickname + " " + apodos[index] + " JAJAJAJ que duermas bien");
        }
    }
}
