/*
https://leetcode.com/problems/plus-one/#/description

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int tmp = 0;
      int carry = 1;
      if(digits.empty()) {
        return digits;
      }

      for(int i=digits.size() - 1; i >= 0; i--) {
        tmp = digits[i] + carry;
        carry = tmp / 10;
        digits[i] = tmp % 10;
        tmp = 0;

      }
      if(carry) {
        digits.insert(digits.begin(), carry);
      }
      for(int i = 0; i < digits.size(); i++)
        cout << digits[i] << endl;
      return digits;
    }
};

int main()
{
  Solution xyz;
  vector<int> x = {9,9};
  xyz.plusOne(x);
  return 1;
}
