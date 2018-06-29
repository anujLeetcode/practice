/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

int rob(vector<int>& nums) {
        vector<int> help;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 or i == 1) {
                help.push_back(nums[i]);
                if (nums[i] > res) {
                    res = nums[i];
                }
            } else {
                if (i >= 3) {
                    int helper = max(nums[i] + help[i - 2], nums[i] + help[i - 3]);
                    help.push_back(helper);
                    if (helper > res) {
                        res = helper;
                    }
                } else {
                    int helper = nums[i] + help[i - 2];
                    help.push_back(helper);
                    if (helper > res) {
                        res= helper;
                    }
                }
            }
        }
        return res;
    }
