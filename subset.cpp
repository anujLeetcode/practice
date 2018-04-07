#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    //{1,2,3}
  int subsetUtil(vector<int>& nums, int start, vector<vector<int> > &result, vector<int> &tmp) {
    if(start > nums.size()) return 0;
        
    for(std::vector<int>::iterator it =  tmp.begin(); it != tmp.end(); ++it) {
      cout << *it << " ,";
    }
    cout << endl;
    result.push_back(tmp);
    for(int i = start; i < nums.size(); i++) {
      tmp.push_back(nums[i]);
      subsetUtil(nums, i+1, result, tmp);
      tmp.pop_back();
    }
    return 1;
  }
    
  vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > result123;
    vector<int> tmp123;
    subsetUtil(nums, 0, result123, tmp123);
    return result123; 
  }
};

int main() {

  vector<int> num123;
  num123.push_back(1);
  num123.push_back(2);
  num123.push_back(3);

  Solution abc;
  abc.subsets(num123);

  return 1;

}


