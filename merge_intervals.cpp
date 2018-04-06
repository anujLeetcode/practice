#include<iostream>
#include<vector>

using namespace std;

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

typedef struct Interval Interval;
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](struct Interval a, struct Interval b) {return (a.start < b.start);});
        vector<Interval> result;
        if(intervals.size() == 0) return result;
        struct Interval previous{intervals[0].start, intervals[0].end};
        if(intervals.size() == 1) {
            result.push_back(previous);
            return result;
        }
        
        for(int i = 1; i < intervals.size(); i++) {
          if(previous.end >= intervals[i].start) {
            previous.end = max(previous.end, intervals[i].end);
          } else {
            result.push_back(previous);
            previous.start = intervals[i].start;
            previous.end = intervals[i].end;
          }
        }
        
        result.push_back(previous);
        return result;
          
    }
};
