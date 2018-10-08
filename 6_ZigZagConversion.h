/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I     N
A   L S   I G
Y A   H R
P     I
*/
// Solution1:
/*
Time Complexity: O(n), where n==len(s)
Space Complexity: O(n)
*/
/*class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;
        for(int i = 0; i < s.length(); i++)
        {
            rows[curRow] += s[i];
            if(curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for(int i = 0; i < rows.size(); i++)
            ret += rows[i];
        
        return ret;
    }
};*/

// Solution2:
/*
Time Complexity: O(n), where n==len(s). Each index is visited once.
Space Complexity: O(1). The return string is not considered extra space.
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        string ret;
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
