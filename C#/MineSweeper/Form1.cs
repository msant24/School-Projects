using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MineSweeper
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Play(object sender, EventArgs e)
        {
            
            int row=0, col=0,mines = 0;//row*col >=18, mines <= row*col/2
            String text = "";
            Form2 f = null;
            Input f2 = null;
            if (easy.Checked)
            {
                row = col = 9;
                mines = 10;
                text = "Easy";
            }
            else if (medium.Checked)
            {
                row = col = 16;
                mines = 40;
                text = "Medium";
            }
            else if (expert.Checked)
            {
                row = 30;
                col = 16;
                mines = 99;
                text = "Expert";
            }
            else if (custom.Checked)
            {
                f2 = new Input();
                f2.ShowDialog();
                row = Input.rows;
                col = Input.columns;
                mines = Input.mines;
            }
            else
            return;
            int size = Math.Min(30, 1000 / Math.Max(row, col));
            f = new Form2(text, row, col, size,mines);
            f.Show();
            textBox1_MouseMove(textBox1, null);

        }

        private void menuStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void textBox1_MouseMove(object sender, MouseEventArgs e)
        {
            int games = 0;
            for (int i = 0; i < Application.OpenForms.Count; i++)
            {
                if (Application.OpenForms[i].Visible == true)
                    games++;
            }
            games = games - 1;
            textBox1.ReadOnly = true;
            textBox1.Text = "" + games;
        }

        private void button1_MouseMove(object sender, MouseEventArgs e)
        {
            textBox1_MouseMove(textBox1, null);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            string playername = textBox1.Text;
        }

        private void custom_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = Application.OpenForms.Count - 1; i >= 0; i--)
            {
                if (Application.OpenForms[i].Name != "MainForm")
                    Application.OpenForms[i].Close();
            }
        }

        private void easyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int row = 0, col = 0, mines = 0;
            String text = "";
            Form2 f = null;
            row = col = 9;
            mines = 10;
            text = "Easy";
            int size = Math.Min(30, 1000 / Math.Max(row, col));
            f = new Form2(text, row, col, size, mines);
            f.Show();
            textBox1_MouseMove(textBox1, null);
        }

        private void mediumToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int row = 0, col = 0, mines = 0;
            String text = "";
            Form2 f = null;
            row = col = 16;
            mines = 40;
            text = "Medium";
            int size = Math.Min(30, 1000 / Math.Max(row, col));
            f = new Form2(text, row, col, size, mines);
            f.Show();
            textBox1_MouseMove(textBox1, null);
        }

        private void hardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int row = 0, col = 0, mines = 0;
            String text = "";
            Form2 f = null;
            row = 30;
            col = 16;
            mines = 99;
            text = "Expert";
            int size = Math.Min(30, 1000 / Math.Max(row, col));
            f = new Form2(text, row, col, size, mines);
            f.Show();
            textBox1_MouseMove(textBox1, null);
        }

        private void closeAllGamesToolStripMenuItem_Click(object sender, EventArgs e)
        {

            for (int i = Application.OpenForms.Count - 1; i >= 0; i--)
            {
                if (Application.OpenForms[i].Name != "MainForm")
                    Application.OpenForms[i].Close();
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }
    }
        
}
