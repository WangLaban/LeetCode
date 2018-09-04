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
string commonPrefix(string first, string second)
{
    if(first.length() == 0 || second.length() == 0)
        return "";

    int n = min(first.length(), second.length());
    for(int i = 0; i < n; i++)
    {
        if(first[i] != second[i])
            return first.substr(0, i);
    }
    return first.substr(0, n);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); i++)
        {
            prefix = commonPrefix(prefix, strs[i]);
        }
        return prefix;
    }
};
