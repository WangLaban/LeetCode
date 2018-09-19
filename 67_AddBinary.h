/*
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/
// Solution1: mySolution
/*class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length(), len2 = b.length();
        int maxLen = max(len1, len2);
        string result(maxLen + 1, '0');
        int carry = 0;
        while(len1 && len2)
        {
            result[maxLen] = (a[len1 - 1] - '0' + b[len2 - 1] - '0' + carry) % 2 + '0';
            carry = (a[len1 - 1] - '0' + b[len2 - 1] - '0' + carry) / 2;
            len1--;
            len2--;
            maxLen--;
        }
        while(len1)
        {
            result[maxLen] = (a[len1 - 1] - '0' + carry) % 2 + '0';
            carry = (a[len1 - 1] - '0' + carry) / 2;
            len1--;
            maxLen--;
        }
        while(len2)
        {
            result[maxLen] = (b[len2 - 1] - '0' + carry) % 2 + '0';
            carry = (b[len2 - 1] - '0' + carry) / 2;
            len2--;
            maxLen--;
        }
        if(carry)
            result[0] = carry + '0';
        else
            result.erase(result.begin());
        
        return result;
    }
};*/

// Solution2: 
class Solution {
public:
    string addBinary(string a, string b) {
        string output = "";
        for(int carry = 0, sum = 0, i = a.length() - 1, j = b.length() - 1; carry > 0 || i >= 0 || j >= 0; i--, j--)  //carry > 0, the first bit overflow
        {
            sum = carry;
            if(i >= 0)
                sum += a[i] - '0';
            if(j >= 0)
                sum += b[j] - '0';
            
            carry = sum / 2;
            sum %= 2;
            output = char(sum + '0') + output;
        }
        return output;
    }
};
