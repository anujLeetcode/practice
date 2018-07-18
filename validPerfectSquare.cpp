/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 1;
        long end = num;
        long mid = (start + end) /2;
        if(num == 1) return true;
        //remember <=
        while(start <= end) {
            long mid = (start + end) /2;
            if(mid * mid == num) {
                return true;
            } else if (mid * mid < num) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return false ;     
    }
};
