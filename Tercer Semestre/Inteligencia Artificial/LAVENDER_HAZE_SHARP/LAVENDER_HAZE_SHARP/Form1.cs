using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LAVENDER_HAZE_SHARP
{
    public partial class Form1 : Form
    {

        struct lab
        {
            public char simbolo;
            public Pair<int, int> padre;
            public bool esCamino;
        };

        const int N = 40;
        public static PictureBox[,] px = new PictureBox[N, N];
        int t_px = 8;//tamano de la casilla

        public Form1()
        {
            InitializeComponent();
            //se agregan todas las casillas del laberinto
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    px[i, j] = new PictureBox();
                    int x = 10 + t_px * i;
                    int y = 10 + t_px * j;
                    px[i, j].SetBounds(x,y,t_px,t_px);
                    px[i, j].Visible = true;
                    Controls.Add(px[i, j]);

                }//fin for j
            }//fin for i
        }

        private void iniciar_Click(object sender, EventArgs e)
        {
            lab[,] casilla = new lab[N, N];
            iniciarStructs(casilla);

            Pair<int, int> f = new Pair<int, int>();
            f = generarLaberinto(casilla);
            pintarLab(casilla);
            mostrarLaberinto(casilla);
            BFS(casilla, f);
            pintarLab(casilla);
        }

        void pintarLab(lab[,] c)
        {
            //pinta las casillas dependiendo si son obstaculos o no
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if (c[i,j].simbolo == '.') { px[i, j].BackColor = Color.White; }
                    if (c[i, j].simbolo == '#') { px[i, j].BackColor = Color.Orange; }
                }//fin for j
            }//fin for i
        }
        void BFS(lab[,] c,Pair<int,int>f)
        {
            Queue<Pair<int, int>> vis = new Queue<Pair<int, int>>();
            restablecerMat(c);

            vis.Enqueue(new Pair<int,int>(0,0));

            int x = vis.Peek().First;
            int y = vis.Peek().Second;

            while (vis.Count!=0  && (x != f.First || y != f.Second))
            {
                x = vis.Peek().First;
                y = vis.Peek().Second;
                vis.Dequeue();
                matriz.Items.Add(x.ToString() + " " + y.ToString() );
                if (x - 1 >= 0 && c[x - 1,y].simbolo != '#' && !c[x - 1,y].esCamino) { 
                    vis.Enqueue(new Pair<int,int>(x - 1, y)); 
                    c[x - 1, y].esCamino = true;
                    c[x - 1,y].padre = new Pair<int, int>(x , y);
                }//arriba
                if (x + 1 < N && c[x + 1,y].simbolo != '#' && !c[x + 1,y].esCamino) {
                    vis.Enqueue(new Pair<int, int>(x + 1, y));
                    c[x + 1, y].esCamino = true;
                    c[x + 1, y].padre = new Pair<int, int>(x, y);
                }//abajo
                if (y - 1 >= 0 && c[x,y - 1].simbolo != '#' && !c[x,y - 1].esCamino) {
                    vis.Enqueue(new Pair<int, int>(x , y - 1));
                    c[x, y -1].esCamino = true;
                    c[x, y -1].padre = new Pair<int, int>(x, y);
                }//izquierda
                if (y + 1 < N && c[x,y + 1].simbolo != '#' && !c[x,y + 1].esCamino) {
                    vis.Enqueue(new Pair<int, int>(x, y + 1));
                    c[x, y + 1].esCamino = true;
                    c[x, y + 1].padre = new Pair<int, int>(x, y);
                }//derecha

            }//while mientras no llegue al destino

            x = f.First;
            y = f.Second;

            while (x != 0 || y != 0)
            {
                c[x,y].simbolo = 'a';
                px[x, y].BackColor = Color.Blue;
                int cx = c[x,y].padre.First;
                int cy = c[x,y].padre.Second;

                x = cx; y = cy;
            }//regresa el camino

            x = f.First;
            y = f.Second;
            c[x,y].simbolo = 'f';
            px[x, y].BackColor = Color.Red;
            c[0, 0].simbolo = 'a';
            px[0, 0].BackColor = Color.Green;
        }
        Pair<int, int> generarLaberinto(lab[,] casilla)
        {
            //desde el struct el laberinto esta lleno de
            //espacios abiertos (.)
            var r = new Random();

            for (int i = 0; i < N; i++)
            {
                /*
                    se calcula el numero de obstaculos por fila
                    el 33% de 40 es 13 y el 42% de 40 es 16, por lo tanto
                    la cantidad de obstaculos debe rondar de 13 a 16
                */
                int n_ob = 13 + r.Next(0,4);
                while (0 < n_ob)
                {
                    int x = r.Next(0,N);
                    if (casilla[x,i].simbolo == '.')
                    {
                        casilla[x,i].simbolo = '#';
                        n_ob--;
                    }//si no es un obstaculo

                }//fin while obstaculos
            }//fin for i

            int fy = N - 1;
            int fx = r.Next(0,N);//aqui es donde se determina el punto final

            //casilla final
            casilla[fx,fy].simbolo = 'f';

            casilla[fx,fy].esCamino = true;
            //casilla de inicio
            casilla[0,0].simbolo = '.';
            casilla[0,0].esCamino = true;

            hacerUnHuecoEnLaPared(casilla, fx, fy, 1, 0);
            hacerUnHuecoEnLaPared(casilla, fx, fy, 0, 1);

            Pair<int, int> f = new Pair<int, int>(fx,fy);
            
            return f;
        }

        void hacerUnHuecoEnLaPared(lab[,] casilla,int fx,int fy,int x,int y)
        {
            int q_abajo = 5; //la probabilidad de ir abajo es de 5
            int q_der = q_abajo + 4; // la probabilidad de ir a la derecha 4
                                     //entonces la probabilidad de que se mueva a la izquierda queda determinada por:
                                     //10 - q_der - q_abajo
            var r = new Random();

            while (x != fx || y != fy)
            {
                casilla[x,y].esCamino = true;

                if (casilla[x,y].simbolo == '#')
                {
                    //si el camino se topa con un muro mueve ese muro en la misma fila
                    //debe revisar que no sea parte de un camino y que no sea un muro
                    int mover = r.Next(0,N);
                    while (casilla[mover,y].simbolo == '#' || casilla[mover,y].esCamino==true) { mover = r.Next(0,N); }

                    casilla[mover,y].simbolo = '#';//se mueve la casilla
                }//si la casilla es un muro
                casilla[x,y].simbolo = '.';

                int decision = r.Next(0,9);

                if (y == fy)
                {
                    if (x > fx) { x--; }
                    else { x++; }
                }
                else
                {
                    if (decision <= q_abajo && y < N - 1) { y++; }//hacia abajo
                    else if (decision <= q_der && x < N) { x++; }//preferiblemente a la derecha
                    else if (x > 0) { x--; }// a la izquierda
                    else if (y < N - 1) { y++; }// si se llega a un limite mejor bajar
                }

            }//despeja camino

        }

        void mostrarLaberinto(lab[,] c)
        {
                matriz.Items.Clear();
            //imprime el laberinto (char) en la listbox
                for (int i = 0; i < N; i++)
                {
                    String r = "";
                    for (int j = 0; j < N; j++)
                    {
                        r += c[i,j].simbolo;
                    }//fin for j
                    matriz.Items.Add(r);//matriz es el nombre de la listbox
                }//fin for i
        }
        void restablecerMat(lab[,] c)
        {
            //restablece el valor de es camino del laberinto
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    c[i,j].esCamino = false;
                }
            }
        }
        void iniciarStructs(lab[,] c)
        {
            //inicializa los valores del laberinto
            //simbolo = .
            //int px = 0 (x del padre)
            //int py = 0 (y del padre)
            //bool esCamino = false
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    c[i, j].simbolo = '.';
                    c[i, j].padre = new Pair<int, int>(0, 0);
                    c[i, j].esCamino = false;
                }//fin for j
            }//fin for i
        }
    }
}

public class Pair<T, U>
{
    public Pair()
    {
    }

    public Pair(T first, U second)
    {
        this.First = first;
        this.Second = second;
    }

    public T First { get; set; }
    public U Second { get; set; }
};