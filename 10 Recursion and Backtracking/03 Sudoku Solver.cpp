// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if placing character c at board[row][col] is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        // Check all rows in current column
        for (int i = 0; i < 9; i++)
        {
            // If character already exists in column, not valid
            if (board[i][col] == c)
                return false;
        }

        // Check all columns in current row
        for (int j = 0; j < 9; j++)
        {
            // If character already exists in row, not valid
            if (board[row][j] == c)
                return false;
        }

        // Calculate start indices of the 3x3 sub-box
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        // Check the 3x3 sub-box for duplicate character
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // If character found in sub-box, not valid
                if (board[boxRowStart + i][boxColStart + j] == c)
                    return false;
            }
        }

        // If all checks passed, placement is valid
        return true;
    }

    // Recursive function to solve Sudoku using backtracking
    bool solveSudoku(vector<vector<char>> &board)
    {
        // Traverse each cell in the board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // If current cell is empty
                if (board[i][j] == '.')
                {
                    // Try all possible digits
                    for (char c = '1'; c <= '9'; c++)
                    {
                        // Check if placing c is valid here
                        if (isValid(board, i, j, c))
                        {
                            // Place c tentatively
                            board[i][j] = c;

                            // Recur to solve rest of the board
                            if (solveSudoku(board))
                                return true; // If successful, return true

                            // If not successful, backtrack
                            board[i][j] = '.';
                        }
                    }
                    // If no digit can be placed here, return false to backtrack
                    return false;
                }
            }
        }
        // If all cells are filled correctly, return true
        return true;
    }
};

int main()
{
    // Initialize the Sudoku board with given values and '.' for blanks
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    Solution sol;
    sol.solveSudoku(board);

    // Print the solved Sudoku board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
