/*
215. Kth Largest Element in an Array
DescriptionHintsSubmissionsDiscussSolution
Pick One
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/
#include<iostream>
#include<vector>

using namespace std;

 class Solution {
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int j = start-1;
        for(int i = start; i <= end-1; i++) {
            if(nums[i] <= pivot) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        j++;
        swap(nums[j], nums[end]);
        return j;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;
        k = nums.size() -k;

        if(k < 0 || k > nums.size()) return -1;

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) {
          cout << k;
          if(k == 1) return max(nums[0], nums[1]);
          return min(nums[0], nums[1]);
        }

        int pivot = partition(nums, start, end);
        while(start <= end) {
            int pivot = partition(nums, start, end);

            if(pivot == k) {            
              return nums[k];
            } else if (pivot > k) {
              end = pivot-1;
              cout << "end:" << end << endl;
            } else {
              start = pivot+1;
              cout << "start:" << start << endl;
            }
        }
        return -1;
    }
};

int main() {
  Solution abc;
  vector<int> x;
  x.push_back(3);
  x.push_back(1);
  x.push_back(2);
  x.push_back(4);
  cout << abc.findKthLargest(x, 2);
  return 1;
}

