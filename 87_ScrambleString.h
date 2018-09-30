/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false
*/
// refer to https://www.cnblogs.com/yuzhangcmu/p/4189152.html
// Solution1: DP
// 我们提出维护量res[i][j][n]，其中i是s1的起始字符，j是s2的起始字符，而n是当前的字符串长度，res[i][j][len]表示的是以i和j分别为s1和s2起点
// 的长度为len的字符串是不是互为scramble。
// 有了维护量我们接下来看看递推式，也就是怎么根据历史信息来得到res[i][j][len]。判断这个是不是满足，其实我们首先是把当前s1[i...i+len-1]字符
// 串劈一刀分成两部分，然后分两种情况：第一种是左边和s2[j...j+len-1]左边部分是不是scramble，以及右边和s2[j...j+len-1]右边部分是不是
// scramble；第二种情况是左边和s2[j...j+len-1]右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。如果以上两种情况
// 有一种成立，说明s1[i...i+len-1]和s2[j...j+len-1]是scramble的。而对于判断这些左右部分是不是scramble我们是有历史信息的，因为长度小于n的
// 所有情况我们都在前面求解过了（也就是长度是最外层循环）。
// 上面说的是劈一刀的情况，对于s1[i...i+len-1]我们有len-1种劈法，在这些劈法中只要有一种成立，那么两个串就是scramble的。
// 总结起来递推式是res[i][j][len] = (res[i][j][k]&&res[i+k][j+k][len-k]) || (res[i][j+len-k][k]&&res[i+k][j][len-k])对于所有1<=k 如
// 此总时间复杂度因为是三维动态规划，需要三层循环，加上每一步需要线行时间求解递推式，所以是O(n^4)。虽然已经比较高了，但是至少不是指数量级的，
// 动态规划还是相当有用的，空间复杂度是O(n^3)。
/*class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1 == s2)
            return true;
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                for(int k = 1; k <= n - max(i, j); k++)
                {
                    if(s1.substr(i, k) == s2.substr(j, k))
                        dp[i][j][k] = true;
                    else
                    {
                        for(int t = 1; t < k; t++)
                        {
                            if((dp[i][j][t] && dp[i + t][j + t][k - t]) || (dp[i][j + k - t][t] && dp[i + t][j][k - t]))
                            {
                                dp[i][j][k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};*/
// Solution2: Brute Force Recursion
// 基本的思想就是：在S1上找到一个切割点，左边长度为i, 右边长为len - i。 有2种情况表明它们是IsScramble
// (1). S1的左边和S2的左边是IsScramble， S1的右边和S2的右边是IsScramble
// (2). S1的左边和S2的右边是IsScramble， S1的右边和S2的左边是IsScramble （实际上是交换了S1的左右子树）
/*class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1 == s2)
            return true;
        int n = s1.length();
        int map[26] = {0};
        for(int i = 0; i < n; i++)
        {
            map[s1[i] - 'a']++;
            map[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(map[i] != 0)
                return false;
        }
        for(int i = 1; i < n; i++)
        {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};*/
// Solution3: Brute Force Recursion
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1 == s2)
            return true;
        string str1 = s1;
        string str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1 != str2)
            return false;
        for(int i = 1; i < s1.length(); i++)
        {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if(isScramble(s11, s21) && isScramble(s12, s22))
                return true;
            s21 = s2.substr(s1.length() - i);
            s22 = s2.substr(0, s1.length() - i);
            if(isScramble(s11, s21) && isScramble(s12, s22))
                return true;
        }
        return false;
    }
};
