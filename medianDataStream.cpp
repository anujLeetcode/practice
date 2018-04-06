#include<iostream>
#include<queue>
using namespace std;
class MedianFinder {
   
     // MAX_HEAP by default 
     priority_queue<int> left_half;
   
     // MIN_HEAP by default
     priority_queue<int, vector<int>, greater<int> > right_half;
 
public:
    /** initialize your data structure here. */
 
    MedianFinder() { }
    
    void addNum(int num) {
        if(left_half.empty() || left_half.top() > num) {
            left_half.push(num);
        } else {
            right_half.push(num);
        }
        
        cout << "before rebalanace";
        //rebalance
        if((left_half.size() >  (right_half.size() + 1))) {
            int temp = left_half.top();
            left_half.pop();
            right_half.push(temp);   
        } else if(right_half.size() > (left_half.size() + 1)) {
            int temp = right_half.top();
            right_half.pop();
            left_half.push(temp);            
        }
    }
    
    double findMedian() {     
      if(left_half.size() == right_half.size()) {
        if (left_half.empty()) return 0;
        return ((right_half.top() + left_half.top()) / 2.0);
      } else if((right_half.size() > left_half.size()) == 1) {
        return right_half.top();
      } 
      return left_half.top();
        
    }
};


int main() {

  MedianFinder obj =  MedianFinder();
  obj.addNum(1);
  obj.addNum(2);
  cout << obj.findMedian();
  return 0;
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 */
