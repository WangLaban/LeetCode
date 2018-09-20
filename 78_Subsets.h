/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
// Solution1: 
// nums = {}         []
// nums = {1}        [] [1]
// nums = {1, 2}     [] [1] [2] [1, 2]
// nums = {1, 2, 3}  [] [1] [2] [1, 2] [3] [1, 3] [2, 3] [1, 2, 3]
// ......
/*class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        for(int i = 0; i < nums.size(); i++)
        {
            int size = res.size();
            for(int j = 0; j < size; j++)  // for(int j = 0; j < res.size(); j++) -- error: res increments
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};*/

// Solution2: DFS
void subsetsRe(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
{
    res.push_back(out);
    for(int i = start; i < nums.size(); i++)
    {
        out.push_back(nums[i]);
        subsetsRe(nums, i + 1, out, res);
        out.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        subsetsRe(nums, 0, out, res);
        return res;
    }
};
