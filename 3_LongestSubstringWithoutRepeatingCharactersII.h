/*
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", which the length is 3.
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
/*
Time complexity : O(n). Index j will iterate n times.

Space complexity (HashMap) : O(min(m, n)).
*/
/*
unordered_map, C++ 11 new feature, based on Hash table, it reduces the look up time to O(1) 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char, int> cmap;  //hash table
        int ans = 0, i = 0, j = 0;

        for(; j < len; j++)
        {
            //try to extend the range[i, j)
            if(cmap.find(s[j]) != cmap.end())
            {
                i = max(cmap[s[j]], i);
            }
            ans = max(ans, j - i + 1);
            cmap[s[j]] = j + 1;  //OK, exist key, will change its value
            //cmap.insert(pair<char, int>(s[j], j + 1));  //error, exist key, won't change its value
        }
        return ans;
    }
};
