/*
464. Can I Win
DescriptionHintsSubmissionsDiscussSolution
Pick One
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example
*/

class Solution {

    // player A = 3
    // Player B = 7
    // is same as PLayer A = 7 , Player B =3. So record the result
    unordered_map<int, bool> combo_map;
    bool canIWinHelper(int maxChoosableInteger, int desiredTotal, vector<bool> &used) {  
      if(desiredTotal <= 0) return false;
      int key = bool2int(used);
      if(combo_map.find(key) != combo_map.end()) return combo_map[key];
        
      for(int i = 1; i <= maxChoosableInteger; i++) {
        if(!used[i]) {
          used[i] = true;
          if(!canIWinHelper(maxChoosableInteger, desiredTotal - i, used)){
            used[i] = false;
            combo_map[key] = true;
            return true;
          }
          used[i] = false;
        }
      }
      combo_map[key] = false;
      return false;
    }
    int bool2int(vector<bool> &bool_vec) {
        int i = 0;
        for(auto a : bool_vec) {
            // remember <<=
            i <<= 1;
            if(a == true) i |= 1;
        }
        return i;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if(maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal) return false;
        vector<bool> used(maxChoosableInteger+1, false);
        return canIWinHelper(maxChoosableInteger, desiredTotal, used);
    }
};
