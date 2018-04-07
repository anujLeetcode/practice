/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return -1;
        if(nums.size() == 1 ) {
            if(nums[0] == target) return 0;
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end)/2;
        
        while(start <= end) {
            if((end - start) == 1) {
              if(arr[start] == target) return start;
              if(arr[end] == target) return end;
              return -1;
            }
            int mid = (start + end)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[start] < nums[mid]) {
                if(nums[start] <= target && nums[mid] > target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                 if(nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;   
        
        
    }
};


int main() {
  vector<int> arr;
  arr.push_back(5);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  Solution obj;
  cout << obj.search(arr, 1);
  return 1;
}
