
namespace REGISTRO_TEMPERATURA_CEEH
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Dia = new System.Windows.Forms.TextBox();
            this.Mes = new System.Windows.Forms.TextBox();
            this.Año = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.TEMP = new System.Windows.Forms.Label();
            this.FDR = new System.Windows.Forms.Label();
            this.moda = new System.Windows.Forms.Label();
            this.button4 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(351, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(453, 30);
            this.label1.TabIndex = 0;
            this.label1.Text = "REGISTRO DE TEMPERATURAS";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.HotTrack;
            this.label2.Font = new System.Drawing.Font("Cooper Black", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.White;
            this.label2.Location = new System.Drawing.Point(12, 120);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(425, 35);
            this.label2.TabIndex = 1;
            this.label2.Text = "INGRESA TEMPERATURA";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(84, 176);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(175, 22);
            this.textBox1.TabIndex = 2;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.Highlight;
            this.label3.Font = new System.Drawing.Font("Cooper Black", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.White;
            this.label3.Location = new System.Drawing.Point(533, 120);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(676, 35);
            this.label3.TabIndex = 3;
            this.label3.Text = "INGRESA FECHA DE LA TEMPERATURA 1\r\n";
            // 
            // Dia
            // 
            this.Dia.Location = new System.Drawing.Point(696, 176);
            this.Dia.Name = "Dia";
            this.Dia.Size = new System.Drawing.Size(62, 22);
            this.Dia.TabIndex = 4;
            // 
            // Mes
            // 
            this.Mes.Location = new System.Drawing.Point(806, 176);
            this.Mes.Name = "Mes";
            this.Mes.Size = new System.Drawing.Size(62, 22);
            this.Mes.TabIndex = 5;
            // 
            // Año
            // 
            this.Año.Location = new System.Drawing.Point(909, 176);
            this.Año.Name = "Año";
            this.Año.Size = new System.Drawing.Size(62, 22);
            this.Año.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(702, 219);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 23);
            this.label4.TabIndex = 7;
            this.label4.Text = "DÍA";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(814, 218);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 24);
            this.label5.TabIndex = 8;
            this.label5.Text = "MES";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(928, 218);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(43, 23);
            this.label6.TabIndex = 9;
            this.label6.Text = "AÑO";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Brown;
            this.button1.Font = new System.Drawing.Font("Impact", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.Color.White;
            this.button1.Location = new System.Drawing.Point(44, 219);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(255, 86);
            this.button1.TabIndex = 10;
            this.button1.Text = "REGISTRA TEMPERATURA";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(618, 328);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(177, 114);
            this.button2.TabIndex = 11;
            this.button2.Text = "DESPLIEGA TEMPERATURAS, FECHAS DE REGISTRO.\r\n";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(1041, 355);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(177, 61);
            this.button3.TabIndex = 12;
            this.button3.Text = "NUEVO REGISTRO";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.PapayaWhip;
            this.label7.Font = new System.Drawing.Font("Cooper Black", 13.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(39, 328);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(230, 27);
            this.label7.TabIndex = 13;
            this.label7.Text = "TEMPERATURAS";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.PapayaWhip;
            this.label8.Font = new System.Drawing.Font("Cooper Black", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(291, 328);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(298, 27);
            this.label8.TabIndex = 14;
            this.label8.Text = "FECHAS DE REGISTRO";
            // 
            // TEMP
            // 
            this.TEMP.AutoSize = true;
            this.TEMP.BackColor = System.Drawing.Color.Transparent;
            this.TEMP.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEMP.Location = new System.Drawing.Point(105, 382);
            this.TEMP.Name = "TEMP";
            this.TEMP.Size = new System.Drawing.Size(0, 23);
            this.TEMP.TabIndex = 15;
            // 
            // FDR
            // 
            this.FDR.AutoSize = true;
            this.FDR.BackColor = System.Drawing.Color.Transparent;
            this.FDR.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FDR.Location = new System.Drawing.Point(391, 382);
            this.FDR.Name = "FDR";
            this.FDR.Size = new System.Drawing.Size(0, 23);
            this.FDR.TabIndex = 16;
            // 
            // moda
            // 
            this.moda.AutoSize = true;
            this.moda.BackColor = System.Drawing.Color.PapayaWhip;
            this.moda.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.moda.Location = new System.Drawing.Point(701, 528);
            this.moda.Name = "moda";
            this.moda.Size = new System.Drawing.Size(0, 23);
            this.moda.TabIndex = 17;
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(833, 355);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(177, 61);
            this.button4.TabIndex = 18;
            this.button4.Text = "SACAR MODA";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1286, 783);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.moda);
            this.Controls.Add(this.FDR);
            this.Controls.Add(this.TEMP);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Año);
            this.Controls.Add(this.Mes);
            this.Controls.Add(this.Dia);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Dia;
        private System.Windows.Forms.TextBox Mes;
        private System.Windows.Forms.TextBox Año;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label TEMP;
        private System.Windows.Forms.Label FDR;
        private System.Windows.Forms.Label moda;
        private System.Windows.Forms.Button button4;
    }
}

