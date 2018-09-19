/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
// Solution1: additional sapce
/*class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        vector<int> row;
        vector<int> col;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        while(!row.empty())
        {
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[row.back()][j] = 0;
            row.pop_back();
        }
        while(!col.empty())
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][col.back()] = 0;
            col.pop_back();
        }
    }
};*/

// Solution2: constant sapce
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int left = 0, top = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                left = 1;
                break;
            }
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0)
            {
                top = 1;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // column set to zero
        for(int i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        // row set to zero
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i < matrix.size(); i++)
                    matrix[i][j] = 0;
            }
        }
        // the first row
        if(top)
        {
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        // the first column
        if(left)
        {
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};
