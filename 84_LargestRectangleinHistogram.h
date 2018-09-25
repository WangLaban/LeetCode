/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.
*/
// Solution1: Only calucate area when reaching local maximum value
/*class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            if(i < heights.size() - 1 && heights[i] <= heights[i + 1])
                continue;
            int minHeight = heights[i];
            for(int j = i; j >= 0; j--)
            {
                minHeight = min(minHeight, heights[j]);
                res = max(res, minHeight * (i - j + 1));
            }
        }
        return res;
    }
};*/
// Solution2: Keep a non-descending stack
/*class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, i = 0;
        heights.push_back(0);
        stack<int> s;
        while(i < heights.size())
        {
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else
            {
                int idx = s.top();
                s.pop();
                int width = s.empty() ? i : (i - 1 - s.top());
                res = max(res, width * heights[idx]);
            }
        }
        return res;
    }
};*/

// Solution3: Keep a non-descending stack, if the vector height is not allowed to be change
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, i = 0;
        stack<int> s;
        while(i < heights.size())
        {
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else
            {
                int idx = s.top();
                s.pop();
                int width = s.empty() ? i : (i - 1 - s.top());
                res = max(res, width * heights[idx]);
            }
        }
        while(!s.empty())
        {
            int idx = s.top();
            s.pop();
            int width = s.empty() ? i : (i - 1 - s.top());
            res = max(res, width * heights[idx]);
        }
        return res;
    }
};
