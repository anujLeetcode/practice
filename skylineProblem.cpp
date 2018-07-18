// Skyling problem
// https://www.youtube.com/watch?v=Cv0ft2dFz80

/* 
1. Mark key points for each given building.
2. For each key point if buildings with more heigh overlap, change its y to
   the height of tallest overlapping building.
*/

#include<vector>
#include<iostream>
#include<list>

using namespace std;

class Solution {

    list<pair<int, int> > merge(list<pair<int, int> > first_half, list<pair<int, int> > second_half) {
      list<pair<int, int> > result; 
      int a_last_height = 0;
      int b_last_height = 0;
      while(!first_half.empty() && !second_half.empty()) {
        pair<int, int> a = first_half.front();
        pair<int, int> b = second_half.front();
        if(a.first < b.first) {
          if(a.second < b_last_height) {
            a.second = b_last_height;
            a_last_height = a.second;
          }
          first_half.pop_front();
          result.push_back(a);
        }
        else if(b.first < a.first) {
          if(b.second < a_last_height) {
            b.second = a_last_height;
            b_last_height = b.second;
          }
          second_half.pop_front();
          result.push_back(a);
        } else {
            pair<int, int> temp;
            if(b.second < a.second) {
              temp.second = a.second; 
           } else {
              temp.second = b.second; 
           }
           temp.first = a.first;
           result.push_back(temp);
        }
      }
      while(!first_half.empty()) {
        result.push_back(first_half.front());
        first_half.pop_front();
      }
       
      while(!second_half.empty()) {
        result.push_back(second_half.front());
        second_half.pop_front();
      }

      return result;
    }
    
    
    list<pair<int, int> > getSkyline_rec(int low, int high, vector<vector<int> >& buildings) {
        list<pair<int, int> > result;
        if(low > high) {
            return result; 
        }

        else if (low == high) {
          int x = buildings[low][0];
          int y = buildings[low][1]; 
          int h = buildings[low][2];
          pair<int, int> a(x, h);
          pair<int, int> b(y, 0);
          result.push_back(a);
          result.push_back(b);
          return result;   
            
        } else {
          int mid = (low + high) / 2;
          list<pair<int, int> > first_half = getSkyline_rec(low, mid, buildings);
          list<pair<int, int> > second_half = getSkyline_rec(mid + 1, high, buildings);  
          return merge(first_half, second_half);   
        }
    }
 public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        int size = buildings.size();
        list<pair<int, int> > result = getSkyline_rec(0, size -1, buildings);
        vector<pair<int, int> > v(std::begin(result), std::end(result));  
        return v;
     }
};

int main() {
  return 0;
}
