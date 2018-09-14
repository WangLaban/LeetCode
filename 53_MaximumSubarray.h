/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
// Solution1: mySolution
/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum = nums[0];
        int ret = sum;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                if(sum > 0)
                    sum += nums[i];
                else
                    sum = nums[i];
                ret = max(ret, sum);
            }
            else
            {
                if(sum < nums[i])
                    sum = nums[i];
                else
                    sum += nums[i];
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};*/

// Solution2: refer to https://leetcode.com/submissions/detail/175941782/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dynamic programming
        if(nums.empty()){
            return 0;
        }
        
        int local_max = nums[0];
        int global_max = nums[0];
        
        for (int i=1; i<nums.size(); ++i){
            if (nums[i-1] > 0){
                nums[i] += nums[i-1];
            }
        }
        
        for (int i=0; i<nums.size(); ++i){
            if (global_max < nums[i]){
                global_max = nums[i];
            }
        }
        
        return global_max;   
    }
};
