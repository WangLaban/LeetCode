/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
// Solution: Sort & Recursion
void combinationSumRe(vector<int>& candidates, int target, int start, vector<int>& com, vector<vector<int>>& ret)
{
    if(target == 0)
    {
        ret.push_back(com);
        return;
    }
    for(int i = start; i < candidates.size() && candidates[i] <= target; i++)
    {
        com.push_back(candidates[i]);
        combinationSumRe(candidates, target - candidates[i], i, com, ret);
        com.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        combinationSumRe(candidates, target, 0, com, ret);
        return ret;
    }
};
