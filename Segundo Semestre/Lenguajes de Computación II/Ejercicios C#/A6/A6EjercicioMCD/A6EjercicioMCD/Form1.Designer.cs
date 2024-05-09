
namespace A6EjercicioMCD
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
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Num2 = new System.Windows.Forms.TextBox();
            this.Num1 = new System.Windows.Forms.TextBox();
            this.MaximoComunDivisor = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Green;
            this.label1.Location = new System.Drawing.Point(215, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(356, 35);
            this.label1.TabIndex = 0;
            this.label1.Text = "MAXIMO COMUN DIVISOR";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(261, 111);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(269, 25);
            this.label2.TabIndex = 1;
            this.label2.Text = "Ingresa 2 numeros enteros";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(291, 200);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 17);
            this.label3.TabIndex = 2;
            this.label3.Text = "Numero 1";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(486, 200);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 17);
            this.label4.TabIndex = 3;
            this.label4.Text = "Numero 2";
            // 
            // Num2
            // 
            this.Num2.Location = new System.Drawing.Point(467, 175);
            this.Num2.Name = "Num2";
            this.Num2.Size = new System.Drawing.Size(116, 22);
            this.Num2.TabIndex = 4;
            // 
            // Num1
            // 
            this.Num1.Location = new System.Drawing.Point(266, 175);
            this.Num1.Name = "Num1";
            this.Num1.Size = new System.Drawing.Size(116, 22);
            this.Num1.TabIndex = 5;
            // 
            // MaximoComunDivisor
            // 
            this.MaximoComunDivisor.Font = new System.Drawing.Font("Eras Demi ITC", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MaximoComunDivisor.ForeColor = System.Drawing.Color.Blue;
            this.MaximoComunDivisor.Location = new System.Drawing.Point(322, 262);
            this.MaximoComunDivisor.Name = "MaximoComunDivisor";
            this.MaximoComunDivisor.Size = new System.Drawing.Size(208, 97);
            this.MaximoComunDivisor.TabIndex = 6;
            this.MaximoComunDivisor.Text = "MCD";
            this.MaximoComunDivisor.UseVisualStyleBackColor = true;
            this.MaximoComunDivisor.Click += new System.EventHandler(this.MCD_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.MaximoComunDivisor);
            this.Controls.Add(this.Num1);
            this.Controls.Add(this.Num2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
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
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Num2;
        private System.Windows.Forms.TextBox Num1;
        private System.Windows.Forms.Button MaximoComunDivisor;
    }
}

