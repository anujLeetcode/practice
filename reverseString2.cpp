/*
Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
    void reverse(vector<char>& str, int start, int end) {
        
        while(start <= end) {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
public:
    void reverseWords(vector<char>& str) {
        std::reverse(str.begin(), str.end());
        int start = 0;
        int end = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ' || i == str.size()-1) {
                if (i == str.size()-1) end = i;
                else end = i-1;
                reverse(str, start, end);
                while(str[i] == ' ') {
                    i++;
                }
                start = i;
                
            } else {
                continue;
            }
        }
        
    }
};
