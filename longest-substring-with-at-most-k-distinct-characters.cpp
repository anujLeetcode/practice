#include<iostream>
#include<string>

using namespace std;

/// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

/// Given a string, find the length of the longest substring T that contains at most k distinct characters.
/// For example, Given s = “eceba” and k = 2,
/// T is "ece" which its length is 3.


/// ****************** Similar one*****************
///  https://leetcode.com/problems/longest-repeating-character-replacement/description/
/// Given a string that consists of only uppercase English letters, you can replace any letter in the string
/// with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

//Note:
//Both the string's length and k will not exceed 104.


class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(s.size() == 0) return 0;
    if(k <= 0) return 0;
        
    int i=0;
    int j=0;
    int count[256]={0};
    int result = 0, distinct=0;
    for(int i=0; i< s.size(); i++) {
      if(count[s[i]] == 0) distinct++;
      count[s[i]]++;
            
      while(distinct > k) {
        if(count[s[j]] > 0)
          count[s[j]]--; 
          if(count[s[j]] == 0)
            distinct--;
          j++;
      }
      result = max(result, i - j + 1);   
    }
    return result; 
  }
};

int main() {

 Solution abc;
 cout << abc.lengthOfLongestSubstringKDistinct("eceaaaaaaab", 2);
}
