/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Above is a 7 x 3 grid. How many possible unique paths are there?
Note: m and n will be at most 100.
Example 1:
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:
Input: m = 7, n = 3
Output: 28
*/
// Solution: C(m - 1, n - 1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        if(m == 1 || n == 1)
            return 1;
        if(n > m)
            swap(m, n);
        m = m - 1;
        n = n - 1;
        m = m + n;
        long long result = 1;
        for(int i = m - n + 1; i <= m; i++)
        {
            result *= i;
        }
        for(int i = 1; i <= n; i++)
        {
            result /= i;
        }
        
        return result;
    }
};
