/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
bool existRe(vector<vector<char>>& board, string word, int deep, int i, int j, vector<vector<char>>& avail)
{
    if(deep == word.length())
        return true;
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        return false;
    if(avail[i][j] == '1' || board[i][j] != word[deep])
        return false;
    avail[i][j] = '1';
    if(existRe(board, word, deep + 1, i + 1, j, avail))
        return true;
    if(existRe(board, word, deep + 1, i - 1, j, avail))
        return true;
    if(existRe(board, word, deep + 1, i, j + 1, avail))
        return true;;
    if(existRe(board, word, deep + 1, i, j - 1, avail))
        return true;
    avail[i][j] = '0';
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> res;
        vector<vector<char>> avail(board.size(), vector<char>(board[0].size(), '0'));
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(existRe(board, word, 0, i, j, avail))
                    return true;
            }  
        }
        return false;
    }
};
