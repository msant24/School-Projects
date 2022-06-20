using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Simple_Calc
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, EventArgs e)
        {
            Button b = (Button)sender;
            result_Box.Text = result_Box.Text + b.Text;
        }

        private void result_Box_Click(object sender, EventArgs e)
        {
            result_Box.Text = "";
        }

        private void Enter_Click(object sender, EventArgs e)
        {
            result_Box.Text = Parentheses(result_Box.Text);
        }

        private string Parentheses(string text)
        {
            while (text.Contains('(') && text.Contains(')'))
            {
                int openIndex = 0;
                int closeIndex = 0;

                for (int i = 0; i < text.Length; i++)
                {
                    if (text[i] == '(')
                    {
                        openIndex = i;
                    }
                    if (text[i] == ')')
                    {
                        closeIndex = i;

                        text = text.Remove(openIndex, closeIndex - openIndex + 1).Insert(openIndex, SolveParentheses(openIndex, closeIndex, text));

                        break;
                    }
                }
            }
            
            

            for (int i = 1; i < text.Length; i++)
            {
                if (text[i] == '-' && (text[i - 1] == '*' || text[i - 1] == '/'))
                {
                    for(int j = i - 1; j >= 0; j--)
                    {
                        if (text[j] == '+')
                        {
                            StringBuilder text1 = new StringBuilder(text);
                            text1[j] = '-';
                            text = text1.ToString();
                            text = text.Remove(i, 1);
                            break;
                        }
                        else if(text[j] == '-')
                        {
                            StringBuilder text1 = new StringBuilder(text);
                            text1[j] = '+';
                            text = text1.ToString();
                            text = text.Remove(i, 1);
                            break;
                        } 
                    }
                }
            }
            if (text[0] == '-')
            {
                text = '0' + text;
            }

            return Calculate(text);
        }

        private string SolveParentheses(int openIndex, int closeIndex, string text)
        {
            string bracketAnswer = Calculate(text.Substring(openIndex + 1, closeIndex - openIndex - 1));

            return bracketAnswer;
        }

        public string Calculate(string text) 
        {
            double finalAnswer = AddandSubstract(text);

            return finalAnswer.ToString();
        }

        public double AddandSubstract(string text1)
        {
            string[] text = text1.Split('-');
            List<string> textList = new List<string>();

            for (int i = 0; i < text.Length; i++)
            {
                textList.Add(text[i]);
                if (i != text.Length - 1)
                {
                    textList.Add("-");
                }
            }

            for (int i = 0; i < textList.Count; i++)
            {
                if (textList[i].Contains('+') && textList[i].Length > 1)
                {
                    string[] textPart = textList[i].Split('+');

                    textList.RemoveAt(i);

                    for (int j = textPart.Length - 1; j >= 0; j--)
                    {
                        textList.Insert(i, textPart[j]);
                        if (j != 0)
                        {
                            textList.Insert(i, "+");
                        }
                    }


                }
            }

            double total;
            if (textList[0].Contains('*') || textList[0].Contains('/'))
            {
                total = DivideAndMultiply(textList[0]);
            }
            else
            {
                total = Convert.ToDouble(textList[0]);
            }
            for (int i = 2; i < textList.Count; i += 2)
            {
                if(textList[i - 1] == "-")
                {
                    total = total - DivideAndMultiply(textList[i]);
                }
                else if (textList[i - 1] == "+")
                {
                    total = total + DivideAndMultiply(textList[i]);
                }

            }
            return total;
        }

        private double DivideAndMultiply(string text1)
        {
            string[] text = text1.Split('*');
            List<string> textList = new List<string>();

            for (int i = 0; i < text.Length; i++)
            {
                textList.Add(text[i]);
                if (i != text.Length - 1)
                {
                    textList.Add("*");
                }
            }

            for (int i = 0; i < textList.Count; i++)
            {
                if (textList[i].Contains('/') && textList[i].Length > 1)
                {
                    string[] textPart = textList[i].Split('/');

                    textList.RemoveAt(i);

                    for (int j = textPart.Length - 1; j >= 0; j--)
                    {
                        textList.Insert(i, textPart[j]);
                        if (j != 0)
                        {
                            textList.Insert(i, "/");
                        }
                    }


                }
            }

            double total = Convert.ToDouble(textList[0]);
            for (int i = 2; i < textList.Count; i += 2)
            {
                if (textList[i - 1] == "/")
                {
                    total = total / Convert.ToDouble(textList[i]);
                }
                else if (textList[i - 1] == "*")
                {
                    total = total * Convert.ToDouble(textList[i]);
                }

            }
            return total;
        }

        private double Divide(string text1)
        {
            string[] text = text1.Split('/');

            double total = Convert.ToDouble(text[0]);
            for (int i = 1; i < text.Length; i++)
            {
                total = total / Convert.ToDouble(text[i]);
            }
            return total;
        }
    }
}
