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
// Solution1:
/*class Solution {
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
};*/

// Solution2:
/*
Time complexity: O(log(min(m,n))).
At first, the searching range is [0, m]. And the length of this searching range will be reduced by half after each loop. So, we only need log(m) loops. Since we do constant operations in each loop, so the time complexity is O(log(m)). Since m≤n, so the time complexity is O(log(min(m,n))).
Space complexity: O(1).
We only need constant memory to store 9 local variables, so the space complexity is O(1).
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)  // to ensure m <= n
        {
            vector<int> ivec(nums1);
            nums1 = nums2;
            nums2 = ivec;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < iMax && nums2[j - 1] > nums1[i])
                iMin = i + 1;  // iMin is too small
            else if(i > iMin && nums1[i - 1] > nums2[j])
                iMax = i - 1;  // iMax is too big
            else
            {
                int maxLeft = 0;
                if(i == 0)
                    maxLeft = nums2[j - 1];
                else if(j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                if((m + n) % 2 == 1)
                    return maxLeft;
                
                int minRight = 0;
                if(i == m)
                    minRight = nums2[j];
                else if(j == n)
                    minRight = nums1[i];
                else
                    minRight = min(nums1[i], nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};
