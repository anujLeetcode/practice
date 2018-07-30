#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int>);
int next(int i, vector<int> &ar); 
void clearTheFailedPath(int start, int end, vector<int> &nums);

int solution(vector<int> ar) { 
    set<vector<int>> result;
    unordered_map<vector<int>, vector<int> > result_map;
    vector<int> temp;
    for (int start = 0; start < ar.size() && ar[start] != 0; start++) {
        int slow = start, fast = start;
        int count = 0;
        // cout << "start: " << start << "marker: " << marker[start] << "ar: " << ar[start] << endl;
        while (count < ar.size()) {
            slow = next(slow, ar); 
            fast = next(fast, ar);
            fast = next(fast, ar);
            temp.push_back(slow);
            if (fast == slow && temp.size() != ar.size()) {
                if (slow != next(slow, ar)) {
                    vector<int> key(temp);
                    std::sort(key.begin(), key.end());
                    result_map[key].push_back(temp); 
                    //result.insert(temp);
                    break;
                }
                else break;
            }
            count++;
        }
        temp.clear();
    }

    for(auto it : result_map) {
      result.insert(it->second.first);
    }    

    cout << result.size() << endl;
    for (auto x : result) {
      for (int j = 0; j < x.size(); j++) {
        cout << x[j] << " ";
      }
      cout << "\n";
    }
    return result.size();
}

int next(int i, vector<int> &nums) {
  int n = nums.size();
  return nums[i]+i>=0?(i + nums[i])%n:(i+nums[i])%n==0?(i + nums[i])%n+n:0;
}

void clearTheFailedPath(int start, int end, vector<int> &nums) {
    // sets all elements from 'start' to 'end' (not including the 'end') to zero
    while (start != end || start == next(start, nums)) { // 'end' is set to zero if it's a self-loop
        int nextIndx = next(start, nums);
        nums[start] = 0;
        if (start == nextIndx) break;
        start = nextIndx;
    }
}

int main() {
  int n, i, result;

  cin >> n;
  vector<int> ar(n);
  for (i=0;i<n;i++) {
    cin >> ar[i];
  }
	
  result = solution(ar);	

  //cout << result;
  return 0;
}
