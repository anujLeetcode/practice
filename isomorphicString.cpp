/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> charMap;
        map<char, char> charMapR;
        for (int i = 0; i < s.size(); i++) {
            charMap.insert({ s[i], t[i] });
            charMapR.insert({ t[i], s[i] });
        }
        string tRecon, sRecon;
        for (int i = 0; i < s.size(); i++) {
            tRecon += charMap[s[i]];
            sRecon += charMapR[t[i]];
        }
        return tRecon == t && sRecon == s;
    }
};
