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
Time complexity : O(n). Two traversals of the string.
Space complexity : O(1). Only two extra variables left and right are needed.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1)
            return 0;
        int left = 0, right = 0, maxLen = 0;
        // Scan from left to right
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
            if(right == left)
                maxLen = max(maxLen, 2 * right);
            if(right > left)
                left = right = 0;
        }
        left = right = 0;
        // Scan from right to left
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
                right++;
            else
                left++;
            if(left == right)
                maxLen = max(maxLen, 2 * left);
            if(left > right)
                left = right = 0;
        }
        return maxLen;
    }
};
