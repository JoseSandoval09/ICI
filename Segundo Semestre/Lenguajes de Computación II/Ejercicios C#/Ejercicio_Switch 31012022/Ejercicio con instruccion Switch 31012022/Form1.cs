using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio_con_instruccion_Switch_31012022
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int cm, dm, um, cent, dec, r1, cant_org;
            int uni;
            string cant_texto;
            cant_org = Convert.ToInt32(Cantidad.Text);
            if(cant_org<1 || cant_org > 1000000)
            {
                MessageBox.Show("El valor tiene que ser solo entre 1-1,000,000 ");
                
            }
            else
            {
                MessageBox.Show("El valor esta siendo convertido, espera.");
                cm = cant_org / 100000;
                r1 = cant_org % 100000;
                dm = r1 / 10000;
                r1 = r1 % 10000;
                um = r1 / 1000;
                r1 = r1 % 1000;
                cent = r1 / 100;
                r1 = r1 % 100;
                dec = r1 / 10;
                uni = r1 % 10;
                cant_texto = "";

                //CANTIDADES >1000
                switch (cm)
                {
                    case 1:{
                            if (dm == 0 && um == 0)
                            {
                                cant_texto = "Cien ";
                            }
                            else
                            {
                                cant_texto = "Ciento ";

                            }
                            break;
                    }
                    case 2: cant_texto = "Doscientos "; break;
                    case 3: cant_texto = "Trecientos "; break;
                    case 4: cant_texto = "Cuatrocientos "; break;
                    case 5: cant_texto = "Quinientos "; break;
                    case 6: cant_texto = "Seiscientos "; break;
                    case 7: cant_texto = "Setecientos "; break;
                    case 8: cant_texto = "Ochocientos "; break;
                    case 9: cant_texto = "Novecientos "; break;
                    case 10: cant_texto = "Un millon "; break;
                }

                switch (dm)
                {
                    case 1:
                        switch (um)
                        {
                            case 0: cant_texto = cant_texto + "Diez"; break;
                            case 1: cant_texto = cant_texto + "Once"; break;
                            case 2: cant_texto = cant_texto + "Doce"; break;
                            case 3: cant_texto = cant_texto + "Trece"; break;
                            case 4: cant_texto = cant_texto + "Catorce"; break;
                            case 5: cant_texto = cant_texto + "Quince"; break;
                            case 6: cant_texto = cant_texto + "Dieciseis"; break;
                            case 7: cant_texto = cant_texto + "Diecisiete"; break;
                            case 8: cant_texto = cant_texto + "Dieciocho"; break;
                            case 9: cant_texto = cant_texto + "Diecinueve"; break;
                        }
                        break;
                    case 2:
                        if (um == 0)
                        {
                            cant_texto = cant_texto + "Veinte";
                        }
                        else
                        {
                            cant_texto = cant_texto + "Veinti";
                        }
                        break;
                    case 3: cant_texto = cant_texto + "Treinta"; break;
                    case 4: cant_texto = cant_texto + "Cuarenta"; break;
                    case 5: cant_texto = cant_texto + "Cincuenta"; break;
                    case 6: cant_texto = cant_texto + "Sesenta"; break;
                    case 7: cant_texto = cant_texto + "Setenta"; break;
                    case 8: cant_texto = cant_texto + "Ochenta"; break;
                    case 9: cant_texto = cant_texto + "Noventa"; break;
                }
                if(um!= 0 && dm >= 3 && dm <= 9)
                {
                    cant_texto = cant_texto + "y";
                }
                if (dm != 1)
                {
                    switch (um)
                    {
                        case 1:cant_texto = cant_texto + "Un"; break;
                        case 2:cant_texto = cant_texto + "Dos"; break;
                        case 3: cant_texto = cant_texto + "Tres"; break;
                        case 4: cant_texto = cant_texto + "Cuatro"; break;
                        case 5: cant_texto = cant_texto + "Cinco"; break;
                        case 6: cant_texto = cant_texto + "Seis"; break;
                        case 7: cant_texto = cant_texto + "Siete"; break;
                        case 8: cant_texto = cant_texto + "Ocho"; break;
                        case 9: cant_texto = cant_texto + "Nueve"; break;
                    }
                }
                
                if(cant_org >=1000 && cant_org != 1000000)
                {
                    cant_texto = cant_texto + "Mil";

                }
                //Cantidades <1000

                switch (cent)
                {
                    case 1:
                        {
                            if (dec == 0 && uni ==0)
                            {
                                cant_texto = cant_texto + "Cien";
                            }
                            else
                            {
                                cant_texto = cant_texto + "Ciento";
                            }
                            break;

                        }
                    case 2: cant_texto = cant_texto + "Docientos"; break;
                    case 3: cant_texto = cant_texto + "Trecientos"; break;
                    case 4: cant_texto = cant_texto + "Cuatrocientos"; break;
                    case 5: cant_texto = cant_texto + "Quinientos"; break;
                    case 6: cant_texto = cant_texto + "Seiscentos"; break;
                    case 7: cant_texto = cant_texto + "Setecientos"; break;
                    case 8: cant_texto = cant_texto + "Ochocientos"; break;
                    case 9: cant_texto = cant_texto + "Novecientos"; break;
                    case 10: cant_texto = cant_texto + "Un millon"; break;


                }
                switch (dec)
                {
                    case 1:
                        {
                            switch (uni)
                            {
                                case 0: cant_texto = cant_texto + "Diez"; break;
                                case 1: cant_texto = cant_texto + "Once"; break;
                                case 2: cant_texto = cant_texto + "Doce"; break;
                                case 3: cant_texto = cant_texto + "Trece"; break;
                                case 4: cant_texto = cant_texto + "Catorce"; break;
                                case 5: cant_texto = cant_texto + "Quince"; break;
                                case 6: cant_texto = cant_texto + "Dieciseis"; break;
                                case 7: cant_texto = cant_texto + "Diecisiete"; break;
                                case 8: cant_texto = cant_texto + "Dieciocho"; break;
                                case 9: cant_texto = cant_texto + "Diecinueve"; break;

                            }
                            break;
                        }
                    case 2:
                        {
                            if (uni == 0)
                            {
                                cant_texto = cant_texto + "Veinte";

                            }
                            else
                            {
                                cant_texto = cant_texto + "Veinti";
                            }
                            break;

                        }
                        
                    case 3: cant_texto = cant_texto + "Treinta"; break;
                    case 4: cant_texto = cant_texto + "Cuarenta"; break;
                    case 5: cant_texto = cant_texto + "Cincuenta"; break;
                    case 6: cant_texto = cant_texto + "Sesenta"; break;
                    case 7: cant_texto = cant_texto + "Setenta"; break;
                    case 8: cant_texto = cant_texto + "Ochenta"; break;
                    case 9: cant_texto = cant_texto + "Noventa"; break;
                }
                if(uni !=0 && dec>=3 && dec <= 3)
                {
                    cant_texto = cant_texto + "Y";
                }
                if (dec != 1)
                {
                    switch (uni)
                    {
                        case 1: cant_texto = cant_texto + "Un"; break;
                        case 2: cant_texto = cant_texto + "Dos"; break;
                        case 3: cant_texto = cant_texto + "Tres"; break;
                        case 4: cant_texto = cant_texto + "Cuatro"; break;
                        case 5: cant_texto = cant_texto + "Cinco"; break;
                        case 6: cant_texto = cant_texto + "Seis"; break;
                        case 7: cant_texto = cant_texto + "Siete"; break;
                        case 8: cant_texto = cant_texto + "Ocho"; break;
                        case 9: cant_texto = cant_texto + "Nueve"; break;
                    }
                }

                label2.Text = cant_texto;




            }




            }
        }
    }

