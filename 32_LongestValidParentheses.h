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
Time complexity : O(n). Single traversal of string to fill dp array is done.
Space complexity : O(n). dp array of size n is used. 
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1)
            return 0;
        
        int maxLen = 0;
        // int *dq = new int[s.length()];  --  Each element is not initialized
        int *dq = new int[s.length()]();  // every elements is initialized to 0
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i - 1] == '(')
                {
                    dq[i] = (i >= 2 ? dq[i - 2] : 0) + 2;
                }
                else if(i - dq[i - 1] > 0 && s[i - dq[i - 1] -1] == '(')
                {
                    dq[i] = dq[i - 1] + 2 + (i - dq[i - 1] >= 2 ? dq[i - dq[i - 1] - 2] : 0);
                }
            }
            maxLen = max(maxLen, dq[i]);
        }
        delete[] dq;
        return maxLen;
    }
};
