/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Example:
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
// Solution1: Dynamic Programming
//            a) dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
//            b) For each element matrix[i][j], calculate the area of rectangle including the element itself.
/*class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        pair<int, int> dp[n][m];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                int x = (j == 0) ? 1 : dp[i][j - 1].first + 1;
                int y = (i == 0) ? 1 : dp[i - 1][j].second + 1;
                dp[i][j] = make_pair(x, y);
                int minHeight = y;
                for(int k = j; k > j - x; k--)
                {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
};*/

// Solution2: calculate 'Largest Rectangle in Histogram' for each row
// a little different from 'Largest Rectangle in Histogram'
// final 0 is already provided beforehand
/*int largestRectangleArea(vector<int>& height)
{
    stack<int> s;
    int res = 0;
    for(int i = 0; i < height.size(); i++)
    {
        int count = 0;
        while(!s.empty() && s.top() > height[i])
        {
            count++;
            res = max(res, count * s.top());
            s.pop();
        }
        while(count--)
            s.push(height[i]);
        s.push(height[i]);
    }
    return res;
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        vector<int> height(matrix[0].size() + 1, 0);
        int res = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
};*/

// Solution3: 
// 对于每个点(row, col), 我们最后都计算以这个点上方的连续的'1'往left, right方向延申可以得到的最大的矩形的面积
// height[row][col]记录的是(row, col)这个坐标为底座的直方图柱子的高度, 如果这个点是'0', 那么高度当然是0了
// left[row][col]记录的是(row, col)这个坐标点对应的height可以延申到的最左边的位置
// right[row][col]记录的是(row, col)这个坐标点对应的height可以延申到的最右边的位置+1
// eg.
// 0 0 0 1 0 0 0 
// 0 0 1 1 1 0 0 
// 0 1 1 1 1 1 0
// The vector "left" and "right" from row 0 to row 2 are as follows
// row 0:
// l: 0 0 0 3 0 0 0
// r: 7 7 7 4 7 7 7
// row 1:
// l: 0 0 2 3 2 0 0
// r: 7 7 5 4 5 7 7 
// row 2:
// l: 0 1 2 3 2 1 0
// r: 7 6 5 4 5 6 7
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> H(m, 0);
        vector<int> L(m, 0);
        vector<int> R(m, m);
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int left = 0, right = m;
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    H[j]++;
                    L[j] = max(left, L[j]);
                }
                else
                {
                    left = j + 1;
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = m;
                }
            }
            for(int j = m - 1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                {
                    R[j] = min(R[j], right);
                    res = max(res, (R[j] - L[j]) * H[j]);
                }
                else
                {
                    right = j;
                }
            }
        }
        return res;
    }
};
