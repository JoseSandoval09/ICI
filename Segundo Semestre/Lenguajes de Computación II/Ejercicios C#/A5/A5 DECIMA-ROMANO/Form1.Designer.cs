
namespace A5_DECIMA_ROMANO
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Decimal = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.NumRomano = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(245, 40);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(290, 35);
            this.label1.TabIndex = 0;
            this.label1.Text = "DECIMAL>>ROMANO";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Times New Roman", 13.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(88, 140);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(271, 27);
            this.label2.TabIndex = 1;
            this.label2.Text = "Ingresa el número decimal";
            // 
            // Decimal
            // 
            this.Decimal.Location = new System.Drawing.Point(425, 145);
            this.Decimal.Name = "Decimal";
            this.Decimal.Size = new System.Drawing.Size(216, 22);
            this.Decimal.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Arial Rounded MT Bold", 16.2F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(425, 200);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(215, 73);
            this.button1.TabIndex = 3;
            this.button1.Text = "CONVIERTE A ROMANO!!";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // NumRomano
            // 
            this.NumRomano.AutoSize = true;
            this.NumRomano.Location = new System.Drawing.Point(422, 320);
            this.NumRomano.Name = "NumRomano";
            this.NumRomano.Size = new System.Drawing.Size(0, 17);
            this.NumRomano.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.NumRomano);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Decimal);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox Decimal;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label NumRomano;
    }
}

