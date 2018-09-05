/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
vector<string> letterCombinationsRe(vector<string> str1, string str2)
{
    vector<string> ret;
    string str;
    for(int i = 0; i < str1.size(); i++)
    {
        str = str1[i];
        for(int j = 0; j < str2.length(); j++)
        {
            str += str2[j];
            ret.push_back(str);
            str.pop_back();
        }
    }
    return ret;
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        
        if(digits.length() == 0)
            return ret;
        
        string str;
        for(int i = 0; i < keyboard[digits[0] - '0'].length(); i++)
        {
            str = keyboard[digits[0] - '0'][i];
            ret.push_back(str);
        }
            
        for(int i = 1; i < digits.length(); i++)
        {
            ret = letterCombinationsRe(ret, keyboard[digits[i] - '0']);
        }
        return ret;
    }
};
