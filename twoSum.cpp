class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(int i=0; i < nums.size(); i++) {
          hash[nums[i]] = i+1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
          if(hash.find(target - nums[i]) != hash.end()) {
              
            cout << i << endl;
            cout << hash[target - nums[i]] - 1;
            result.push_back(hash[target - nums[i]] - 1);
            result.push_back(i);
            return result;
          } 
        }
        return result;
    }
};
