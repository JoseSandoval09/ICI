
namespace LAVENDER_HAZE_SHARP
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
            this.iniciar = new System.Windows.Forms.Button();
            this.matriz = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // iniciar
            // 
            this.iniciar.Location = new System.Drawing.Point(489, 366);
            this.iniciar.Name = "iniciar";
            this.iniciar.Size = new System.Drawing.Size(99, 48);
            this.iniciar.TabIndex = 0;
            this.iniciar.Text = "Generar";
            this.iniciar.UseVisualStyleBackColor = true;
            this.iniciar.Click += new System.EventHandler(this.iniciar_Click);
            // 
            // matriz
            // 
            this.matriz.FormattingEnabled = true;
            this.matriz.ItemHeight = 16;
            this.matriz.Location = new System.Drawing.Point(489, 25);
            this.matriz.Name = "matriz";
            this.matriz.Size = new System.Drawing.Size(260, 308);
            this.matriz.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::LAVENDER_HAZE_SHARP.Properties.Resources.champi;
            this.ClientSize = new System.Drawing.Size(782, 453);
            this.Controls.Add(this.matriz);
            this.Controls.Add(this.iniciar);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button iniciar;
        private System.Windows.Forms.ListBox matriz;
    }
}

