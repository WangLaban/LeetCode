/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
/*
Time complexity : O(n)
This brute-force approach examines each of the n elements of nums exactly twice, so the overall runtime is linear.
Space complexity : O(1)
The linear scan method allocates a fixed-size array and a few integers, so it has a constant-size memory footprint.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ivec{-1, -1};
        if(nums.size() == 0)
            return ivec;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                ivec.clear();
                ivec.push_back(i);
                break;
            }
        }
        if(ivec[0] == -1)
            return ivec;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] == target)
            {
                ivec.push_back(i);
                break;
            }
        }

        return ivec;
    }
};
