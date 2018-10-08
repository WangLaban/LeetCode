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
// Solution1:
/*
Time complexity : O(2n) = O(n). In the worst case each character will be visited twice by i and j.
Space complexity : O(min(m, n)). We need O(k) space for the sliding window, where k is the size of the Set. The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.  
*/
/*
unordered_set, C++ 11 new feature, based on Hash table, it reduces the look up time to O(1) 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_set<char> cset;  //hash table
        int ans = 0, i = 0, j = 0;
        while(i < len && j < len)
        {
            //try to extend the range[i, j)
            if(cset.find(s[j]) != cset.end())
            {
                cset.erase(s[i]);
                i++;
            }
            else
            {
                cset.insert(s[j]);
                j++;
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};

// Solution2:
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
