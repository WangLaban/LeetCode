/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int distance = INT_MAX;
        int result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len - 2; i++)
        {
            int twoSum = target - nums[i];
            int left = i + 1, right = len - 1;
            while(left < right)
            {
                if(abs(target - (nums[i] + nums[left] + nums[right])) < distance)
                {
                    distance = abs(target - (nums[i] + nums[left] + nums[right]));
                    result = nums[i] + nums[left] + nums[right];
                }
                if(nums[left] + nums[right] < twoSum)
                {
                    left++;
                }
                else if(nums[left] + nums[right] > twoSum)
                {
                    right--;
                }
                else
                {
                    return target;
                }
            }
        }
        return result;
    }
};
