/*
Given an unsorted integer array, find the smallest missing positive integer.
Example 1:
Input: [1,2,0]
Output: 3
Example 2:
Input: [3,4,-1,1]
Output: 2
Example 3:
Input: [7,8,9,11,12]
Output: 1
Note:
Your algorithm should run in O(n) time and uses constant extra space.
*/
//  Solution: Swap elements in nums and try to make all the elements in nums satisfy: nums[i] == i + 1.
//            Pick out the first one that does not satisfy nums[i] == i + 1.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for(i = 0; i < n; i++)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return i + 1;
    }
};
