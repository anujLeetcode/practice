/*
https://leetcode.com/problems/generate-parentheses/#/description

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

/*

#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesisUtil(vector<string> &result, string str, int open, int close, int n) {
        if(str.size() == n * 2) {
            result.push_back(str);
            cout <<"insert: " << str << endl;
            return result;
        }
        
        if(open < n) {
            generateParenthesisUtil(result, str + '(', open+1, close, n);
            cout << "open:" << open << " close:" << close << " str:" << str << endl; 
        }
        if(close < open) {
            generateParenthesisUtil(result, str + ')', open, close+1, n);
            cout << "open:" << open << " close:" << close << " str:" << str << endl; 
        }
        return result;
    }
    
    vector<string> generateParenthesis(int n) {
      vector<string> result_string;
      if(n == 0) return result_string;
      generateParenthesisUtil(result_string, "", 0, 0, n);
      return result_string;
        
    }
};

int main() {
  Solution abc;
  abc.generateParenthesis(3);
  return 1;
}


