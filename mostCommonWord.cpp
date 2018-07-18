/*
819. Most Common Word
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.

*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s;
        unordered_map<string, int> m;
        unordered_set<string> banned_set;
        for(int i = 0; i < banned.size(); i++) {
            banned_set.insert(banned[i]);
        }
        for(int i = 0; i < paragraph.size(); i++) {
            if(isalpha(paragraph[i])) {
                s.push_back(tolower(paragraph[i]));
            } else {
                s.push_back(' ');
            }
        }
        stringstream ss(s);
        string p;
        string result;
        int max_count = 0;
        while(ss >> p) {
            if(banned_set.count(p) == 0) {
                m[p] +=1;
                if(m[p] > max_count) {
                   result = p;
                   max_count = m[p];
                }
            }  
        }
        return result;
    }
};
