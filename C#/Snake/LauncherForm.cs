using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PA5_Draft
{
    public partial class LauncherForm : Form
    {
        int NumberOfApples;
        int Obstacle;
        public LauncherForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NumberOfApples = (int)numericUpDown1.Value;
            Obstacle = (int)comboBox1.SelectedIndex;
            if (comboBox1.SelectedIndex == -1) return;
            Console.WriteLine(Obstacle);
            MainForm f = new MainForm(NumberOfApples, Obstacle);
            this.Hide();
            f.ShowDialog();
            this.Close();
        }
    }
}
