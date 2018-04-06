#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void search(string&word, int pos, int count, string path, vector<string>& v){
        if(pos == word.length()) { v.push_back(path+(count? to_string(count):"")); return ; }
        search(word, pos+1, count+1, path, v);
        search(word, pos+1, 0, path+(count? to_string(count):"")+word[pos], v);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> v;
        search(word, 0, 0, "", v);
        return v;
    }
};

int main() {
  Solution abc;
   vector<string> result = abc.generateAbbreviations("word");
   for(vector<string>::iterator it = result.begin(); it != result.end() ; it++) {
     cout << *it << endl;
   }
   
}
