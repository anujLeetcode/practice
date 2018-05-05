#include<iostream>
#include<string>
#include<vector>

using namespace std;

class solution 
{

void combinationUtil(string& s, int k, vector<int>& arr) {
  string temp;
  if (k == arr.size()) {
    for(int i = 0; i < arr.size(); i++) {
      if(arr[i]) {
        temp += s[i];
      }
    }
    cout << temp << endl;
    return;
  }

  arr[k] = 0;
  combinationUtil(s, k+1, arr);

  arr[k] = 1;
  combinationUtil(s, k+1, arr);
}


public:
  void combination(string &s) {
    vector<int> a(s.size(), 0);
    combinationUtil(s, 0, a); 
  }
};

int main() {
  solution x;
  string y("abcd");
  x.combination(y);
  return 1;
}
