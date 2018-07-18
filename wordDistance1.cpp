/*
243. Shortest Word Distance
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int N=(int)words.size(),mini=N;
        for (int i=0,p=-1,q=-1; i<N; ++i){
            //bool found=false;
            if (words[i]==word1){ p=i; }
            if (words[i]==word2){ q=i; }
            if (p>=0 && q>=0)
                mini=min(mini,abs(p-q));
        }
        return mini;
    }
};
