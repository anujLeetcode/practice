#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-2;
        if(nums.size()==1) return;

        if(nums.size() == 2) {
            if(nums[0] < nums[1])
                swap(nums[0], nums[1]);
            return;
        }
        while(k >= 0) {
            if(nums[k] < nums[k+1])
               break;
            k--;
        }
        if(k==-1) return;
        int j = k+2;
        int l=k+1;
        //3286
        while(j < nums.size()){
            if(nums[j] < nums[k+1] && nums[j] > nums[k]) {
                l = j;
            }
            j++;    
        }
        swap(nums[k], nums[l]);
        sort(nums.begin()+k+1, nums.end());               
    }
};

int main() {

 Solution abc;
 vector<int> test {2, 3, 1};
 abc.nextPermutation(test);
 for(vector<int>::iterator it = test.begin(); it != test.end(); it++)
 {
   cout << *it << ", ";
 }

}
