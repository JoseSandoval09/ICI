
namespace A6TablasMultilplicar
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
            this.Num = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Multi = new System.Windows.Forms.ListBox();
            this.TablaM = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.label1.Font = new System.Drawing.Font("Cooper Black", 22.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Purple;
            this.label1.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.label1.Location = new System.Drawing.Point(132, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(557, 44);
            this.label1.TabIndex = 0;
            this.label1.Text = "TABLAS DE MULTIPLICAR ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Bell MT", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(100, 91);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(257, 24);
            this.label2.TabIndex = 1;
            this.label2.Text = "Ingresa un numero del 1-15 ";
            // 
            // Num
            // 
            this.Num.Location = new System.Drawing.Point(417, 93);
            this.Num.Name = "Num";
            this.Num.Size = new System.Drawing.Size(244, 22);
            this.Num.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(357, 202);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 17);
            this.label3.TabIndex = 3;
            // 
            // Multi
            // 
            this.Multi.Font = new System.Drawing.Font("Consolas", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Multi.FormattingEnabled = true;
            this.Multi.ItemHeight = 22;
            this.Multi.Location = new System.Drawing.Point(54, 131);
            this.Multi.Name = "Multi";
            this.Multi.Size = new System.Drawing.Size(342, 312);
            this.Multi.TabIndex = 4;
            this.Multi.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // TablaM
            // 
            this.TablaM.Font = new System.Drawing.Font("Courier New", 13.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TablaM.Location = new System.Drawing.Point(450, 233);
            this.TablaM.Name = "TablaM";
            this.TablaM.Size = new System.Drawing.Size(255, 74);
            this.TablaM.TabIndex = 5;
            this.TablaM.Text = "TABLA DE MULTIPLICACION";
            this.TablaM.UseVisualStyleBackColor = true;
            this.TablaM.Click += new System.EventHandler(this.TablaM_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.TablaM);
            this.Controls.Add(this.Multi);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Num);
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
        private System.Windows.Forms.TextBox Num;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox Multi;
        private System.Windows.Forms.Button TablaM;
    }
}

