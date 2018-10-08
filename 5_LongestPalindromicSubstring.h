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
// Solution1: Expand Around Center
// Input: babad  Output: aba
/*
Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
Space complexity : O(1). 
*/
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

// Solution2: Expand Around Center
// Input: babad  Output: bab
// https://articles.leetcode.com/longest-palindromic-substring-part-i
/*
Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
Space complexity : O(1). 
*/
/*string expandAroundCenter(string s, int c1, int c2) {
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
};*/

// Solution3: Dynamic Programming
/*
Time complexity : O(n^2). This gives us a runtime complexity of O(n^2).
Space complexity : O(n^2). It uses O(n^2) space to store the table.
*/
/*class Solution {
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
};*/

// Solution4: Manacher’s algorithm
// Input: babad  Output: bab

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
/*
Time complexity : O(n).
Space complexity : O(n). 
*/
string preProcess(string s)
{
    int n = s.length();
    if (n == 0) return "^$";
    string ret = "^";
    for(int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);
    ret += "#$";
    
    return ret;
}

class Solution {
public:
    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();
        int *p = new int[n];
        int id = 0, mx = 0, centerIndex = 0, maxLen = 0;
        for(int i = 1; i < n - 1; i++)
        {
            int i_mirror = 2 * id - i;  //equals to i' = id - (i - id)
            p[i] = (mx > i) ? min(mx - i, p[i_mirror]) : 1;
            // Attempt to expand palindrome centered at i
            while(T[i + p[i]] == T[i - p[i]])
                p[i]++;
            // If palindrome centered at i expand past mx,
            // adjust center based on expanded palindrome.
            if(i + p[i] > mx)
            {
                id = i;
                mx = i + p[i];
            }
            
            if(p[i] > maxLen)
            {
                centerIndex = i;
                maxLen = p[i];
            }
        }
        delete [] p;
        return s.substr((centerIndex - maxLen) / 2, maxLen - 1);
    }
};
