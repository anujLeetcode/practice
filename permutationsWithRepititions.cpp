
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        backtracking(nums, res, 0);
        return res;
    }
    
private:
    void backtracking(vector<int>& nums, vector<vector<int>>& res,int begin){
        if(begin==nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i<nums.size();i++){
            if((nums[i]!=nums[begin] || i == begin) && checkmiddle(nums,i,begin)){
                swap(nums[i],nums[begin]);
                backtracking(nums, res, begin+1);
                swap(nums[i],nums[begin]);
            }
        }
        
    }
    
    bool checkmiddle(vector<int>& nums, int i , int begin){
        for(int k = begin; k<i; k++)
            if(nums[i] == nums[k])
                return false;
        return true;
    }
};

