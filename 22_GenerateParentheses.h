/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
/*
Time Complexity : O(4^n / √n). Each valid sequence has at most n steps during the backtracking procedure.
Space Complexity : O(4^n / √n), as described above, and using O(n) space to store the sequence. 
*/
void backtrack(vector<string> &ans, string cur, int open, int close, int max)
{
    if(cur.length() == max * 2)
    {
        ans.push_back(cur);
        return;
    }
    if(open < max)
    {
        backtrack(ans, cur + "(", open + 1, close, max);
    }
    if(close < open)
    {
        backtrack(ans, cur + ")", open, close + 1, max);
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n == 0)
            return ret;
        backtrack(ret, "", 0, 0, n);
        return ret;
    }
};
