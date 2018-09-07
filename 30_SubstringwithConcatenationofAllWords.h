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
// Solution1: 
/*class Solution {
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
};*/

// Solution2: refer to https://leetcode.com/submissions/detail/174391273/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;
        unordered_map<string, int> expected;
        for (auto &word : words)
        {
            expected[word]++;
        }
        
        int word_len = words[0].size();
        // take the input s = "barfoothefoobarman" and words = ["foo","bar"] for an example
        // the substrings must start at i, i + 3, i + 6, ...
        // so only 3 round is needed 
        for (int i = 0; i < word_len; i++)
        {
            unordered_map<string, int> window;
            // use this counter and the condition check of "window[word] > expected[word]" 
            // we don't need to check the maps "window" and "expected" fully to see if they equal with each other
            int cnt = 0;
            int j = i;
            int beg = j;
            while (j <= (int)s.size() - word_len)
            {
                string word = s.substr(j, word_len);
                if (expected.find(word) != expected.end())
                {
                    window[word]++;
                    j += word_len;
                    cnt++;
                    while (window[word] > expected[word])
                    {
                        string left = s.substr(beg, word_len);
                        window[left]--;
                        cnt--;
                        beg += word_len;
                    }
                    if (cnt == words.size())
                        res.push_back(beg);
                }
                else
                {
                    // when some thing not expected are met, we have to drop everything we've got so far 
                    window.clear();
                    cnt = 0;
                    j += word_len;
                    beg = j;
                }
            }
        }
        return res;
    }
};
