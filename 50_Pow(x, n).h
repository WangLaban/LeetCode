/*
Implement pow(x, n), which calculates x raised to the power n (x^n).
Example 1:
Input: 2.00000, 10
Output: 1024.00000
Example 2:
Input: 2.10000, 3
Output: 9.26100
Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
// Solution: consider n = -2147483648
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(x == 0 || x == 1)
            return x;
        if(x < 0)
            return (n % 2 == 0) ? myPow(-x, n) : -myPow(-x, n);
        //if(n < 0)  //n = -2147483648, error
            //return myPow(1.0 / x, -n);
        
        double half = (n < 0) ? myPow(1.0 / x, -(n / 2)) : myPow(x, n / 2);
        return (n % 2 == 0) ? (half * half) : (n < 0) ? (1.0 / x * half * half) : (x * half * half);
    }
};
