#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int permuteUtil(vector<int>& nums, vector<vector<int>> &result,
        int start) {

      if(start == nums.size() -1) {
        result.push_back(nums);
      }
      for (int i = start; i < nums.size() ; i++) {
        swap(nums[start], nums[i]);
        // start +1...careful...
        permuteUtil(nums, result, start+1);
        swap(nums[start], nums[i]);
      }
      return 1;
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      permuteUtil(nums, result, 0);
      return result;
    }
};

int main() {
  vector<int> input;
  input.push_back(1);
  input.push_back(2);
  input.push_back(3);
//  input.push_back(4);
  Solution abc;
  abc.permute(input);
  return 1;
}
