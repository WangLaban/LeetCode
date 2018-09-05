/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Note:
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        if(nums.size() < 4)
            return ret;
        
        sort(nums.begin(), nums.end());
        
        for(size_t i = 0; i < nums.size() - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(size_t j = i + 1; j < nums.size() - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int twoSum = target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;

                while(left < right)
                {
                    if(nums[left] + nums[right] > twoSum)
                    {
                        right--;
                    }
                    else if(nums[left] + nums[right] < twoSum)
                    {
                        left++;
                    }
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])
                            left++;
                        while(left < right && nums[right - 1] == nums[right])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};
