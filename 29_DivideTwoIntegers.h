/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if(dividend == 0)
            return 0;
        bool negative = false;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            negative = true;
        long long dividendI = abs((long long)dividend), divisorI = abs((long long)divisor);  // -2147483648
        
        long long result = 0;
        
        while(dividendI >= divisorI)  // If use "dividendI -= divisorI" will cause Time Limit Exceeded
        {
            long long c = divisorI;
            for(int i = 0; (c << i) <= dividendI; i++)
            {
                dividendI -= (c << i);
                result += (1 << i);
            }
        }
        if(result > INT_MAX && !negative)
            return INT_MAX;
        return negative ? -result : result;
    }
};
