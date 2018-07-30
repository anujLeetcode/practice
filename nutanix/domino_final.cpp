#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int>);
int next(int i, vector<int> &ar);
void clearTheFailedPath(int start, int end, vector<int> &nums);

// The solution assumes that the loop can be in any direction.
//E.g 
// 6
// 2 -1 1 2 2 2
// 0 2 3 5 1 -> It can move forward and backward both. I am sorting the result to print the output as asked.
// but I think this could mess up the sequence in a loop.

int solution(vector<int> ar) {
    set<vector<int>> result;
    vector<int> temp;
    for (int start = 0; start < ar.size(); start++) {
        int slow = start, fast = start;
        int count = 0;
        if (ar[start] == 0) continue;
        while (count < ar.size()) {
            // Use a slow and fast pointer. When the slow and fast pointers meet, there is a loop.
            slow = next(slow, ar);
            fast = next(fast, ar);
            fast = next(fast, ar);
            temp.push_back(slow);
            // Check if all the indices are not included when we detect a loop
            if (fast == slow && temp.size() != ar.size()) {
                if (slow != next(slow, ar)) {
                    for(int x : temp) {
                       //cout << x << "&" <<endl;
                       ar[x] = 0;
                    }
                    // Sort the indices before inserting.
                    // For this input the loop can move to the left too.
                    // 6
                    // 2 -1 1 2 2 2
                    sort(temp.begin(), temp.end());
                    result.insert(temp);
                    break;
                }
                else break;
            }
            count++;
        }
        temp.clear();
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

