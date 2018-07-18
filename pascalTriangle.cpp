/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

1  
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 

*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr(rowIndex+1);
        arr[0] = 1;
        for(int i = 0; i <= rowIndex; i++) {
            for(int j = i; j > 0; j--) {
                arr[j] = arr[j] + arr[j-1];
            }
        }
        return arr;
    }
};
