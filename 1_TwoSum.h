/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
// Solution1:
/*
Time complexity : O(n^2). For each element, we try to find its complement by looping through the rest of array which takes O(n) time. Therefore, the time complexity is O(n^2).
Space complexity : O(1). 
*/
/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        result.clear();
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};*/

// Solution2:
/*
Time complexity : O(nlogN). We traverse the list containing n elements exactly twice. Since the Reb_Black_Tree reduces the look up time to O(logN), the time complexity is O(nlogN).
Besides, hash table can reduces the look up time to O(1), so if we use hash_map, the time complexity will be O(n).
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
