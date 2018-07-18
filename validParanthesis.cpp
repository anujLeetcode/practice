/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

*/
class Solution {
    stack<char> char_stack;
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); i++) {
          if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
            char_stack.push(s[i]);
          } else if (s[i] == ')') {
              if (char_stack.empty() || char_stack.top() != '(') return false;
              char_stack.pop();
          } else if (s[i] == ']') {
              if (char_stack.empty() || char_stack.top() != '[') return false;
              char_stack.pop();
          } else if (s[i] == '}') {
              if (char_stack.empty() || char_stack.top() != '{') return false;
              char_stack.pop();
          }
        }   
        if(!char_stack.empty()) return false;
        return true;
    }
};
