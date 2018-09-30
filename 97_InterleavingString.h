/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
Example 1:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
// Solution1: Recursion with memoization
/*
Time complexity : O(2^{m+n}). m is the length of s1 and nn is the length of s2.
Space complexity : O(m⋅n). 
*/
/*class Solution {
private:
    bool is_Interleave(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>>& memo) {
        if (i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }
        if (j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1 ? true : false;
        }
        bool ans = false;
        if (s3[k] == s1[i] && is_Interleave(s1, i + 1, s2, j, s3, k + 1, memo)
                || s3[k] == s2[j] && is_Interleave(s1, i, s2, j + 1, s3, k + 1, memo)) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.length(), vector<int>(s2.length(), -1));
        return is_Interleave(s1, 0, s2, 0, s3, 0, memo);
    }
};*/
// Solution2: Using 2D Dynamic Programming
/*
Time complexity : O(m⋅n). dp array of size m∗n is filled.
Space complexity : O(m⋅n). 2D dp of size (m+1)*(n+1) is required. m and n are the lengths of strings s1 and s2 respectively. 
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != (s1.length() + s2.length()))
            return false;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        for(int i = 0; i <= s1.length(); i++)
        {
            for(int j = 0; j <= s2.length(); j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                {
                    dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                else if(j == 0)
                {
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
