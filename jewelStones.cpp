771. Jewels and Stones
DescriptionHintsSubmissionsDiscussSolution
Pick One
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

class Solution {
    unordered_set<char> jewel_set;
public:
    int numJewelsInStones(string J, string S) {
        for(int i=0; i < J.size(); i++) {
            jewel_set.insert(J[i]);
        }
        
        int jewel_count = 0;
        for(int j = 0; j < S.size(); j++) {
            if(jewel_set.count(S[j]) > 0) {
                jewel_count++;
            }
        }
        return jewel_count;
        
    }
};
