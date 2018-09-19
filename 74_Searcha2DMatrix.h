/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
// Solution1: mySolution
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())  //input: [[]]
            return false;
        int first = 0, last = matrix.size() * matrix[0].size() - 1;
        int i = 0;
        for(; i < matrix.size(); i++)
        {
            if(target > matrix[i][matrix[0].size() - 1])
                first += matrix[0].size();
            else if(target == matrix[i][matrix[0].size() - 1])
                return true;
            else
                break;
        }
        if(first < last)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(target == matrix[i][j])
                    return true;
            }
        }
        return false;
    }
};*/

// Solution2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())  //input: [[]]
            return false;
        int i = 0, j = matrix[0].size() - 1;
        while(i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size())
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
