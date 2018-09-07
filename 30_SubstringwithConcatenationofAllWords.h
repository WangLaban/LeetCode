/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:
Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
*/
// Use map to replace unordered_map is also OK.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(s.length() == 0 || words.size() == 0)
            return ret;
        
        int L = s.length(), M = words.size(), N = words[0].length();
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        for(int i = 0; i < M; i++)
            need[words[i]]++;
        for(int i = 0; i <= L - M * N; i++)
        {
            found.clear();
            int j;
            for(j = 0; j < M; j++)
            {
                string sub = s.substr(i + j * N, N);
                unordered_map<string, int>::iterator it = need.find(sub);  // auto it = need.find(sub);
                if(it == need.end())
                    break;
                if(need[sub] <= found[sub])
                    break;
                found[sub]++;
            }
            if(j == M)
                ret.push_back(i);
        }
        return ret;
    }
};
