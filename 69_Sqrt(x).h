/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
Example 1:
Input: 4
Output: 2
Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/
// Solution1: Newton iteration method: x(i+1) = (x(i) + n/x(i)) / 2, refer to http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
/*class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        double ret = 1;
        double last = 0;
        while(ret != last)
        {
            last = ret;
            ret = (ret + x / ret) / 2;
        }
        return (int)ret;
    }
};*/

// Solution2: Binary search in range [0, x / 2 + 1]
class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        int j = x / 2 + 1;
        while(i <= j)
        {
            long long mid = (i + j) / 2;
            long long multi = mid * mid;  //multiplier's type should be 'long long' also, otherwise the result will overflow
            if(multi == x)
                return mid;
            else if(multi < x)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return j;
    }
};
