/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);
// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
// Solution1: mySolution
/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return nums.size();
        
        int len = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); )
        {
            if(*it == val)
                it = nums.erase(it);
            else
            {
                ++it;
                len++;
            }
        }
        return len;
    }
};*/

// Solution2: refer to https://leetcode.com/problems/remove-element/solution/
// Approach 1: Two Pointers
/*
Time complexity : O(n). Assume the array has a total of n elements, both i and j traverse at most 2n steps.
Space complexity : O(1). 
*/
/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == val)
                continue;
            nums[i] = nums[j];
            i++;
        }
        return i;
    }
};*/

// Solution3: refer to https://leetcode.com/problems/remove-element/solution/
// Approach 2: Two Pointers - when elements to remove are rare
/*
Time complexity : O(n). Both i and n traverse at most n steps. In this approach, the number of assignment operation is equal to the number of elements to remove. So it is more efficient if elements to remove are rare.
Space complexity : O(1).
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            else 
                i++;
        }
        return n;
    }
};
