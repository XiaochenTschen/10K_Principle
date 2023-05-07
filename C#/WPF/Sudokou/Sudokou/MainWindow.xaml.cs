using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Sudokou
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private TextBox[,] textBoxes = new TextBox[9, 9];

        public MainWindow()
        {
            InitializeComponent();
            InitializeTextBoxes();
        }

        private void InitializeTextBoxes()
        {
            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    TextBox textBox = new TextBox();
                    Grid.SetRow(textBox, row);
                    Grid.SetColumn(textBox, col);
                    SudokuGrid.Children.Add(textBox);
                    textBoxes[row, col] = textBox;
                }
            }
        }

        private bool isValid(char[,] board, int row, int col, char ch)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i, col] == ch)
                {
                    return false;
                }
                if (board[row, i] == ch)
                {
                    return false;
                }
                if (board[3 * (row / 3) + i / 3, 3 * (col / 3) + i % 3] == ch)
                {
                    return false;
                }
            }
            return true;
        }

        private bool solver(char[,] board)
        {
            int numRows = board.GetLength(0);
            int numCols = board.GetLength(1);

            for (int row = 0; row < numRows; row++)
            {
                for (int col = 0; col < numCols; col++)
                {
                    if (board[row, col] == '.')
                    {
                        for (char ch = '1'; ch <= '9'; ch++)
                        {
                            if (isValid(board, row, col, ch))
                            {
                                board[row, col] = ch;
                                if (solver(board) == true)
                                {
                                    return true;
                                }
                                board[row, col] = '.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        private void solverSodukou(char[,] board)
        {
            solver(board);
        }

        private void Calculate_Click(object sender, RoutedEventArgs e)
        {
            char[,] board = new char[9, 9];

            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    string textBoxText = textBoxes[row, col].Text;
                    char cellContent = textBoxText.Length > 0 ? textBoxText[0] : '.';
                    board[row, col] = cellContent;
                }
            }

            solverSodukou(board);

            for (int row = 0; row < 9; row++)
            {
                for (int col = 0; col < 9; col++)
                {
                    char currentElement = board[row, col];
                    textBoxes[row, col].Text = currentElement.ToString();
                }
            }
        }

    }

    

}
