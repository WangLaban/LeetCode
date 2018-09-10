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
Time complexity : O(log(n))
Because binary search cuts the search space roughly in half on each iteration, there can be at most [log(n)] iterations. Binary search is invoked twice, so the overall complexity is logarithmic.
Space complexity : O(1)
All work is done in place, so the overall memory usage is constant.
*/
// returns leftmost (or rightmost) index at which `target` should be
// inserted in sorted array `nums` via binary search.
int extremeInsertionIndex(vector<int>& nums, int target, bool left)
{
    int low = 0, high = nums.size();  // The first element's index and the past-the-end element's index
    while(low < high)
    {
        int mid = (low + high) / 2;
        if(nums[mid] > target || (left && nums[mid] == target))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ivec{-1, -1};
        int left = extremeInsertionIndex(nums, target, true);
        if(left == nums.size() || nums[left] != target)
            return ivec;
        ivec.clear();
        ivec.push_back(left);
        ivec.push_back(extremeInsertionIndex(nums, target, false) - 1);
        
        return ivec;
    }
};
