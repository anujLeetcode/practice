/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
" 3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function
*/

class Solution {
    stack<int> res;
public:
    int calculate(string s) {
        int temp = 0;
        // Add + to the expr and evaluate
        char sign = '+';
        for(int i = 0; i < s.size(); i++) {
            
          if(isdigit(s[i])) {
              temp = temp * 10 + s[i] - '0';
          } 
            
          if(!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
            if(sign == '+') {
              res.push(temp);
              temp = 0;
            } else if(sign == '-')  {
              res.push(-temp);
              temp = 0;
            } else if(sign == '/') {
              int pop = res.top();
              res.pop();
              res.push(pop / temp);
              temp = 0;
            } else {
              int pop = res.top();
              res.pop();
              res.push(pop * temp);
              temp = 0;
            }
            sign = s[i];
          }       
        }
        
        int result = 0;
        while(!res.empty()) {
            result += res.top();
            res.pop();
            
        }
        return  result;
        
    }
};
