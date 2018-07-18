/*

i438. Find All Anagrams in a String
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// same as sliding window of substring. Just check if the lenght of the window == t.size
class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        int i = 0;
        int j = 0;
        int start = -1;
        int end = -1;
        int count = 0;
        vector<int> result;
        int minWindowStr = -1;
        if(t.size() > s.size()) return result;
        for(int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;   
        }
        
        for(int i = 0; i < s.size(); i++) {
            s_map[s[i]]++; 
            //cout << "1111111" << endl;
            if (s_map[s[i]] <= t_map[s[i]] && minWindowStr == -1 ) {
                count++;
                if(count == t.size()) {
                    start = j;
                    end = i;
                    minWindowStr = i -j + 1; 
                    if(minWindowStr == t.size()) result.push_back(start);
                   // cout << minWindowStr << "@@@" << endl;
                    
                }
            }
            //cout << "2222" << endl;
            if(count == t.size()) {
                while(!s_map[s[j]] || s_map[s[j]] > t_map[s[j]]) {
                    if(s_map[s[j]] > t_map[s[j]]) s_map[s[j]]--;
                    j++;
                    if(i -j + 1 <= minWindowStr) {
                      start = j;
                      end = i;
                      minWindowStr = i -j + 1;  
                      if(minWindowStr == t.size()) result.push_back(start);
                      //cout << minWindowStr << "###" << endl;
                    }
                }
            }
        }
        return result;
    }
};
