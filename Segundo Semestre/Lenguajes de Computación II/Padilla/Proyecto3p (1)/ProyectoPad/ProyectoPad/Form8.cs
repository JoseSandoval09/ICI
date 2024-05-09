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
    public partial class FormChinChanPum : Form
    {
        public FormChinChanPum()
        {
            InitializeComponent();
        }

        private void conversoresToolStripMenuItem_Click(object sender, EventArgs e)
        {

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

        private void adivinaElNumeroToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAdivinaNum frmAd = new FormAdivinaNum();
            frmAd.Show();
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

        int Player_Move, CPU_Move, P_wins = 0, CPU_wins = 0;



        private void button4_Click(object sender, EventArgs e)
        {
            if (P_wins > CPU_wins)
            {
                MessageBox.Show("EL jugador ha ganado " + P_wins + " juegos a  " + CPU_wins);
            }
            else if (CPU_wins > P_wins)
            {
                MessageBox.Show("La CPU ha ganado " + CPU_wins + " juegos a  " + P_wins);
            }
            else if (CPU_wins == P_wins)
            {
                MessageBox.Show("EL JUGADOR Y LA MAQUINA HAN QUEDADO EMPATADOS");
            }

            pictureBox1.Image = null;
            pictureBox2.Image = null;
            Player_Move = 0;
            CPU_Move = 0;
            P_wins = 0;
            CPU_wins = 0;
            Ganados_CPU.Text = ".";
            Ganados_P.Text = ".";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources._2;
            Player_Move = 1;
            Random CPU_r = new Random();
            int CPU_selection = CPU_r.Next(0, 2);
            CPU_Move = CPU_selection;
            MessageBox.Show("Es turno de la maquina");
            if (CPU_selection == 0)
            {
                pictureBox2.Image = Properties.Resources._1_d;
                MessageBox.Show("LA CPU HA SELECCIONADO TIJERA");
                Jugar();
            }
            else if (CPU_selection == 1)
            {
                pictureBox2.Image = Properties.Resources._2_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PIEDRA");
                Jugar();
            }
            else if (CPU_selection == 2)
            {
                pictureBox2.Image = Properties.Resources._3_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PAPEL");
                Jugar();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources._3;
            Player_Move = 2;
            Random CPU_r = new Random();
            int CPU_selection = CPU_r.Next(0, 2);
            CPU_Move = CPU_selection;
            MessageBox.Show("Es turno de la maquina");
            if (CPU_selection == 0)
            {
                pictureBox2.Image = Properties.Resources._1_d;
                MessageBox.Show("LA CPU HA SELECCIONADO TIJERA");
                Jugar();
            }
            else if (CPU_selection == 1)
            {
                pictureBox2.Image = Properties.Resources._2_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PIEDRA");
                Jugar();
            }
            else if (CPU_selection == 2)
            {
                pictureBox2.Image = Properties.Resources._3_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PAPEL");
                Jugar();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources._1;
            Player_Move = 0;
            Random CPU_r = new Random();
            int CPU_selection = CPU_r.Next(0, 2);
            CPU_Move = CPU_selection;
            MessageBox.Show("Es turno de la maquina");
            if (CPU_selection == 0)
            {
                pictureBox2.Image = Properties.Resources._1_d;
                MessageBox.Show("LA CPU HA SELECCIONADO TIJERA");
                Jugar();
            }
            else if (CPU_selection == 1)
            {
                pictureBox2.Image = Properties.Resources._2_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PIEDRA");
                Jugar();
            }
            else if (CPU_selection == 2)
            {
                pictureBox2.Image = Properties.Resources._3_d;
                MessageBox.Show("LA CPU HA SELECCIONADO PAPEL");
                Jugar();
            }
        }
        private void Jugar()
        {
            //CASOS PLAYER 1 == TIJERAS
            if (Player_Move == 0 && CPU_Move == 2)
            {
                MessageBox.Show("El jugador GANA");
                P_wins++;
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
            }
            else if (Player_Move == 0 && CPU_Move == 1)
            {
                MessageBox.Show("LA CPU GANA");
                CPU_wins++;
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
                Ganados_P.Text = Convert.ToString(P_wins);

            }
            else if (Player_Move == 0 && CPU_Move == 0)
            {
                MessageBox.Show("JUGADORES EMPATADOS");
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
            }

            //CASOS PLAYER 1 == PIEDRA
            if (Player_Move == 1 && CPU_Move == 2)
            {
                MessageBox.Show("La CPU GANA");
                CPU_wins++;
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
                Ganados_P.Text = Convert.ToString(P_wins);
            }
            else if (Player_Move == 1 && CPU_Move == 1)
            {
                MessageBox.Show("JUGADORES EMPATADO");
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);

            }
            else if (Player_Move == 1 && CPU_Move == 0)
            {
                MessageBox.Show("EL JUGADOR GANA");
                P_wins++;
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);

            }

            //CASOS PLAYER 2== PAPEL
            if (Player_Move == 2 && CPU_Move == 2)
            {
                MessageBox.Show("JUGADORES EMPATADOS");
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
            }
            else if (Player_Move == 2 && CPU_Move == 1)
            {
                MessageBox.Show("JUGADOR GANA");
                P_wins++;
                Ganados_P.Text = Convert.ToString(P_wins);
                Ganados_CPU.Text = Convert.ToString(CPU_wins);

            }
            else if (Player_Move == 2 && CPU_Move == 0)
            {
                MessageBox.Show("LA CPU GANA");
                CPU_wins++;
                Ganados_CPU.Text = Convert.ToString(CPU_wins);
                Ganados_P.Text = Convert.ToString(P_wins);
            }

        }


    }
}
