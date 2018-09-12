/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
// Solution: DFS(Depth First Search)
void permuteUniqueRe(vector<int>& nums, vector<bool>& avail, vector<int>& pum, vector<vector<int>>& ret)
{
    if(pum.size() == nums.size())
    {
        ret.push_back(pum);
        return;
    }
    int last_index = -1;
    for(int i = 0; i < nums.size(); i++)
    {
        if(last_index != -1 && nums[i] == nums[last_index]) continue;
        if(avail[i])
        {
            avail[i] = false;
            pum.push_back(nums[i]);
            permuteUniqueRe(nums, avail, pum, ret);
            pum.pop_back();
            avail[i] = true;
            last_index = i;
        }
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.clear();
        sort(nums.begin(), nums.end());
        vector<bool> avail(nums.size(), true);
        vector<int> pum;
        permuteUniqueRe(nums, avail, pum, ret);
        return ret;
    }
};
