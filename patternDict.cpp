/* SLIGHTLY MODIFIED SOLUTION. BUT SIMILAR LOGIC
Input:  
dict = ["abb", "abc", "xyz", "xyy"];
pattern = "foo"
Output: [xyy abb]
Explanation: 
xyy and abb have same character at index 1 and 2 like the pattern

Input:  
dict = ["abb", "abc", "xyz", "xyy"];
pat = "mno"
Output: [abc xyz]
Explanation: 
abc and xyz have all distinct characters, similar to the pattern

Input:  
dict = ["abb", "abc", "xyz", "xyy"];
pattern = "aba"
Output: [] 
Explanation: 
Pattern has same character at index 0 and 2. 
No word in dictionary follows the pattern.

Input:  
dict = ["abab", "aba", "xyz", "xyx"];
pattern = "aba"
Output: [aba xyx]
Explanation: 
aba and xyx have same character at index 0 and 2 like the pattern
*/

class Solution {
    string encodeString(string s) {
        int j = 0;
        unordered_map<char, int> m;
        string result;
        for(int i=0; i < s.size(); i++) {
          if(m.find(s[i]) == m.end()) {
            m[s[i]] = j;
            j++;
          }
          result.append(to_string(m[s[i]]));
        }
        //cout << result << endl;
        return result;
    }
    
  public:
    bool wordPattern(string pattern, string str) {
        istringstream ss(str);
        string s;
        string pat = encodeString(pattern);
        cout << pat << endl << endl << endl;
        
        while(ss >> s) {
          
          if( pat == encodeString(s)) return true;
          cout << s << endl;
          s.clear();
          cout << s;
          
        }
        return false; 
    }
};
