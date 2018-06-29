/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples 1:

Input: 1
Output: []
Examples 2:

Input: 37
Output:[]
Examples 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Examples 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]

*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> factors;
        vector<vector<int>> result;
        getFactors(2, n, factors, result);
        return result;
    }
    
    void getFactors(int start, int n, vector<int>& factors, vector<vector<int>>& result) {
        for(int i = start; i <= sqrt(n); i++) {
            if(n % i != 0) continue;
            factors.push_back(i);
            factors.push_back(n/i);
            result.push_back(factors);
            factors.pop_back();
            getFactors(i, n/i, factors, result);
            factors.pop_back();
        }
    }
};

