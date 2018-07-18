/*
763. Partition Labels
DescriptionHintsSubmissionsDiscussSolution
Pick One
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>char_map (256, 0);
        for(int i = 0; i < S.size(); i++) {
            char_map[S[i] - 'a'] = i;
        }
        int last = 0;
        int idx = -1;
        vector<int> result;
        for(int i = 0; i < S.size(); i++) {
            idx = max(idx, char_map[S[i] - 'a']);
            if(idx == i) {
              result.push_back(i - last + 1);
              last = i + 1;
            }
        }
        return result;
        
    }
};
