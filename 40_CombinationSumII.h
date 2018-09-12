/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
void combinationSum2Re(vector<int>& candidates, int target, int start, vector<int>& com, vector<vector<int>>& ret)
{
    if(target == 0)
    {
        ret.push_back(com);
    }
    for(int i = start; i < candidates.size() && candidates[i] <= target; i++)
    {
        if(i > start && candidates[i] == candidates[i - 1])
            continue;
        com.push_back(candidates[i]);
        combinationSum2Re(candidates, target - candidates[i], i + 1, com, ret);
        com.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> com;
        sort(candidates.begin(), candidates.end());
        combinationSum2Re(candidates, target, 0, com, ret);
        
        return ret;
    }
};
