/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for(int num : nums) {
            num_map[num] = 1;
        }
        
        int longest_consecutive = 0;
        int current_longest_consecutive = 0;
        for (int num : nums) {
          if (num_map.find(num) != num_map.end()) {
            current_longest_consecutive = 1;
            int current_num = num;
            if (num_map.find(num-1) == num_map.end()) {
               while(num_map.find(current_num + 1) != num_map.end()) {
                 current_num += 1;
                 current_longest_consecutive += 1;
               }
            }
          }
          longest_consecutive = max(current_longest_consecutive, longest_consecutive);
        }
        return longest_consecutive;  
    }
};
