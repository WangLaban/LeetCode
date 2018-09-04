/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.
*/
/*
Time complexity : O(S⋅log(n)), where S is the sum of all characters in all strings.
The algorithm makes log(n) iterations, for each of them there are S = m*n comparisons, which gives in total O(S⋅log(n)) time complexity.
Space complexity : O(1). We only used constant extra space. 

*/
bool isCommonPrefix(vector<string>& strs, int n)
{
    if(strs.size() == 0)
        return false;
    
    string prefix = strs[0].substr(0, n);
    for(int i = 1; i < strs.size(); i++)
    {
        if(strs[i].compare(0, n, prefix) != 0)
            return false;
    }
    return true;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        int minLen = strs[0].length();
        for(int i = 1; i < strs.size(); i++)
        {
            int minLen = min(minLen, (int)strs[i].length());
        }
        int left = 1, right = minLen;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(isCommonPrefix(strs, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return strs[0].substr(0, left - 1);
    }
};
