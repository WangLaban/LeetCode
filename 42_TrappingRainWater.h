/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
// Solution1: Brute force
/*
Time complexity: O(n^2). For each element of array, we iterate the left and right parts.
Space complexity: O(1) extra space. 
*/
/*class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        for(int i = 1; i < size - 1; i++)
        {
            int max_left = 0, max_right = 0;
            for(int j = i; j >= 0; j--)  //Search the left part for max bar size
            {
                max_left = max(max_left, height[j]);
            }
            for(int j = i; j < size; j++)  //Search the right part for max bar size
            {
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};*/

// Solution2: Dynamic Programming
/*
Time complexity: O(n).
We store the maximum heights upto a point using 2 iterations of O(n) each.
We finally update ans using the stored values in O(n).
Space complexity: O(n) extra space.
Additional O(n) space for left_max and right_max arrays. 
*/
/*class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for(int i = 1; i < size; i++)
            left_max[i] = max(height[i], left_max[i - 1]);
        right_max[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--)
            right_max[i] = max(height[i], right_max[i + 1]);
        for(int i = 1; i < size - 1; i++)
            ans += min(left_max[i], right_max[i]) - height[i];
        
        return ans;
    }
};*/

// Solution3: Using stacks
/*
Time complexity: O(n).
Single iteration of O(n) in which each bar can be touched at most twice(due to insertion and deletion from stack) and insertion and deletion from stack takes O(1) time.
Space complexity: O(n). Stack can take upto O(n) space in case of stairs-like or flat structure.
*/
/*class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> ist;
        while(current < height.size())
        {
            while(!ist.empty() && height[current] > height[ist.top()])
            {
                int top = ist.top();
                ist.pop();
                if(ist.empty())
                    break;
                int distance = current - ist.top() - 1;
                int bounded_height = min(height[current], height[ist.top()]) - height[top];
                ans += distance * bounded_height;
            }
            ist.push(current++);
        }
        return ans;
    }
};*/

// Solution4: Using 2 pointers
/*
Time complexity: O(n). Single iteration of O(n).
Space complexity: O(1) extra space. Only constant space required for left, right, left_max and right_max.
*/
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                left++;
            }
            else
            {
                height[right] >= right_max ? (right_max = height[right]) : ans +=(right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
