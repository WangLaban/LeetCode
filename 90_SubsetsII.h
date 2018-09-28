/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
// Solution1: DFS
/*void subsetWithDupRe(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res)
{
    res.push_back(out);
    for(int i = start; i < nums.size(); i++)
    {
        out.push_back(nums[i]);
        subsetWithDupRe(nums, i + 1, out, res);
        out.pop_back();
        while(i < nums.size() - 1 && nums[i] == nums[i + 1])
            i++;
    }
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(), nums.end());
        subsetWithDupRe(nums, 0, out, res);
        return res;
    }
};*/

// Solution2: 拿[1 2 2]来分析，当处理完第一个2时，此时的子集合为[], [1], [2], [1, 2]，
// 而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，所以只能在上一个循环生成的后两个子集合后面加2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty())
            return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int size = 1, last = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != last)
            {
                last = nums[i];
                size = res.size();
            }
            int newSize = res.size();
            for(int j = newSize - size; j < newSize; j++)
            {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};
