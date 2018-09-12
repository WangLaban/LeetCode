/*
Given a collection of distinct integers, return all possible permutations.
Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
// Solution: DFS(Depth First Search)
void permuteRe(vector<int>& nums, vector<bool>& avail, vector<int>& pum, vector<vector<int>>& ret)
{
    if(pum.size() == nums.size())
    {
        ret.push_back(pum);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(avail[i])
        {
            avail[i] = false;
            pum.push_back(nums[i]);
            permuteRe(nums, avail, pum, ret);
            pum.pop_back();
            avail[i] = true;
        }
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.clear();
        vector<bool> avail(nums.size(), true);
        vector<int> pum;
        permuteRe(nums, avail, pum, ret);
        return ret;
    }
};
