/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/
// Solution1: Greedy, refer to https://leetcode.com/problems/jump-game/solution/
/*
Time complexity : O(n). We are doing a single pass through the nums array, hence n steps, where n is the length of array nums.
Space complexity : O(1). We are not using any extra memory.
*/
/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int distance = nums[i] + i;
            if(distance >= lastPos)
                lastPos = i;
        }
        return lastPos == 0;
    }
};*/

// Solution2: 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, cur = 0;
        while(cur < nums.size() - 1)
        {
            int pre = cur;
            for(; i <= pre; ++i)
                cur = max(cur, i + nums[i]);
            if(pre == cur) return false;  // Cannot reach the last index
        }
        return true;
    }
};
