#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long temp = 0;
        
        bool minus = (x < 0) ? true : false;
        
        while(x != 0) {
            temp = temp * 10 + (x%10);
            x = x / 10;
        }
        
        if(minus) {
          temp = temp * -1;
        }
        if(temp < Integer.MIN_VAL || temp > Integer.MAX.VAL) return 0;
        return temp;     
    }
};

int main() {
  Solution x;
  cout << x.reverse(-321);
}
