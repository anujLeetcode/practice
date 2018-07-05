/*
387. First Unique Character in a String
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
    unordered_map<char, int> char_map;
public:
    int firstUniqChar(string s) {
        for(auto a : s) {
            char_map[a] += 1;
        }
         for(int i = 0; i < s.size(); i++) {
            if(char_map[s[i]] == 1) {
                return i;
            }
        }
        return -1;        
    }
};
