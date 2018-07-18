/*

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
*/
class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) m[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        auto v1 = m[word1];
        auto v2 = m[word2];
        int res = INT_MAX;
        while(!v1.empty() && !v2.empty()){
            res = min(res, abs(v1.back() - v2.back()));
            v1.back() > v2.back() ? v1.pop_back() : v2.pop_back();
        }
        return res;
    }

private:
    unordered_map<string, vector<int>>m;
};
