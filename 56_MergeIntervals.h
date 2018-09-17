/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/
/*
Time complexity : O(nlgn)
Other than the sort invocation, we do a simple linear scan of the list, so the runtime is dominated by the O(nlgn) complexity of sorting.
Space complexity : O(1) (or O(n))
If we can sort intervals in place, we do not need more than constant additional space. Otherwise, we must allocate linear space to store a copy of intervals and sort that.
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
/*bool compare(const Interval Itl1, const Interval Itl2)
{
    return Itl1.start < Itl2.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedItl;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size(); i++)
        {
            // if the merged intervals is empty or if the current intervals does
            // not overlap with the previous, simply append it.
            if(mergedItl.empty() || mergedItl[mergedItl.size() - 1].end < intervals[i].start)
            {
                mergedItl.push_back(intervals[i]);
            }
            // otherwise, there is overlap, so we merge the current and previous intervals
            else
            {
                mergedItl[mergedItl.size() - 1].end = max(mergedItl[mergedItl.size() - 1].end, intervals[i].end);
            }
        }
        return mergedItl;
    }
};*/

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> merged;
        sort(intervals.begin(), intervals.end(), [](const Interval Itl1, const Interval Itl2){return Itl1.start < Itl2.start;});  //Lambda expression
        for(auto itl : intervals)  //Automatic Type Deduction & Range-based for loops
        {
            if(merged.empty() || merged.back().end < itl.start)
                merged.push_back(itl);
            else
                merged.back().end = max(merged.back().end, itl.end);
        }
        return merged;
    }
};
