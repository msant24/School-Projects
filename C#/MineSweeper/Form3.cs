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
    public partial class Input : Form
    {
        public static int rows, columns, mines;
        Form4 f = new Form4();

        public Input()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            rows = int.Parse(textBox1.Text);
            columns = int.Parse(textBox2.Text);
            mines = int.Parse(textBox3.Text);
            if (rows * columns < 18 || mines > (rows * columns) / 2)
            {
                f.ShowDialog();
            }
            else
                this.Close();
            
        }
    }
}
