/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> merged;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const Interval Itl1, const Interval Itl2){return Itl1.start < Itl2.start;});
        for(auto itl : intervals)
        {
            if(merged.empty() || merged.back().end < itl.start)
                merged.push_back(itl);
            else
                merged.back().end = max(merged.back().end, itl.end);
        }
        return merged;
    }
};*/
// non-overlapping intervals
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> merged;
        bool hasInserted = false;
        sort(intervals.begin(), intervals.end(), [](const Interval Itl1, const Interval Itl2){return Itl1.start < Itl2.start;});
        for(auto itl : intervals)
        {
            if(merged.empty() || !hasInserted)
            {
                if(itl.end < newInterval.start)
                {
                    merged.push_back(itl);
                }
                else if(newInterval.end < itl.start )
                {
                    merged.push_back(newInterval);
                    merged.push_back(itl);
                    hasInserted = true;
                }
                else
                {
                    itl.start = min(itl.start, newInterval.start);
                    itl.end = max(itl.end, newInterval.end);
                    merged.push_back(itl);
                    hasInserted = true;
                }
            }
            else
            {
                if(merged.back().end < itl.start)
                {
                    merged.push_back(itl);
                }
                else
                {
                    merged.back().start = min(merged.back().start, itl.start);
                    merged.back().end = max(merged.back().end, itl.end);
                }
            }
        }
        if(!hasInserted)
            merged.push_back(newInterval);
        return merged;
    }
};
