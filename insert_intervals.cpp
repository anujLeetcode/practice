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
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int start = -1;
        int end = -1;
        vector<Interval> result;
        if(intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }
        
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i].end < newInterval.start) {
              result.push_back(intervals[i]);
            } else if(intervals[i].start > newInterval.end) {
              result.push_back(newInterval); 
              while(i < intervals.size()) {
                 result.push_back(intervals[i]);
                 i++;
              }
              return result;
                
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        result.push_back(newInterval);
        return result;
    }
};
