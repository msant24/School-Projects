using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PA6_Draft
{
    public partial class Form1 : Form
    {
        internal int x;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked) x = 1;
            if (radioButton2.Checked) x = 2;
            if (radioButton3.Checked) x = 3;
            if (radioButton4.Checked) x = 4;
        }
    }
}
