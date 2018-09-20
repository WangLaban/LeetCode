/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
// Solution1:
/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0 || k <= 0 || k > n)
            return res;
        vector<int> out(k, 0);
        int i = 0;
        while(i >= 0)
        {
            out[i]++;
            if(out[i] > n)
                i--;
            else if(i == k - 1)
                res.push_back(out);
            else
            {
                i++;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};*/
// Solution2: DFS
/*void combineRe(int n, int k, int start, vector<int>& nums, vector<vector<int>>& res)
{
    if(nums.size() == k)
    {
        res.push_back(nums);
        return;
    }
    //for(int i = start; i <= n - (k - nums.size()) + 1; i++)
    for(int i = start; i<= n; i++)
    {
        nums.push_back(i);
        combineRe(n, k, i + 1, nums, res);
        nums.pop_back();
    }
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n <= 0 || k <= 0 || k > n)
            return res;
        vector<int> nums;
        combineRe(n, k, 1, nums, res);
        return res;
    }
};*/

// Solution3: C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
    	if(n < 0 || k < 0 || k > n)
    	return res;
        if(n == 0 || k == 0)  // end condition
            return {{}};

        res = combine(n - 1, k - 1);
        for(auto &a : res)  // for(auto a : res) -- wrong answer
            a.push_back(n);
        for(auto a : combine(n - 1, k))
            res.push_back(a);
        
        return res;
    }
};
