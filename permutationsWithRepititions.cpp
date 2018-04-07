ass Solution {
public:
    int permuteUniqueUtil(vector<int>& nums, vector<vector<int>>result, int start) {
       for(int i = start; i++ ; i < nums.size()) {
          if(start == nums.size()) {
            result.push_back(nums);
            return 1;
          }

          if(nums[i] != nums[start]) {
            swap(nums[i], nums[start]);
            permuteUniqueUtil(nums, result, start+1);
            swap(nums[i], nums[start]);
          }
       }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     vector<vector<int>>result;
     permuteUniqueUtil(nums, result, 0);
     result result; 
        
    }
};
