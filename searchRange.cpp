#include<iostream>
#include<vector>
using namespace std;

class Solution {
    
public:
void searchRange(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, mid, left, right;
    while (start < end) {
        mid = (start + end) / 2;

        if (nums[mid] > target)
            end = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
        else {
          if (mid == 0 || nums[mid] != nums[mid-1]) {
            start = mid;
            end = mid;
            break;
          }
          end = mid;
        }
        cout << "start:" << start << endl;
        cout << "end:" << end << endl;
        cout << "mid:" << mid << endl;
        cout << endl;
    }
    
    left = start;
    start = 0, end = nums.size() - 11;
    while (start < end) {
        mid = (start + end) / 2;
        if (nums[mid] > target)
            end = mid - 1;
        else if (nums[mid] < target)
            start = mid + 1;
        else 
            start = mid;
    }
    right = start;
    cout << left;
    cout << right;
}
};

int main () {
  vector<int> tmp;
  tmp.push_back(5);
  tmp.push_back(7);
  tmp.push_back(7);
  tmp.push_back(8);
  tmp.push_back(8);
  tmp.push_back(10);
  Solution obj;
  obj.searchRange(tmp, 6);
  return 1;
}
