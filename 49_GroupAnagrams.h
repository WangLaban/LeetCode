/*
Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/
// Solution1: Categorize by Sorted String
/*
Time Complexity: O(NKlogK), where N is the length of strs, and K is the maximum length of a string in strs. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(KlogK) time.
Space Complexity: O(NK), the total information content stored in unmap. 
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmap;
        vector<vector<string>> ret;
        if(strs.size() == 0)
            return ret;
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            
            unmap[key].push_back(strs[i]);

        }
        for(unordered_map<string, vector<string>>::iterator it = unmap.begin(); it != unmap.end(); ++it)
        {
            ret.push_back(it->second);
        }
        return ret;
    }
};

// Solution2: Categorize by Count
/*
Time Complexity: O(NK), where N is the length of strs, and K is the maximum length of a string in strs. Counting each string is linear in the size of the string, and we count every string.
Space Complexity: O(NK), the total information content stored in ans.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmap;
        vector<vector<string>> ret;
        if(strs.empty())
            return ret;
        int count[26];
        for(int i = 0; i < strs.size(); i++)
        {
            memset(count, 0, sizeof(count));
            for(int j = 0; j < strs[i].size(); j++)
            {
                count[strs[i][j] - 'a']++;
            }
            string key;
            for(int j = 0; j < 26; j++)
            {
                key += to_string(count[j]);
            }

            unmap[key].push_back(strs[i]);
        }
        for(auto it = unmap.begin(); it != unmap.end(); ++it)
        {
            ret.push_back(it->second);
        }
        return ret;
    }
};
