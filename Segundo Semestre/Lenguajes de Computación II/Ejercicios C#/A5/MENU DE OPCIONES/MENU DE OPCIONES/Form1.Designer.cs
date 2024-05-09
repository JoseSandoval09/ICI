
namespace MENU_DE_OPCIONES
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
            this.Cuadrado = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.Cubos = new System.Windows.Forms.Button();
            this.ParImpar = new System.Windows.Forms.Button();
            this.ImparPar = new System.Windows.Forms.Label();
            this.Cuadrados = new System.Windows.Forms.Label();
            this.Cubo = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Font = new System.Drawing.Font("Showcard Gothic", 19.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.label1.Location = new System.Drawing.Point(220, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(340, 42);
            this.label1.TabIndex = 0;
            this.label1.Text = "MENU DE OPCIONEES";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Consolas", 13.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(34, 94);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(233, 28);
            this.label2.TabIndex = 1;
            this.label2.Text = "Inserta un numero";
            // 
            // Numero
            // 
            this.Numero.Location = new System.Drawing.Point(317, 94);
            this.Numero.Name = "Numero";
            this.Numero.Size = new System.Drawing.Size(229, 22);
            this.Numero.TabIndex = 2;
            // 
            // Cuadrado
            // 
            this.Cuadrado.Font = new System.Drawing.Font("Comic Sans MS", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Cuadrado.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.Cuadrado.Location = new System.Drawing.Point(39, 204);
            this.Cuadrado.Name = "Cuadrado";
            this.Cuadrado.Size = new System.Drawing.Size(225, 85);
            this.Cuadrado.TabIndex = 3;
            this.Cuadrado.Text = "OPCIÓN 1>>CUADRADO DEL NUMERO";
            this.Cuadrado.UseVisualStyleBackColor = true;
            this.Cuadrado.Click += new System.EventHandler(this.Cuadrado_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Consolas", 13.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Red;
            this.label3.Location = new System.Drawing.Point(273, 151);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(220, 28);
            this.label3.TabIndex = 4;
            this.label3.Text = "Elige una opción";
            // 
            // Cubos
            // 
            this.Cubos.Font = new System.Drawing.Font("Comic Sans MS", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Cubos.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.Cubos.Location = new System.Drawing.Point(289, 204);
            this.Cubos.Name = "Cubos";
            this.Cubos.Size = new System.Drawing.Size(225, 85);
            this.Cubos.TabIndex = 5;
            this.Cubos.Text = "OPCIÓN 2>>CUBO DEL NUMERO";
            this.Cubos.UseVisualStyleBackColor = true;
            this.Cubos.Click += new System.EventHandler(this.button1_Click);
            // 
            // ParImpar
            // 
            this.ParImpar.Font = new System.Drawing.Font("Comic Sans MS", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ParImpar.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.ParImpar.Location = new System.Drawing.Point(542, 204);
            this.ParImpar.Name = "ParImpar";
            this.ParImpar.Size = new System.Drawing.Size(225, 85);
            this.ParImpar.TabIndex = 6;
            this.ParImpar.Text = "OPCIÓN 3>>¿PAR O IMPAR?";
            this.ParImpar.UseVisualStyleBackColor = true;
            this.ParImpar.Click += new System.EventHandler(this.button2_Click);
            // 
            // ImparPar
            // 
            this.ImparPar.AutoSize = true;
            this.ImparPar.BackColor = System.Drawing.Color.Fuchsia;
            this.ImparPar.Font = new System.Drawing.Font("Microsoft YaHei", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ImparPar.Location = new System.Drawing.Point(578, 98);
            this.ImparPar.Name = "ImparPar";
            this.ImparPar.Size = new System.Drawing.Size(0, 25);
            this.ImparPar.TabIndex = 7;
            // 
            // Cuadrados
            // 
            this.Cuadrados.AutoSize = true;
            this.Cuadrados.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Cuadrados.Location = new System.Drawing.Point(143, 351);
            this.Cuadrados.Name = "Cuadrados";
            this.Cuadrados.Size = new System.Drawing.Size(0, 24);
            this.Cuadrados.TabIndex = 8;
            // 
            // Cubo
            // 
            this.Cubo.AutoSize = true;
            this.Cubo.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Cubo.Location = new System.Drawing.Point(394, 351);
            this.Cubo.Name = "Cubo";
            this.Cubo.Size = new System.Drawing.Size(0, 24);
            this.Cubo.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Cubo);
            this.Controls.Add(this.Cuadrados);
            this.Controls.Add(this.ImparPar);
            this.Controls.Add(this.ParImpar);
            this.Controls.Add(this.Cubos);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Cuadrado);
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
        private System.Windows.Forms.Button Cuadrado;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Cubos;
        private System.Windows.Forms.Button ParImpar;
        private System.Windows.Forms.Label ImparPar;
        private System.Windows.Forms.Label Cuadrados;
        private System.Windows.Forms.Label Cubo;
    }
}

