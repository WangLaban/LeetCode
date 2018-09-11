/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
["5","3",".",".","7",".",".",".","."]
["6",".",".","1","9","5",".",".","."]
[".","9","8",".",".",".",".","6","."]
["8",".",".",".","6",".",".",".","3"]
["4",".",".","8",".","3",".",".","1"]
["7",".",".",".","2",".",".",".","6"]
[".","6",".",".",".",".","2","8","."]
[".",".",".","4","1","9",".",".","5"]
[".",".",".",".","8",".",".","7","9"]
A sudoku puzzle...
["5","3","4","6","7","8","9","1","2"]
["6","7","2","1","9","5","3","4","8"]
["1","9","8","3","4","2","5","6","7"]
["8","5","9","7","6","1","4","2","3"]
["4","2","6","8","5","3","7","9","1"]
["7","1","3","9","2","4","8","5","6"]
["9","6","1","5","3","7","2","8","4"]
["2","8","7","4","1","9","6","3","5"]
["3","4","5","2","8","6","1","7","9"]
...and its solution numbers marked in red.
Note:
The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/
void getNextEmpty(vector<vector<char>>& board, int &row, int &column)
{
    do
    {
        if(board[row][column] == '.')
            return;
        row = (column == 8) ? row + 1 : row;
        column = (column + 1) % 9;
    }while(row < 9);
}
void getAvailable(vector<vector<char>>& board, vector<bool> &avail, int row, int column)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] != '.')
            avail[board[row][i] - '1'] = false;
        if(board[i][column] != '.')
            avail[board[i][column] - '1'] = false;
        int box_i = row / 3 * 3 + i / 3, box_j = column / 3 * 3 + i % 3;
        if(board[box_i][box_j] != '.')
            avail[board[box_i][box_j] - '1'] = false;
    }
}
bool solveSudokuRe(vector<vector<char>>& board, int row, int column)
{
    getNextEmpty(board, row, column);

    if(row == 9)
        return true;
    vector<bool> avail(9, true);
    getAvailable(board, avail, row, column);
    for(int i = 0; i < 9; i++)
    {
        if(!avail[i])
            continue;
        board[row][column] = i + '1';
        if(solveSudokuRe(board, row, column))
            return true;
    }
    board[row][column] = '.';
    return false;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuRe(board, 0, 0);
    }
};
