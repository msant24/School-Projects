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
    public partial class MainForm : Form
    {
        Boolean sec = true;
        private int Step = 1;
        private readonly SnakeGame Game;
        int appleCount = 0;
        public MainForm(int NumberOfApples, int Obstacle)
        {
            InitializeComponent();
            Game = new SnakeGame(new System.Drawing.Point((Field.Width - 20) / 2, Field.Height / 2), 40, NumberOfApples, Field.Size, Obstacle);
            Field.Image = new Bitmap(Field.Width, Field.Height);
            Game.EatAndGrow += Game_EatAndGrow;
            Game.HitWallAndLose += Game_HitWallAndLose;
            Game.HitSnakeAndLose += Game_HitSnakeAndLose;
        }

        private void Game_HitWallAndLose()
        {
            System.Media.SoundPlayer player = new System.Media.SoundPlayer("D:/Shool Stuff/Fall 2020/COP 4226/PA5 Draft/PA5 Draft/Right Cross-SoundBible.com-1721311663.wav");
            Gameover f = new Gameover(appleCount);
            player.Play();
            mainTimer.Stop();
            Field.Refresh();
            f.ShowDialog();
        }
        private void Game_HitSnakeAndLose()
        {
            System.Media.SoundPlayer player = new System.Media.SoundPlayer("D:/Shool Stuff/Fall 2020/COP 4226/PA5 Draft/PA5 Draft/Jab-SoundBible.com-1806727891.wav");
            Gameover f = new Gameover(appleCount);
            player.Play();
            mainTimer.Stop();
            Field.Refresh();
            f.ShowDialog();
        }

        private void Game_EatAndGrow()
        {
            System.Media.SoundPlayer player = new System.Media.SoundPlayer("D:/Shool Stuff/Fall 2020/COP 4226/PA5 Draft/PA5 Draft/Biting Apple-SoundBible.com-415478302.wav");
            appleCount++;
            player.Play();
            switch (appleCount)
            {
                case 10:
                    Step = 2;
                    toolStripStatusLabel1.Text = "Step = 2";
                    toolStripProgressBar1.Value++;
                    break;
                case 20:
                    Step = 3;
                    toolStripStatusLabel1.Text = "Step = 3";
                    toolStripProgressBar1.Value++;
                    break;
                case 30:
                    Step = 4;
                    toolStripStatusLabel1.Text = "Step = 4";
                    toolStripProgressBar1.Value++;
                    break;
                case 40:
                    Step = 5;
                    toolStripStatusLabel1.Text = "Step = 5";
                    toolStripProgressBar1.Value++;
                    break;
                case 50:
                    Step = 6;
                    toolStripStatusLabel1.Text = "Step = 6";
                    toolStripProgressBar1.Value++;
                    break;
                case 60:
                    Step = 7;
                    toolStripStatusLabel1.Text = "Step = 7";
                    toolStripProgressBar1.Value++;
                    break;
                case 70:
                    Step = 8;
                    toolStripStatusLabel1.Text = "Step = 8";
                    toolStripProgressBar1.Value++;
                    break;
                case 80:
                    Step = 9;
                    toolStripStatusLabel1.Text = "Step = 9";
                    toolStripProgressBar1.Value++;
                    break;
                case 90:
                    Step = 10;
                    toolStripStatusLabel1.Text = "Step = 10";
                    toolStripProgressBar1.Value++;
                    break;
                default:
                    return;
            }
        }

        private void MainTimer_Tick(object sender, EventArgs e)
        {
            if (sec == true) sec = false;
            else sec = true;
            Game.Move(Step);
            Field.Invalidate();
        }

        private void Field_Paint(object sender, PaintEventArgs e)
        {
            Pen PenForObstacles = new Pen(Color.FromArgb(40, 40, 40), 2);
            Pen PenForSnake = new Pen(Color.FromArgb(100, 100, 100), 2);
            Brush BackGroundBrush = new SolidBrush(Color.FromArgb(150, 250, 150));
            Brush AppleBrush = new SolidBrush(Color.FromArgb(250, 50, 50));
            if(sec) AppleBrush = new SolidBrush(Color.FromArgb(150, 250, 150));
            else AppleBrush = new SolidBrush(Color.FromArgb(250, 50, 50));
            using (Graphics g = Graphics.FromImage(Field.Image))
            {
                g.FillRectangle(BackGroundBrush, new Rectangle(0, 0, Field.Width, Field.Height));
                foreach (Point Apple in Game.Apples)
                    g.FillEllipse(AppleBrush, new Rectangle(Apple.X - SnakeGame.AppleSize / 2, Apple.Y - SnakeGame.AppleSize / 2,
                        SnakeGame.AppleSize, SnakeGame.AppleSize));
                foreach (LineSeg Obstacle in Game.Obstacles)
                    g.DrawLine(PenForObstacles, new System.Drawing.Point(Obstacle.Start.X, Obstacle.Start.Y)
                        , new System.Drawing.Point(Obstacle.End.X, Obstacle.End.Y));
                foreach (LineSeg Body in Game.SnakeBody)
                    g.DrawLine(PenForSnake, new System.Drawing.Point((int)Body.Start.X, (int)Body.Start.Y)
                        , new System.Drawing.Point((int)Body.End.X, (int)Body.End.Y));
            }
        }



        private void Snakes_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Up:
                    Game.Move(Step, Direction.UP);
                    break;
                case Keys.Down:
                    Game.Move(Step, Direction.DOWN);
                    break;
                case Keys.Left:
                    Game.Move(Step, Direction.LEFT);
                    break;
                case Keys.Right:
                    Game.Move(Step, Direction.RIGHT);
                    break;
            }
        }

        private void Field_Click(object sender, EventArgs e)
        {
            if (mainTimer.Enabled)
                mainTimer.Stop();
            else mainTimer.Start();
        }
    }
}
