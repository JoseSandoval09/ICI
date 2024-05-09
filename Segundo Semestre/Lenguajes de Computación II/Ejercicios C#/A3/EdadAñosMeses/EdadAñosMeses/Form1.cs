using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EdadAñosMeses
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void EdadMeses_Click(object sender, EventArgs e)
        {
            float Agemeses = Single.Parse(Edad.Text) * 12;
            Meses.Text = Agemeses.ToString();
        }
    }
}
