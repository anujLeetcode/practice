//Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
#include<iostream>
#include<string>
#include<vector>
#include <sstream> 
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
       vector<string> result;
       //if(nums.size() == 0) return result;
       int start = lower;
       int end =  upper + 1;
       for(int i = 0; i <= nums.size() || start < upper; i ++) {
         stringstream ss;
         if(i < nums.size()) 
           end = nums[i];
         else 
           end = upper + 1;
         if((end - start) == 1 || start == end) {
            start = end;
 
         } else if ((end - start) == 2) {
            ss << start + 1 << endl;
            result.push_back(ss.str());
            start = end;
         } else {
            ss << start + 1 << "<-" << end -1 << endl;
            result.push_back(ss.str());
            start = end;
         }
       }
       return result;
    }
};

int main() {
 Solution obj;
 vector<int> input;
 input.push_back(0);
 input.push_back(1);
 input.push_back(3);
 input.push_back(50);
 input.push_back(75);

vector<string> result = obj.findMissingRanges(input, 0, 99);
for(int i = 0; i < result.size(); i++) {
  cout << result[i];
}
}
