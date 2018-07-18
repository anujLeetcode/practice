#include<string>
#include<iostream>

using namespace std;

class node {
 public:
    node *next[26];
    bool eos;
    node() {
      memset(next, 0, sizeof(next));
      eos = false;
    }
    
};
typedef struct node node;

class Trie {
    node *root;
public:
    /** Initialize your data structure here. */
    
    Trie() {
      root = new node();  
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      node *tmp = root;
      for(int i=0; i < word.size(); i++) {
        if(tmp->next[word[i]-'a'] == NULL){
          tmp->next[word[i]-'a'] = new node();
        }
        tmp = tmp->next[word[i]-'a'];
      }
      tmp->eos = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* tmp = root;
        for(int i=0; i < word.size(); i++) {
          if(tmp->next[word[i]-'a']) {
            tmp = tmp->next[word[i]-'a'];
          } else {
            return false;
          }   
        }
        //
        if(tmp->eos) {
            return true;;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      node* tmp = root;
      for(int i=0; i < prefix.size(); i++) {
        if(tmp->next[prefix[i]-'a']) {
          tmp = tmp->next[prefix[i]-'a'];
        } else {
          return false;
        }
      }   
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
  Trie obj = Trie();
  string word = "bc";
  obj.insert(word);
  bool param_2 = obj.search("a");
  bool param_3 = obj.startsWith("a");
  return 1;
}
