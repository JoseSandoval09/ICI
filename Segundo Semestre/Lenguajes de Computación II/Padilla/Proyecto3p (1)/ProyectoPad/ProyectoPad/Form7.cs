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
    public partial class FormCalculadora : System.Windows.Forms.Form
    {
        public FormCalculadora()
        {
            InitializeComponent();
        }

        public static double ans_ant = 0;
        public static bool nec_limpiar = false;
        public const double val_del_mal = 0.000001;
        bool jerarquia(char a,char b)
        {
            if(a=='C' || a == 'R') { return true; }
            if (a == '^')
            {
                if (b == '^') { return false; }
                return true;
            }
            if (a == '*' || a == '/' || a=='%')
            {
                if (b == '*' || b == '/' || b == '^' || b=='%') { return false; }
                else { return true; }
            }
            if ((a == '-' || a == '+'))
            {
                if (b == '(') { return true; }
                return false;
            }
            return false;
        }
        bool car_buster(char a)
        {
            if (a == '(') { return true; }
            if (a == ')') { return true; }
            if (a == '+') { return true; }
            if (a == '-') { return true; }
            if (a == '*') { return true; }
            if (a == '/') { return true; }
            if (a == '^') { return true; }
            if (a == '%') { return true; }
            if (a == 'C') { return true; }
            if (a == 'R') { return true; }
            return false;
        }
        double postfix(string op)
        {
            string res = "";
            Stack<char> pila = new Stack<char>();

            for (int i=0;i< op.Length; i++)
            {
                if (car_buster(op[i]) == false) { res += op[i]; }
                else
                {
                    res += " ";
                    if (pila.Count() == 0) { pila.Push(op[i]); }
                    else if (op[i] == ')')
                    {
                        Console.WriteLine(pila.Count().ToString());
                        if(pila.Count() == 0) { return val_del_mal; }
                        while (pila.Count()!= 0 && pila.Peek() != '(')
                        {
                            res += pila.Peek();
                            pila.Pop();
                        }//mientras no se cierre parentesis
                        if (pila.Count() == 0) { return val_del_mal; }
                        pila.Pop();
                    }//cierra parentesis
                    else
                    {
                        if (jerarquia(op[i], pila.Peek()) == true || op[i] == '(') { pila.Push(op[i]); }
                        else
                        {
                            res += pila.Peek();
                            pila.Pop();
                            pila.Push(op[i]);
                        }
                    }// hay elementos en la pila
                }//es un operando

            }//recorre string
            while (pila.Count() != 0) { res += pila.Peek(); pila.Pop(); }

            Stack<double> resultados = new Stack<double>();
            for (int i = 0; i < res.Length; i++)
            {
                if (res[i] == ' ') { i++; }
                if (i<res.Length && car_buster(res[i]) == false)
                {
                        double a=0;
                        string numero = "";
                        while(res[i]!=' ') {
                            numero += res[i];
                            i++;
                        }//while construye el numero
                    if (numero == "A") { resultados.Push(ans_ant); }
                    else if(numero == "P") { resultados.Push(Math.PI); }
                    else if(numero == "e") { resultados.Push(Math.E); }
                    else if (numero != "") {
                        a = double.Parse(numero);
                        resultados.Push(a);
                    }
                            
                    
                }//no es un operador
                else if(i<res.Length)
                {
                    if (resultados.Count() < 2) { return val_del_mal; }
                    double b = resultados.Peek(); resultados.Pop();
                    double a = resultados.Peek(); resultados.Pop();
                    if (res[i] == 'C') {
                        int n = Convert.ToInt32(a);
                        int k = Convert.ToInt32(b);
                        a = combinacion(n, k);
                    }
                    if (res[i] == 'R') {
                        int n = Convert.ToInt32(a);
                        int k = Convert.ToInt32(b);
                        a = permutacion(n, k);
                    }
                    if (res[i] == '+') { a += b; }
                    if (res[i] == '-') { a -= b; }
                    if (res[i] == '*') { a *= b; }
                    if (res[i] == '/') { a /= b; }
                    if (res[i] == '%') { a %= b; }
                    if (res[i] == '^')
                    {
                        int veces = Convert.ToInt32(b);
                        double z=1;
                        for (int j = 1; j <= veces; j++)
                        {
                            z *= a;
                        }//fin for j
                        a = z;
                    }//fin potencia

                    resultados.Push(a);
                }
            }//fin for i

            return resultados.Peek();
        }
        int factorial(int a)
        {
            if(a > 1){ return a * (a - 1); }
            return 1;
        }
        int permutacion(int n,int k)
        {
            int res = 1;
            for (int i=k+1; i <= n; i++) { res *= i; }
            return res;
        }
        int combinacion(int n,int k)
        {
            int el = permutacion(n,k);
            int res = 1;
            for(int i = 2; i <= (n - k); i++) { res *= i; }
            el /= res;
            return el;
        }
        double raiz (double a)
        {
            return Math.Sqrt(a);
        }
        double Absoluto (double a)
        {
            return Math.Abs(a);
        }
        double seno (double a)
        {
            return Math.Sin(a);
        }
        double coseno(double a)
        {
            return Math.Cos(a);
        }
        double tangente(double a)
        {
            return Math.Tan(a);
        }

        private void uno_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "1";
        }

        private void dos_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "2";
        }

        private void tres_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "3";
        }

        private void cuatro_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "4";
        }

        private void cinco_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "5";
        }

        private void seis_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "6";
        }

        private void siete_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "7";
        }

        private void ocho_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "8";
        }

        private void nueve_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "9";
        }

        private void cero_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "0";
        }

        private void punto_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += ".";
        }

        private void mas_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "+";
        }

        private void menos_Click(object sender, EventArgs e)
        {
            lcd.Text += "-";
        }

        private void por_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "*";
        }

        private void entre_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "/";
        }

        private void pot_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "^";
        }

        private void mod_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "%";
        }

        private void parabre_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "(";
        }

        private void parcierra_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += ")";
        }

        private void numpi_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "P";
        }

        private void nume_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "e";
        }

        private void borrar_Click(object sender, EventArgs e)
        {
            lcd.Text = ""; nec_limpiar = false;
        }

        private void igual_Click(object sender, EventArgs e)
        {
            string expresion = lcd.Text;
            expresion += ' ';
            double result = postfix(expresion);
            if (result == val_del_mal) { lcd.Text = "Syntax Error"; }
            else
            {
                lcd.Text = result.ToString();
                ans_ant = result;
            }
            nec_limpiar = true;
        }

        double logaritmo(double a, double b)
        {
            return Math.Log(a, b);
        }
        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void answer_Click(object sender, EventArgs e)
        {
            if (nec_limpiar == true) { lcd.Text = ""; nec_limpiar = false; }
            lcd.Text += "A";
        }

        private void fac_Click(object sender, EventArgs e)
        {
            lcd.Text = "A! = ";
            int resultado = factorial(Convert.ToInt32(ans_ant));
            lcd.Text += resultado.ToString(); 
            nec_limpiar = true;
        }

        private void tecraiz_Click(object sender, EventArgs e)
        {
            lcd.Text = "sqrt(A) = ";
            double resultado = raiz(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void tecabs_Click(object sender, EventArgs e)
        {
            lcd.Text = "|A| = ";
            double resultado = Absoluto(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void logar_Click(object sender, EventArgs e)
        {
            lcd.Text = "log(A) = ";
            double resultado = Math.Log10(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void logan_Click(object sender, EventArgs e)
        {
            lcd.Text = "ln(A) = ";
            double resultado = Math.Log(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void tecsin_Click(object sender, EventArgs e)
        {
            lcd.Text = "sin(A) = ";
            double resultado = seno(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void teccos_Click(object sender, EventArgs e)
        {
            lcd.Text = "cos(A) = ";
            double resultado = coseno(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void tectan_Click(object sender, EventArgs e)
        {
            lcd.Text = "tan(A) = ";
            double resultado = tangente(ans_ant);
            lcd.Text += resultado.ToString();
            nec_limpiar = true;
        }

        private void Comb_Click(object sender, EventArgs e)
        {
            lcd.Text += "C";
        }

        private void Perm_Click(object sender, EventArgs e)
        {
            lcd.Text += "R";
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void gato3DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Close();
        }

        private void chinChanPumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormChinChanPum frmCC = new FormChinChanPum();
            frmCC.Show();
            this.Close();
        }

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAdivinaNum frmAdv = new FormAdivinaNum();
            frmAdv.Show();
            this.Close();
        }

        private void bullyingnatorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormBullying frmBll = new FormBullying();
            frmBll.Show();
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
            FormConRomano frmRoma = new FormConRomano();
            frmRoma.Show();
            this.Close();
        }

        private void mayaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormConMaya frmMaya = new FormConMaya();
            frmMaya.Show();
            this.Close();
        }
    }
}
