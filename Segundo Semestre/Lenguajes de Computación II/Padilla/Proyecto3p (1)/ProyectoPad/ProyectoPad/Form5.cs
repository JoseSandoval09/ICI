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
    public partial class FormConMaya : System.Windows.Forms.Form
    {
        public FormConMaya()
        {
            InitializeComponent();
        }
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
            if (esEntero(num.Text) == false) { MessageBox.Show("Ingrese un numero entero"); num.Text = ""; }
            else
            {
                valor1.BackgroundImage = Properties.Resources.mayacero;
                valor20.BackgroundImage = Properties.Resources.mayacero;
                valor400.BackgroundImage = Properties.Resources.mayacero;

                int numero = Convert.ToInt32(num.Text),index = 0;
                if (numero >= 8000) { MessageBox.Show("Okay, demasiado");}
                else
                {
                    while (numero > 0)
                    {
                        switch (numero % 20)
                        {
                            case 0:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayacero; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayacero; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayacero; }
                                break;
                            case 1:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayauno; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayauno; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayauno; }
                                break;
                            case 2:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayados; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayados; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayados; }
                                break;
                            case 3:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayatres; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayatres; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayatres; }
                                break;
                            case 4:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayacuatro; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayacuatro; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayacuatro; }
                                break;
                            case 5:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayacinco; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayacinco; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayacinco; }
                                break;
                            case 6:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayaseis; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayaseis; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayaseis; }
                                break;
                            case 7:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayasiete; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayasiete; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayasiete; }
                                break;
                            case 8:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayaocho; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayaocho; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayaocho; }
                                break;
                            case 9:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayanueve; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayanueve; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayanueve; }
                                break;
                            case 10:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadiez; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadiez; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadiez; }
                                break;
                            case 11:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayaonce; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayaonce; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayaonce; }
                                break;
                            case 12:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadoce; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadoce; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadoce; }
                                break;
                            case 13:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayatrece; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayatrece; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayatrece; }
                                break;
                            case 14:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayacatorce; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayacatorce; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayacatorce; }
                                break;
                            case 15:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayaquince; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayaquince; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayaquince; }
                                break;
                            case 16:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadieciseis; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadieciseis; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadieciseis; }
                                break;
                            case 17:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadiecisiete; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadiecisiete; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadiecisiete; }
                                break;
                            case 18:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadieciocho; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadieciocho; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadieciocho; }
                                break;
                            case 19:
                                if (index == 0) { valor1.BackgroundImage = Properties.Resources.mayadiecinueve; }
                                if (index == 1) { valor20.BackgroundImage = Properties.Resources.mayadiecinueve; }
                                if (index == 2) { valor400.BackgroundImage = Properties.Resources.mayadiecinueve; }
                                break;
                        }//fin switch
                        index++; numero /= 20;
                    }
                }//es menor a 8000
                
            }
        }

        private void gato3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
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
            FormConDigital frmDigital = new FormConDigital();
            frmDigital.Show();
            this.Close();
        }

        private void romanoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConRomano frmRoma = new FormConRomano();
            frmRoma.Show();
            this.Close();
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
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