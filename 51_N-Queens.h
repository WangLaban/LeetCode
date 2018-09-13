/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
// Solution: DFS + bit version (fast), The idea is from http://www.matrix67.com/blog/archives/266
void solveNQueensDFS(int n, int row, int ld, int rd, vector<string>& sol, vector<vector<string>>& ret)
{
    if(row == (1 << n) - 1)
    {
        ret.push_back(sol);
        return;
    }
    int avail = ~(row | ld | rd);
    for(int i = 0; i < n; i++)  //for(int i = n - 1; i >= 0; i--) is also OK
    {
        int pos = 1 << i;
        if(avail & pos)
        {
            string s(n, '.');
            s[i] = 'Q';
            sol.push_back(s);
            solveNQueensDFS(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, sol, ret);
            sol.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> sol;
        solveNQueensDFS(n, 0, 0, 0, sol, ret);
        return ret;
    }
};
