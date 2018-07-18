/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

#include<iostream>
#include<unordered_map>

using namespace std;

class TwoSum {
    std::unordered_map<int,int> x;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        x[number] += 1; 
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        int a , b;
        for(unordered_map<int, int>::iterator ii = x.begin(); ii != x.end(); ii++) {
            //int temp = ii->first;
             a = ii->first;
             b = value - a;
             // use count correctly. not in the first if
             if(a == b && x[a] > 1) return true;
             if(a != b && x.count(b) > 0) return true;
        }
        return false;
    }
};


int main() {
  TwoSum a;
  a.add(0);
  a.add(0);
  a.find(0);
  return 1;
}
