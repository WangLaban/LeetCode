/*
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
Example 1:
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2
For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.
00 - 0
10 - 2
11 - 3
01 - 1
Example 2:
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
*/
// Solution1: 
/*class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);

        for(int i = 1; i <= n; i++)
        {
            int len = res.size();
            int highBit = 1 << (i - 1);
            // attention: 'for(int j = 0; j < len; j++)' the result is wrong
            for(int j = len - 1; j >= 0; j--)
            {
                res.push_back(res[j] + highBit);
            }
        }
        return res;
    }
};*/

// Solution2: 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1 << n, 0);
        for(int i = 0; i < 1 << n; i++)
        {
            res[i] = (i >> 1) ^ i;
        }
        return res;
    }
};
