/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/
/*
Time complexity : O(n^2). This gives us a runtime complexity of O(n^2).
Space complexity : O(n^2). It uses O(n^2) space to store the table.
*/
// Method: Dynamic Programming
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int longestBegin = 0, maxLen = 1;
        bool table[1000][1000] = {false};
        for(int i = 0; i < s.length(); i++)
            table[i][i] = true;
        
        for(int i = 0; i < s.length() - 1; i++)
        {
            if(s[i] == s[i + 1])
            {
                table[i][i + 1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }
        for(int len = 3; len <= s.length(); len++)
        {
            for(int i = 0; i < s.length() - len + 1; i++)
            {
                int j = i + len - 1;
                if(s[i] == s[j] && table[i + 1][j - 1])
                {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(longestBegin, maxLen);
    }
};
