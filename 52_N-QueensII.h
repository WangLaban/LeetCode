/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
// Solution1: Recursion + bit, The idea is from http://www.matrix67.com/blog/archives/266
/*void solveNQueensDFS(int n, int row, int ld, int rd, int &ret)
{
    if(row == (1 << n) - 1)
    {
        ret++;
        return;
    }
    int avail = ~(row | ld | rd);
    for(int i = 0; i < n; i++)
    {
        int pos = 1 << i;
        if(avail & pos)
            solveNQueensDFS(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, ret);
    }
}
class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        solveNQueensDFS(n, 0, 0, 0, ret);
        return ret;
    }
};*/

// Solution2: DFS
/*bool isVaild(int board[], int row, int col)
{
    for(int i = 0; i < row; i++)
        if(board[i] == col || row - i == abs(col - board[i]))
            return false;
    return true;
}
void solveNQueensDFS(int n, int row, int board[], int &ret)
{
    if(row == n)
    {
        ret++;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(isVaild(board, row, i))
        {
            board[row] = i;
            solveNQueensDFS(n, row + 1, board, ret);
            board[row] = -1;
        }
    }
}
class Solution {
public:
    int totalNQueens(int n){
        int ret = 0;
        int board[n];
        memset(board, -1, sizeof(board));
        solveNQueensDFS(n, 0, board, ret);
        return ret;
    }
};*/

// Solution3: Iteration
bool isVaild(int board[], int row, int col)
{
    for(int i = 0; i < row; i++)
        if(board[i] == col || row - i == abs(col - board[i]))  //对角线，行相减的绝对值等于列相减的绝对值
            return false;
    return true;
}
class Solution {
public:
    int totalNQueens(int n){
        int ret = 0;
        int board[n];
        memset(board, -1, sizeof(board));
        int row = 0;
        while(row >= 0)
        {
            if(row == n)
            {
                row--;
                ret++;
            }
            int i = board[row] == -1 ? 0 : board[row] + 1;
            for(; i < n; i++)
            {
                if(isVaild(board, row, i))
                {
                    board[row] = i;
                    row++;
                    break;
                }
            }
            if(i == n)
            {
                board[row] = -1;
                row--;
            }
        }
        return ret;
    }
};
