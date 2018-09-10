/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
/*
Time complexity : O(n). n is the length of the given string..
Space complexity : O(n). The size of stack can go up to n. 
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1)
            return 0;
        int maxLen = 0;
        stack<int> cst;
        cst.push(-1);
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                cst.push(i);
            }
            else
            {
                cst.pop();
                if(cst.empty())
                {
                    cst.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - cst.top());
                }
            }
        }
        return maxLen;
    }
};
