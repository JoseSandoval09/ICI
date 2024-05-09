
namespace EdadAñosMeses
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
            this.Edad = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.EdadMeses = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Meses = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(231, 110);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(162, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ingresa tu edad en años";
            // 
            // Edad
            // 
            this.Edad.Location = new System.Drawing.Point(424, 105);
            this.Edad.Name = "Edad";
            this.Edad.Size = new System.Drawing.Size(170, 22);
            this.Edad.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.InfoText;
            this.label2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.label2.Font = new System.Drawing.Font("Rockwell Condensed", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label2.Location = new System.Drawing.Point(319, 30);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(158, 31);
            this.label2.TabIndex = 2;
            this.label2.Text = "Edad en meses";
            // 
            // EdadMeses
            // 
            this.EdadMeses.Location = new System.Drawing.Point(455, 166);
            this.EdadMeses.Name = "EdadMeses";
            this.EdadMeses.Size = new System.Drawing.Size(121, 40);
            this.EdadMeses.TabIndex = 3;
            this.EdadMeses.Text = "Convierte";
            this.EdadMeses.UseVisualStyleBackColor = true;
            this.EdadMeses.Click += new System.EventHandler(this.EdadMeses_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(263, 227);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(106, 17);
            this.label3.TabIndex = 4;
            this.label3.Text = "Edad en meses";
            // 
            // Meses
            // 
            this.Meses.Location = new System.Drawing.Point(424, 227);
            this.Meses.Name = "Meses";
            this.Meses.Size = new System.Drawing.Size(170, 22);
            this.Meses.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Meses);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.EdadMeses);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Edad);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Edad;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button EdadMeses;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox Meses;
    }
}

