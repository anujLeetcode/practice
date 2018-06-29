#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {

public:
  void combination(string s) {
    unordered_map<char, int> s_map;
    int count =0;

    for (int i = 0;i < s.size(); i++) {
      if(s_map[s[i]] == 0) count++;
      s_map[s[i]]++;
    }
    vector<int> s_count(count, 0);
    vector<char> input(count);
    vector<char> output(count);
    int i = 0;
    for(unordered_map<char, int>::iterator it = s_map.begin(); it != s_map.end(); it++) {
      s_count[i] = it->second;
      input[i] = it->first;
      cout << it->first << ":" << it->second << endl;
      i++;
    }
    combinationUtil(input, s_count, 0, output);    
    cout << "----------------------------------" << endl;
    string result;
    combinationUtil2(s, 0, result);
  }

private:

  void combinationUtil2(string str, int begin, string &result) {
    cout << result << endl;
    for (int i = begin; i < str.size(); i++) {
      if(i == begin || str[i] != str[begin]) {
        result.push_back(str[i]);
        combinationUtil2(str, i+1, result);
        result.pop_back();
      }
    }
    return;
  }
    
  void combinationUtil(vector<char>& input, vector<int>& count, int len, vector<char>& output) {
    for(int j = 0; j < len; j++) {
        cout << output[j];
    }
    cout << endl;
    for(int i = 0;i < input.size(); i++) {
 
      if (count[i] == 0) continue;

      output[len] = input[i];
      count[i]--;
      combinationUtil(input, count, len+1, output);
      count[i]++;
    }

  }
};

int main() {
  Solution xyz;
  xyz.combination("abca");
  return 1;
}
