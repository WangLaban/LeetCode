/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.
Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
// Solution1: mySolution
/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(digits.back() < 9)
        {
            vector<int> result(digits.begin(), digits.end());
            result[len - 1] += 1;
            return result;
        }
        else
        {
            vector<int> result(len + 1, 0);
            int carry = 0;
            digits[len - 1] += 1;
            for(int i = len - 1; i >= 0; i--)
            {
                result[i + 1] = (digits[i] + carry) % 10;
                carry = (digits[i] + carry) / 10;
            }
            if(carry)
                result[0] = carry;
            if(result[0] == 0)
                result.erase(result.begin());
            
            return result;
        }
    }
};*/
// Solution2: refer to https://github.com/leetcoders/LeetCode/blob/master/PlusOne.h
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 1;
        for(int i = len - 1; i >= 0 && carry; i--)
        {
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};
