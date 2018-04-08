Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int, vector<string>> smap;
        std::hash<std::string> hash_str;
        string tmp;
        
        for(int i=0; i < strs.size(); i++) {
            tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());
            smap[hash_str(tmp)].push_back(strs[i]);
        }
        
        vector<vector<string>> a;
        for(std::map<int, vector<string>>::iterator ii = smap.begin(); ii != smap.end() ; ii++ ) {
            a.push_back(ii->second);
        }
        return a;
    }
};
