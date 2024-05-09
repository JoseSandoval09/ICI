
namespace GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.turno = new System.Windows.Forms.Label();
            this.reiniciar = new System.Windows.Forms.Button();
            this.salir = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // turno
            // 
            this.turno.AutoSize = true;
            this.turno.BackColor = System.Drawing.Color.Wheat;
            this.turno.Font = new System.Drawing.Font("Microsoft YaHei", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.turno.ForeColor = System.Drawing.Color.Black;
            this.turno.Location = new System.Drawing.Point(494, 28);
            this.turno.Name = "turno";
            this.turno.Size = new System.Drawing.Size(183, 40);
            this.turno.TabIndex = 0;
            this.turno.Text = "YE VS PETE";
            // 
            // reiniciar
            // 
            this.reiniciar.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.reiniciar.ForeColor = System.Drawing.Color.Red;
            this.reiniciar.Image = global::GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT.Properties.Resources.champi;
            this.reiniciar.Location = new System.Drawing.Point(821, 431);
            this.reiniciar.Name = "reiniciar";
            this.reiniciar.Size = new System.Drawing.Size(184, 50);
            this.reiniciar.TabIndex = 1;
            this.reiniciar.Text = "REINICIAR";
            this.reiniciar.UseVisualStyleBackColor = true;
            this.reiniciar.Click += new System.EventHandler(this.reiniciar_Click);
            // 
            // salir
            // 
            this.salir.BackgroundImage = global::GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT.Properties.Resources.coco;
            this.salir.Font = new System.Drawing.Font("Microsoft YaHei", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.salir.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.salir.Location = new System.Drawing.Point(821, 487);
            this.salir.Name = "salir";
            this.salir.Size = new System.Drawing.Size(184, 50);
            this.salir.TabIndex = 2;
            this.salir.Text = "SALIR";
            this.salir.UseVisualStyleBackColor = true;
            this.salir.Click += new System.EventHandler(this.salir_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::GATO3D_PSEGUNDOPARCIAL_DOERXRJSDSDT.Properties.Resources.beverly;
            this.ClientSize = new System.Drawing.Size(1062, 673);
            this.Controls.Add(this.salir);
            this.Controls.Add(this.reiniciar);
            this.Controls.Add(this.turno);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label turno;
        private System.Windows.Forms.Button reiniciar;
        private System.Windows.Forms.Button salir;
    }
}

