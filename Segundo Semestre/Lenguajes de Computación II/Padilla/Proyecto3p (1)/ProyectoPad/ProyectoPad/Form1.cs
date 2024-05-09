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
    
    public partial class Form1 : System.Windows.Forms.Form
    {
        int dimension_boton = 75;
        int padding = 10;
        public static Button[,,] boton = new Button[3, 3, 3];
        public static int index = 0,p1=1,p2=2;
        public static bool listo=false;
        public static int cpumode = 0;
        int x = 0;
        int y = 0;
        int l = 0;
        int height = 0;
        int width = 0;
        System.Windows.Forms.Form frm2 = new System.Windows.Forms.Form();
        public Form1()
        {
            InitializeComponent();

            boton[0, 0, 0] = new Button();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        boton[i, j, k] = new Button();
                        this.Controls.Add(boton[i, j, k]);
                        boton[i, j, k].Width = dimension_boton;
                        boton[i, j, k].Height = dimension_boton;
                        boton[i, j, k].Location = new Point(x + l + padding, y + padding);
                        boton[i, j, k].BackColor = Color.FromArgb(100, 100, 100);
                        if (i != 1 || k != 1 || j != 1){boton[i, j, k].BackgroundImage = Properties.Resources._75grammy;}
                        boton[i, j, k].Text = "";
                        x += dimension_boton;
                        boton[i, j, k].Click += new System.EventHandler(this.button_Clicked); 
                    }//fin for k
                    y += dimension_boton;
                    x = 0;
                }//fin for j
                l += dimension_boton * 3 + padding;
                y = 0;
            }//fin for i
            boton[1, 1, 1].Enabled = false;
            boton[1, 1, 1].BackColor = Color.FromArgb(0, 0, 0);
        }

        public static int referee()
        {
            if (index >= 25) { return 4; }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    //Verticales
                    if (boton[i, 0, j].BackColor == boton[i, 1, j].BackColor && boton[i, 1, j].BackColor == boton[i, 2, j].BackColor && boton[i, 0, j].BackColor != Color.FromArgb(100, 100, 100))
                    {
                        if (boton[i, 0, j].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                        if (boton[i, 0, j].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
                    }
                    //Horizontales
                    if (boton[i, j, 0].BackColor == boton[i, j, 1].BackColor && boton[i, j, 1].BackColor == boton[i, j, 2].BackColor && boton[i, j, 0].BackColor != Color.FromArgb(100, 100, 100))
                    {
                        if (boton[i, j, 0].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                        if (boton[i, j, 0].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
                    }
                }//fin for j

                //Diagonales derecha
                if (boton[i, 1, 1].BackColor == boton[i, 0, 0].BackColor && boton[i, 1, 1].BackColor == boton[i, 2, 2].BackColor && boton[i, 1, 1].BackColor != Color.FromArgb(100, 100, 100))
                {
                    if (boton[i, 1, 1].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                    if (boton[i, 1, 1].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
                }
                //Diagonales izquierda
                if (boton[i, 1, 1].BackColor == boton[i, 0, 2].BackColor && boton[i, 0, 2].BackColor == boton[i, 2, 0].BackColor && boton[i, 1, 1].BackColor != Color.FromArgb(100, 100, 100))
                {
                    if (boton[i, 1, 1].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                    if (boton[i, 1, 1].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
                }

            }//fin for i
             //Casos especiales
            if (boton[0, 0, 0].BackColor == boton[1, 0, 1].BackColor && boton[1, 0, 1].BackColor == boton[2, 0, 2].BackColor && boton[0, 0, 0].BackColor != Color.FromArgb(100, 100, 100))
            {
                if (boton[0, 0, 0].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                if (boton[0, 0, 0].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
            }
            if (boton[0, 0, 2].BackColor == boton[1, 1, 2].BackColor && boton[1, 1, 2].BackColor == boton[2, 2, 2].BackColor && boton[0, 0, 2].BackColor != Color.FromArgb(100, 100, 100))
            {
                if (boton[0, 0, 2].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                if (boton[0, 0, 2].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
            }
            if (boton[0, 2, 0].BackColor == boton[1, 2, 1].BackColor && boton[1, 2, 1].BackColor == boton[2, 2, 2].BackColor && boton[0, 2, 0].BackColor != Color.FromArgb(100, 100, 100))
            {
                if (boton[0, 2, 0].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                if (boton[0, 2, 0].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
            }
            if (boton[0, 0, 0].BackColor == boton[1, 1, 0].BackColor && boton[1, 1, 0].BackColor == boton[2, 2, 0].BackColor && boton[0, 0, 0].BackColor != Color.FromArgb(100, 100, 100))
            {
                if (boton[0, 0, 0].BackColor == Color.FromArgb(1, 1, 1)) { return 1; }
                if (boton[0, 0, 0].BackColor == Color.FromArgb(255, 255, 255)) { return 2; }
            }
            return 0;
        }
        public static void limpiar()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        boton[i, j, k].BackColor = Color.FromArgb(100, 100, 100);
                        if (i != 1 || k != 1 || j != 1) { boton[i, j, k].BackgroundImage = Properties.Resources._75grammy; }
                    }//fin for k
                }//fin for j
            }//fin for i

            boton[1, 1, 1].BackColor = Color.FromArgb(0, 0, 0);
            index = 0;
        }
        public static void cpu()
        {
            int a, b, c;
            Random r = new Random();
            do
            {
                a = r.Next(0, 2);
                b = r.Next(0, 2);
                c = r.Next(0, 2);
            } while (boton[a, b, c].BackColor != Color.FromArgb(100, 100, 100));
            if (cpumode == 1) {
                boton[a, b, c].BackColor = Color.FromArgb(1, 1, 1);
                switch (p1)
                {
                    case 1: boton[a,b,c].BackgroundImage = Properties.Resources._75drake; break;
                    case 2: boton[a, b, c].BackgroundImage = Properties.Resources._75dualipa; break;
                    case 3: boton[a, b, c].BackgroundImage = Properties.Resources._75kanye; break;
                    case 4: boton[a, b, c].BackgroundImage = Properties.Resources._75kim; break;
                    case 5: boton[a, b, c].BackgroundImage = Properties.Resources._75macmiller; break;
                    case 6: boton[a, b, c].BackgroundImage = Properties.Resources._75messi; break;
                    case 7: boton[a, b, c].BackgroundImage = Properties.Resources._75pepe; break;
                    case 8: boton[a, b, c].BackgroundImage = Properties.Resources._75pete; break;
                    case 9: boton[a, b, c].BackgroundImage = Properties.Resources._75rosalia; break;
                    case 10: boton[a, b, c].BackgroundImage = Properties.Resources._75spiderman; break;
                    case 11: boton[a, b, c].BackgroundImage = Properties.Resources._75taylor; break;
                }//fin switch   
            }
            if (cpumode == 2) { 
                boton[a, b, c].BackColor = Color.FromArgb(255, 255, 255);
                switch (p2)
                {
                    case 1: boton[a, b, c].BackgroundImage = Properties.Resources._75drake; break;
                    case 2: boton[a, b, c].BackgroundImage = Properties.Resources._75dualipa; break;
                    case 3: boton[a, b, c].BackgroundImage = Properties.Resources._75kanye; break;
                    case 4: boton[a, b, c].BackgroundImage = Properties.Resources._75kim; break;
                    case 5: boton[a, b, c].BackgroundImage = Properties.Resources._75macmiller; break;
                    case 6: boton[a, b, c].BackgroundImage = Properties.Resources._75messi; break;
                    case 7: boton[a, b, c].BackgroundImage = Properties.Resources._75pepe; break;
                    case 8: boton[a, b, c].BackgroundImage = Properties.Resources._75pete; break;
                    case 9: boton[a, b, c].BackgroundImage = Properties.Resources._75rosalia; break;
                    case 10: boton[a, b, c].BackgroundImage = Properties.Resources._75spiderman; break;
                    case 11: boton[a, b, c].BackgroundImage = Properties.Resources._75taylor; break;
                }//fin switch
            }
        }
        private void button_Clicked(object sender, EventArgs e)
        {
            Button clickd = sender as Button;
            if (listo == false) { MessageBox.Show("Presione Jugar para comenzar"); }
            else
            {
                if (index % 2 == 0 )
                {
                    if (cpumode == 1) { cpu(); index++; }
                    else if (clickd.BackColor == Color.FromArgb(100, 100, 100)) 
                    {
                        clickd.BackColor = Color.FromArgb(1, 1, 1);
                        switch (p1)
                        {
                            case 1: clickd.BackgroundImage = Properties.Resources._75drake; break;
                            case 2: clickd.BackgroundImage = Properties.Resources._75dualipa; break;
                            case 3: clickd.BackgroundImage = Properties.Resources._75kanye; break;
                            case 4: clickd.BackgroundImage = Properties.Resources._75kim; break;
                            case 5: clickd.BackgroundImage = Properties.Resources._75macmiller; break;
                            case 6: clickd.BackgroundImage = Properties.Resources._75messi; break;
                            case 7: clickd.BackgroundImage = Properties.Resources._75pepe; break;
                            case 8: clickd.BackgroundImage = Properties.Resources._75pete; break;
                            case 9: clickd.BackgroundImage = Properties.Resources._75rosalia; break;
                            case 10: clickd.BackgroundImage = Properties.Resources._75spiderman; break;
                            case 11: clickd.BackgroundImage = Properties.Resources._75taylor; break;
                        }//fin switch
                        index++;
                    }  
                }//fin es jugador 1
                else
                {
                    if (cpumode == 2) { cpu(); index++; }
                    else if (clickd.BackColor == Color.FromArgb(100, 100, 100))
                    {
                        clickd.BackColor = Color.FromArgb(255, 255, 255);
                        switch (p2)
                        {
                            case 1: clickd.BackgroundImage = Properties.Resources._75drake; break;
                            case 2: clickd.BackgroundImage = Properties.Resources._75dualipa; break;
                            case 3: clickd.BackgroundImage = Properties.Resources._75kanye; break;
                            case 4: clickd.BackgroundImage = Properties.Resources._75kim; break;
                            case 5: clickd.BackgroundImage = Properties.Resources._75macmiller; break;
                            case 6: clickd.BackgroundImage = Properties.Resources._75messi; break;
                            case 7: clickd.BackgroundImage = Properties.Resources._75pepe; break;
                            case 8: clickd.BackgroundImage = Properties.Resources._75pete; break;
                            case 9: clickd.BackgroundImage = Properties.Resources._75rosalia; break;
                            case 10: clickd.BackgroundImage = Properties.Resources._75spiderman; break;
                            case 11: clickd.BackgroundImage = Properties.Resources._75taylor; break;
                        }//fin switch
                        index++;
                    }
                }//fin es jugador 2

                int resultado = referee();

                if (resultado != 0)
                {
                    p1choose.Enabled = true;
                    p2choose.Enabled = true;
                    p2sig.Enabled = true;
                    p1sig.Enabled = true;
                    limpiar();
                    listo = false;
                    cpumode = 0;
                    turno.Text = "GATO 3-D";
                }

                if (resultado == 1) { MessageBox.Show("Primer Jugador, GANA"); }
                else if (resultado == 2) { MessageBox.Show("Segundo Jugador, GANA"); }
                else if (resultado == 4) { MessageBox.Show("EMPATE"); }
                else { turno.Text = "Turno Jugador " + (index % 2 + 1).ToString(); }
            }//fin cuando esta listo
            
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            //a este ni le muevas
        }

        private void reiniciar_Click(object sender, EventArgs e)
        {
            limpiar();
            turno.Text = "GATO 3-D";
        }

        private void salir_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void p1choose_Click(object sender, EventArgs e)
        {
            if (p1 >= 11) { p1 = 1; }
            else { p1++; }
            if (p1 == p2) { p1++; }
            switch (p1)
            {
                case 1: p1choose.BackgroundImage = Properties.Resources._125drake; break;
                case 2: p1choose.BackgroundImage = Properties.Resources._125dualipa; break;
                case 3: p1choose.BackgroundImage = Properties.Resources._125kanye; break;
                case 4: p1choose.BackgroundImage = Properties.Resources._125kim; break;
                case 5: p1choose.BackgroundImage = Properties.Resources._125macmiller; break;
                case 6: p1choose.BackgroundImage = Properties.Resources._125messi; break;
                case 7: p1choose.BackgroundImage = Properties.Resources._125pepe; break;
                case 8: p1choose.BackgroundImage = Properties.Resources._125pete; break;
                case 9: p1choose.BackgroundImage = Properties.Resources._125rosalia; break;
                case 10: p1choose.BackgroundImage = Properties.Resources._125spiderman; break;
                case 11: p1choose.BackgroundImage = Properties.Resources._125taylor; break;
            }//fin switch
        }

        private void p1sig_Click(object sender, EventArgs e)
        {
            p1choose.Enabled = false;
            p2choose.Enabled = false;
            p2sig.Enabled = false;
            p1sig.Enabled = false;
            listo = true;
        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void sexoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAdivinaNum frm2 = new FormAdivinaNum();
            frm2.Show();
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
            FormCalculadora frmCalc = new FormCalculadora();
            frmCalc.Show();
            this.Close();
        }

        private void bullyingNatorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormBullying frmBll = new FormBullying();
            frmBll.Show();
            this.Close();
        }

        private void chinChanPumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormChinChanPum frmChan = new FormChinChanPum();
            frmChan.Show();
            this.Close();
        }

        private void p2sig_Click(object sender, EventArgs e)
        {
            if (cpumode == 0) {
                cpumode = 1;
                p2sig.BackColor = Color.FromArgb(126, 241, 67);
                p2sig.Text = "CPU PRIMERO";
            }
            else if (cpumode == 1)
            {
                cpumode = 2;
                p2sig.BackColor = Color.FromArgb(31, 128, 217);
                p2sig.Text = "CPU SEGUNDO";
            }
            else {
                cpumode = 0;
                p2sig.BackColor = Color.FromArgb(241, 67, 67);
                p2sig.Text = "CPU DESACTIVADA";
            }
        }

        private void p2choose_Click(object sender, EventArgs e)
        {
            if (p2 >= 11) { p2 = 1; }
            else { p2++; }
            if (p1 == p2) { p2++; }
            switch (p2)
            {
                case 1: p2choose.BackgroundImage = Properties.Resources._125drake; break;
                case 2: p2choose.BackgroundImage = Properties.Resources._125dualipa; break;
                case 3: p2choose.BackgroundImage = Properties.Resources._125kanye; break;
                case 4: p2choose.BackgroundImage = Properties.Resources._125kim; break;
                case 5: p2choose.BackgroundImage = Properties.Resources._125macmiller; break;
                case 6: p2choose.BackgroundImage = Properties.Resources._125messi; break;
                case 7: p2choose.BackgroundImage = Properties.Resources._125pepe; break;
                case 8: p2choose.BackgroundImage = Properties.Resources._125pete; break;
                case 9: p2choose.BackgroundImage = Properties.Resources._125rosalia; break;
                case 10: p2choose.BackgroundImage = Properties.Resources._125spiderman; break;
                case 11: p2choose.BackgroundImage = Properties.Resources._125taylor; break;
            }//fin switch
        }
    }
}
