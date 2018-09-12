/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:
You can assume that you can always reach the last index.
*/
// Solution: Jump to the position where we can jump farthest (index + nums[index]) next time.
// Solution1: 
/*class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, i = 0, cur = 0;
        while(cur < nums.size() - 1)
        {
            ++ret;
            int pre = cur;
            for(; i <= pre; ++i)
                cur = max(cur, i + nums[i]);
            if(pre == cur) return -1;  // Cannot reach the last index
        }
        return ret;
    }
};*/

// Solution2: 
class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, last = 0, cur = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            cur = max(cur, i + nums[i]);
            if(i == last)
            {
                last = cur;
                ++ret;
                if(cur >= nums.size() - 1)
                    break;
            }
        }
        return ret;
    }
};
