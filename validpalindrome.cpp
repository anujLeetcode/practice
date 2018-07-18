/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/
class Solution {
public:
    bool isPalindrome(string s) {
        int i =0;
        int j = s.size()-1;
        while(i < j) {
            if (!isalnum(s[i])) i++;
            else if (!isalnum(s[j])) j--;
            else {
                //cout << s[i] << " " << s[j] << endl;
                if(tolower(s[i]) != tolower(s[j]) )return false;
                i++;
                j--;
            }
        }
        return true;
        
    }
};
