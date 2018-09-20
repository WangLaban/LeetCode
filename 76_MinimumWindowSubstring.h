/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
/*
Time Complexity: O(∣S∣+∣T∣) where |S| and |T| represent the lengths of strings S and T. In the worst case we might end up visiting every element of string S twice, once by left pointer and once by right pointer. ∣T∣ represents the length of string T.
Space Complexity: O(∣S∣+∣T∣). ∣S∣ when the window size is equal to the entire string S. ∣T∣ when T has all unique characters.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() == 0 || t.length() == 0 || s.length() < t.length())
            return "";
        if(s.find(t) != string::npos)
            return t;
        
        // Dictionary which keeps a count of all the unique characters in t
        map<char, int> dictT;
        for(int i = 0; i < t.length(); i++)
        {
            dictT[t[i]]++;
        }
        
        // Left and Right pointer
        int l = 0, r = 0;
        
        // Dictionary which keeps a count of all the unique characters in the current window.
        map<char, int> windowCounts;
        
        int count = 0;
        int resLeft = -1, resRight = s.length() - 1;
        for(; r < s.length(); r++)
        {
            if(!dictT.count(s[r]))
                continue;
            
            if(windowCounts[s[r]] < dictT[s[r]])
                count++;
            
            // Add one character from the right in string t to the window
            windowCounts[s[r]]++;
            
            if(count < t.length())
                continue;
            
            // move left
            for(; l < r; l++)
            {
                if(dictT.count(s[l]) == 0)
                    continue;
                if(windowCounts[s[l]] <= dictT[s[l]])
                    break;
                windowCounts[s[l]]--;
            }
            
            // update result
            if(r - l < resRight - resLeft)
            {
                resLeft = l;
                resRight = r;
            }
        }
        return (resLeft == -1) ? "" : s.substr(resLeft, resRight - resLeft + 1);
    }
};
