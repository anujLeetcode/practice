/*
245. Shortest Word Distance III
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p = -1, q = -1, min_dist = words.size() + 1;
        bool same = word1 == word2;
        for(int i =0; i < words.size(); i++) {
            if(words[i] == word1){
                p = i;
                if(same) swap(p,q);     
            } else if (words[i] == word2) {
                q = i;
            }
            if(p >=0 && q >=0) {
               min_dist = min(min_dist, abs(q-p)); 
            }
        }
        return min_dist;
        
    }
};
