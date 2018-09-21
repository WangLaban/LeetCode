/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int start = 0, end = nums.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] < target)
            {
                if(nums[end] == target || nums[start] == target)
                    return true;
                if(nums[start] == nums[mid])
                    start++;
                else if(nums[start] < nums[mid] || target < nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if(nums[end] == target || nums[start] == target)
                    return true;
                if(nums[mid] == nums[end])
                    end--;
                else if(nums[mid] < nums[end] || nums[end] < target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};
