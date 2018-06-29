/*

266. Palindrome Permutation
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

*/
class Solution {
public:
bool canPermutePalindrome(string s) {
    int dict[256] = {0};
    for (auto c: s)
        dict[c]++;
    int cnt = 0;
    for (int i=0; i<256; i++){
        if (dict[i] % 2 != 0)   cnt++;
    }
    
    return cnt<=1;
}
};

