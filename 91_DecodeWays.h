/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:
Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
// Solution1: DP
/*class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0')
            return 0;
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++)
        {
            dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
            if(i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp.back();
    }
};*/

// Solution2:
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0 || s[0] == '0')
            return 0;
        int c1 = 1, c2 = 1;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '0')
                c1 = 0;
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                c1 = c1 + c2;
                c2 = c1 - c2;
            }
            else
            {
                c2 = c1;
            }
        }
        return c1;
    }
};
