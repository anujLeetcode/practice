/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class Solution {
    unordered_map<int, int> s;
public:
    vector<int> twoSum (vector<int>& numbers, int target) {
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++) {
            s[numbers[i]] = i;
        }
        
        for (int i = 0; i < numbers.size(); i++) {
          if (s.find(target - numbers[i]) != s.end()) 
          {
            if (numbers[i] <= (target - numbers[i])) {
              result.push_back(i + 1);
              result.push_back(s[target - numbers[i]] + 1);
            } else {
              result.push_back(s[target - numbers[i]] + 1);
              result.push_back(i+1); 
            }
            return result;
          }
        }
        return result;
    }
};
