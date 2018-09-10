/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Example 1:
Input: [1,3,5,6], 5
Output: 2
Example 2:
Input: [1,3,5,6], 2
Output: 1
Example 3:
Input: [1,3,5,6], 7
Output: 4
Example 4:
Input: [1,3,5,6], 0
Output: 0
*/
// Solution1: mySolution
/*class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int i;
        for(i = 0; i < nums.size(); i++)
        {
            if(target <= nums[i])
                return i;
            else
                continue;
        }
        return i;
    }
};*/

// Solution2: refer to https://leetcode.com/submissions/detail/175057360/
// You may assume no duplicates in the array.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(target < nums[mid])
            {
                right = mid - 1;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
                return mid;
        }
        return left;
    }
};
