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
Time complexity : O(n).
Space complexity : O(n). 
*/
// Method: Manacher’s algorithm
// 1. Input: babad  Output: bab

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
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
