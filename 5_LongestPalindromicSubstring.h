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
// Method: Expand Around Center
// 1. Input: babad  Output: aba
/*int expandAroundCenter(string s, int left, int right)
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
};*/
// 2. https://articles.leetcode.com/longest-palindromic-substring-part-i
// Input: babad  Output: bab
string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2;
  int n = s.length();
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
}

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        string longest = s.substr(0, 1);  // a single char itself is a palindrome
        for (int i = 0; i < n-1; i++) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;
            
            string p2 = expandAroundCenter(s, i, i+1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
};
