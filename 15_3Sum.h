/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        result.clear();
        if(nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len - 2 && nums[i] <= 0; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;  // avoid duplicates
            
            int twoSum = 0 - nums[i];
            int left = i + 1, right = len - 1;
            while(left < right)
            {
                if(nums[left] + nums[right] < twoSum)
                    left++;
                else if(nums[left] + nums[right] > twoSum)
                    right--;
                else{
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(left < right && nums[left] == nums[left - 1])  // avoid duplicates
                        left++;
                    while(left < right && nums[right] == nums[right + 1])  // avoid duplicates
                        right--;
                }
            }
        }
        return result;
    }
};
