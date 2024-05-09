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
    public partial class FormConRomano : System.Windows.Forms.Form
    {
        public FormConRomano()
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
        int esRomano(char x)
        {
            switch (x)
            {
                case 'I': return 0;
                case 'V': return 1;
                case 'X': return 2;
                case 'L': return 3;
                case 'C': return 4;
                case 'D': return 5;
                case 'M': return 6;
            }
            return -1;
        }
        string decRomano(int n)
        {
            string res = "";
            while (n >= 1000){ res += 'M'; n -= 1000; }
            if (n >= 900) { res += "CM"; n -= 900; }
            if (n >= 500) { res += 'D'; n -= 500; }
            if (n >= 400) { res += "CD"; n -= 400; }
            while(n >= 100) { res += 'C'; n -= 100; }
            if (n >= 90) { res += "XC"; n -= 90; }
            if (n >= 50) { res += "L"; n -= 50; }
            if (n >= 40) { res += "XL"; n -= 40; }
            while(n >= 10) { res += 'X'; n -= 10; }
            if (n>= 9) { res += "IX"; n -= 9; }
            if (n >= 5) { res += "V"; n -= 5; }
            if (n >= 4) { res += "IV"; n -= 4; }
            while (n >= 1) { res += 'I'; n--; }
            return res;
        }
        int jerarquiaRomana(char a,char b)
        {
            if(a=='V' && b == 'I') { return 4; }
            if(a=='X' && b == 'I') { return 9; }
            if(a=='L' && b == 'X') { return 40; }
            if(a=='C' && b == 'X') { return 90; }
            if(a=='D' && b == 'C') { return 400; }
            if(a=='M' && b == 'C') { return 900; }
            return 0;
        }
        int valoresRomanos(char a)
        {
            if (a == 'I') { return 1; }
            if (a == 'V') { return 5; }
            if (a == 'X') { return 10; }
            if (a == 'L') { return 50; }
            if (a == 'C') { return 100; }
            if (a == 'D') { return 500; }
            if (a == 'M') { return 1000; }
            return -1;
        }
        int romDecimal(string r)
        {
            int res=0,aux=0;
            for(int i=r.Length - 1;i>=1;i--)
            {
                aux = jerarquiaRomana(r[i], r[i - 1]);
                if (valoresRomanos(r[i]) == -1)
                {
                    MessageBox.Show("Caracter invalido");
                    return -1;
                }
                else if (aux == 0) { res += valoresRomanos(r[i]);}
                else { res += aux; i--; }
            }//fin for hasta segundo elemento
            if (aux == 0) { res += valoresRomanos(r[0]); }
            return res;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if(numrom.Text == "" && numdec.Text == "") { MessageBox.Show("Ingrese un valor"); }
            else if(numrom.Text == "" && esEntero(numdec.Text) == true)
            {
                numrom.Text = "";
                int numero = Convert.ToInt32(numdec.Text);
                if (numero > 4999) { MessageBox.Show("Okay, demasiado"); numdec.Text = ""; numrom.Text = ""; }
                else { numrom.Text = decRomano(numero); }
            }
            else if (numdec.Text == "")
            {
                numdec.Text = "";
                numrom.Text = numrom.Text.ToUpper();
                int resultado = romDecimal(numrom.Text);
                if (resultado == -1) { numdec.Text = ""; numrom.Text = ""; }
                else { numdec.Text = resultado.ToString(); }
            }
            else { MessageBox.Show("Ingrese los campos de forma correcta"); numrom.Text = ""; numdec.Text = ""; }
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

        private void FormConRomano_Load(object sender, EventArgs e)
        {

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
