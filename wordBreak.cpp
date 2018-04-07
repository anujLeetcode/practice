#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;
 
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
  vector<bool> wb(s.size(), false);

  if(wordDict.size() == 0 || s.size() == 0) return false;

  
 
  for (int i = 0; i < s.length(); i++) 
  { 
    for(int j = i; j >= 0 ; j--) 
    {
        if(i == 0 || j == 0 || wb[j-1] == true)
        {  
          if(std::find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end())
          {
            wb[i] = true;
            break;
          } 
        }
      }
    }
    return wb[s.length() -1];  
  }
};

int main() 
{
  class Solution abc;
  string input("ilikesamsungmobile");
  vector<string> dict{ "i", "like", "sam", "sung", "samsung", "mobil", "ice", "cream", "icecream", "man", "go", "mango"};

  cout << abc.wordBreak(input, dict);

}
