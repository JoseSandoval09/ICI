﻿
namespace EjercicioCuboDeUnValor
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
            this.Numero = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Cubo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label1.Font = new System.Drawing.Font("Britannic Bold", 18F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(230, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(335, 35);
            this.label1.TabIndex = 0;
            this.label1.Text = "CALCULADOR DE CUBOS";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(137, 135);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(249, 17);
            this.label2.TabIndex = 1;
            this.label2.Text = "Ingresa un numero para sacar el cubo";
            // 
            // Numero
            // 
            this.Numero.Location = new System.Drawing.Point(427, 135);
            this.Numero.Name = "Numero";
            this.Numero.Size = new System.Drawing.Size(177, 22);
            this.Numero.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(430, 195);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(173, 29);
            this.button1.TabIndex = 3;
            this.button1.Text = "CONVIERTE";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(181, 261);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(141, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "El numero al cubo es";
            // 
            // Cubo
            // 
            this.Cubo.Location = new System.Drawing.Point(427, 261);
            this.Cubo.Name = "Cubo";
            this.Cubo.Size = new System.Drawing.Size(177, 22);
            this.Cubo.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Cubo);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Numero);
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
        private System.Windows.Forms.TextBox Numero;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Cubo;
    }
}

