/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0)
            return 0.0;

        double result = 0.0;
        int len;
        vector<int> ivec;
        if(nums1.size() > 0)
            ivec.insert(ivec.begin(), nums1.begin(), nums1.end());
        if(nums2.size() > 0)
            ivec.insert(ivec.begin(), nums2.begin(), nums2.end());
        sort(ivec.begin(), ivec.end());

        len = ivec.size();
        if(len % 2 == 0)
            result = (ivec[(len - 1) / 2] + ivec[len / 2]) / 2.0;
        else
            result = (ivec[(len - 1) / 2]) / 1.0;
        
        return result;
    }
};
