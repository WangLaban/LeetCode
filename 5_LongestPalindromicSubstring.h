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
Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
Space complexity : O(1). 
*/
int expandAroundCenter(string s, int left, int right)
{
    int L = left, R = right;
    while(L >= 0 && R < s.length() && s[L] == s[R])
    {
        L--;
        R++;
    }
    return R - L - 1;
}

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())  //if(s == NULL) -- Compiler Error
            return "";  //return NULL; -- Runtime Error
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if(len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
