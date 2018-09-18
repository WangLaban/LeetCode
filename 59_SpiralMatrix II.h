/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
Example:
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
// Solution1: mySolution
/*class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        if(n == 0)
            return ret;
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int num = 1;
        //while(r1 <= r2 || c1 <= c2)  //also OK
        while(r1 <= r2 && c1 <= c2)
        {
            for(int j = c1; j <= c2; j++)
            {
                ret[r1][j] = num++;
            }
            for(int i = r1 + 1; i <= r2; i++)
            {
                ret[i][c2] = num++;
            }
            //if(r1 < r2 && c1 < c2)  //also OK
            if(r1 < r2 && c1 < c2)
            {
                for(int j = c2 - 1; j >= c1; j--)
                {
                    ret[r2][j] = num++;
                }
                for(int i = r2 - 1; i > r1; i--)
                {
                    ret[i][c1] = num++;
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ret;
    }
};*/

// Solution2:
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        if(n == 0)
            return ret;
        int start = 0, end = n - 1;
        int num = 1;
        while(start <= end)
        {
            //top
            for(int i = start; i <= end; i++)
                ret[start][i] = num++;
            //right
            for(int j = start + 1; j <= end; j++)
                ret[j][end] = num++;
            //bottom
            for(int i = end - 1; i >= start; i--)
                ret[end][i] = num++;
            //left
            for(int j = end - 1; j > start; j--)
                ret[j][start] = num++;
            
            start++;
            end--;
        }
        return ret;
    }
};
