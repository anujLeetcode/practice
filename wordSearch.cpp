#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    bool DFS(vector<vector<char> >& board, int row, int col,string word, int wordLen) {
       if(board[row][col] != word[wordLen]) return false;
       if(wordLen == word.size()) return true;
       bool ret = false;
       if(row > 1) { ret = DFS(board, row-1, col, word, wordLen + 1);}
       if((row < board.size() - 1) && !ret) {ret = DFS(board, row+1, col, word, wordLen + 1);}
       if((col > 0) && !ret) {ret = DFS(board, row, col-1, word, wordLen + 1);} 
       if((col < board[0].size() - 1) && !ret) {ret = DFS(board, row, col+1, word, wordLen + 1);}
       return ret;
    }   
public:
    bool exist(vector<vector<char> >& board, string word) {
      if(board.size() || board[0].size() || word.size() != 0) {
        for(int i = 0; i < board.size(); i++) {
          for(int j = 0; j < board[0].size(); j++) {
            if(DFS(board, i, j, word, 0)) return true;
          }
        } 
      }
      return false;   
    }
};

int main() {
  return 1;
}
