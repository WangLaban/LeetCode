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
Time Complexity : O(4^n / √n).
Space Complexity : O(4^n / √n).
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        set<string> mySet;
        if(n == 0)
            ret.push_back("");

        for(int i = 0; i < n; i++)
        {
            for(string left: generateParenthesis(i))
            {
                for(string right: generateParenthesis(n - 1 - i))
                {
                    ret.push_back("(" + left + ")" + right);
                }
            }
        }
        return ret;
    }
};
