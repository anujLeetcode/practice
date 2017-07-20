/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
*/







#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

static std::map<int, string> keypad_map = {{0,""}, {1,""}, {2,"abc"}, {3, "def"}, {4, "ghi"},
                                          {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8,"tuv"},
                                          {9, "wxyz"}};

class Solution {
public:

   vector<string> letterCombinationsUtil(string digits, int index, vector<string> &result, string &local){
       if(index == digits.length()) {
         result.push_back(local);
         return result;
       }
       
       string digitChars = keypad_map[digits[index] - '0'];
       for(int i = 0; i < digitChars.size(); i++) {
         local.push_back(digitChars[i]);
         letterCombinationsUtil(digits, index+1, result, local);
         local.pop_back();
       }
       return result;       
   }

    vector<string> letterCombinations(string digits) {
      string  tmp;
      vector<string> result_vector;
      letterCombinationsUtil(digits, 0, result_vector, tmp); 
      return result_vector;   
    }


};

int main() {
  string test("234");
  Solution a;
  a.letterCombinations(test);  
  return 0;
}
