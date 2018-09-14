/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
// Solution1: Simulation
/*
Time Complexity: O(N), where N is the total number of elements in the input matrix. We add every element in the matrix to our final answer.
Space Complexity: O(N), the information stored in seen and in ret. 
*/
/*class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
        
        int R = matrix.size(), C = matrix[0].size();
        bool seen[R][C] = {false};
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
        for(int i = 0; i < R * C; i++)
        {
            ret.push_back(matrix[r][c]);
            seen[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if(cr >= 0 && cr < R && cc >= 0 && cc < C && !seen[cr][cc])
            {
                r = cr;
                c = cc;
            }
            else
            {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return ret;
    }
};*/

// Solution2: Layer-by-Layer
/*
ime Complexity: O(N), where N is the total number of elements in the input matrix. We add every element in the matrix to our final answer.
Space Complexity: O(N), the information stored in ret.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
        
        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        while(r1 <= r2 && c1 <= c2)
        {
            for(int c = c1; c <= c2; c++)
                ret.push_back(matrix[r1][c]);
            for(int r = r1 + 1; r <= r2; r++)
                ret.push_back(matrix[r][c2]);
            if(r1 < r2 && c1 < c2)
            {
                for(int c = c2 - 1; c > c1; c--)
                    ret.push_back(matrix[r2][c]);
                for(int r = r2; r > r1; r--)
                    ret.push_back(matrix[r][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ret;
    }
};
