/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
     void combineUtil(int n, int k, int start, vector<int>& local, vector<vector<int>>& result) {
        if(k == local.size()) {
            result.push_back(local);
            return;
        }
        for(int i = start; i <= n; i++) {
            local.push_back(i);
            combineUtil(n, k, i+1, local, result);
            local.pop_back();        
        } 
    }
public:
    vector<vector<int>> combine(int n, int k) {
       vector<int> local;
       vector<vector<int>> result;
       combineUtil(n, k, 1, local, result);
       return result;
    }
};
