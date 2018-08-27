/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
/*
Time complexity : O(n). We traverse the list containing n elements exactly twice. Since the hash table reduces the look up time to O(1), the time complexity is O(n).
Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores exactly n elements. 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> imap;
        int i, complement;
        result.clear();
        for(i = 0; i < nums.size(); ++i)
            imap[nums[i]] = i;
        for(i = 0; i < nums.size(); ++i)
        {
            complement = target - nums[i];
            map<int, int>::iterator iter = imap.find(complement);
            if(iter != imap.end() && iter->second != i)
            {
                result.push_back(i);
                result.push_back(iter->second);
                return result;
            }
        }
        return result;
    }
};
