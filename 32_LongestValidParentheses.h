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

// Solution2: 
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

// Solution3:
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
