/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
It doesn't matter what values are set beyond the returned length.
Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);
// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
// Solution1: mySolution
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 1, j = 0;
        int last = nums[0], count = 1;
        for(; i < nums.size(); i++)
        {
            if(nums[i] == last)
            {
                count++;
                if(count > 2)
                    continue;
                j++;
                nums[j] = nums[i];
            }
            else
            {
                last = nums[i];
                count = 1;
                j++;
                nums[j] = nums[i];
            }
        }
        return ++j;  // index + 1, return the length
    }
};*/

// Solution2:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int i = 2, j = 1;
        while(i < nums.size())
        {
            if(nums[i] == nums[j] && nums[i] == nums[j - 1])
            {
                i++;
            }
            else
            {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        return ++j;
    }
};
