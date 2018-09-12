/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
// Solution: refer to https://github.com/leetcoders/LeetCode/blob/master/MultiplyStrings.h
class Solution {
public:
    string multiply(string num1, string num2) {
        int M = num1.length(), N = num2.length();
        string ret(N + M, '0');
        for(int i = M - 1; i >= 0; i--)
        {
            int carry = 0;
            for(int j = N - 1; j >= 0; j--)
            {
                int sum = carry + (ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                carry = sum / 10;
                ret[i + j + 1] = sum % 10 + '0';
            }
            ret[i] += carry;
        }
        while(ret.length() > 1 && ret[0] == '0')
            ret.erase(ret.begin());
        
        return ret;
    }
};
