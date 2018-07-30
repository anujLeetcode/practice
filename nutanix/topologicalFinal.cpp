#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
using namespace std;

// Using topological sort to solve this.

string solution(vector< vector<int> > prerequisites, int numCourse, int rows);

int main() {
        int numCourse, rows, i;
        string result;

        cin >> numCourse;
        cin >> rows;
        vector< vector<int> > prerequisites(rows, vector<int>(2));
        for (i=0;i<rows;i++) {
                cin >> prerequisites[i][0];
                cin >> prerequisites[i][1];
        }

        result = solution(prerequisites, numCourse, rows);
        cout << result;
        return 0;
}

void topological(vector<set<int> > prerequisite_set, vector<bool> visited, vector<int> indegree, int numCourse, vector<int>& ans, vector<vector<int>>& result) {

    if(ans.size() ==  numCourse) {
      result.push_back(ans);
      // for (int x : ans) {
      //  cout << x << "#";
      //}
      //cout << endl;
      return;
    }

    for (int i = 0; i < numCourse; i++) {
       if(!visited[i] && indegree[i] == 0) {
         ans.push_back(i);
         visited[i] = true;
         for (auto it = prerequisite_set[i].begin(); it != prerequisite_set[i].end(); it++) {
           --indegree[*it];
         }

         topological(prerequisite_set, visited, indegree,  numCourse, ans, result);

         for (auto it = prerequisite_set[i].begin(); it != prerequisite_set[i].end(); it++) {
           ++indegree[*it];
         }
         visited[i] = false;
         ans.pop_back();
       }
    }
}
string solution(vector< vector<int> > prerequisites, int numCourse, int rows){
        if (numCourse <= 0) return "Invalid";
        
        // Vector of sets to map a course -> all dependent courses
        vector<set<int> > prerequisite_set(numCourse);
        for (int i = 0; i < prerequisites.size(); i++) {
          // cout << prerequisites[i][0] << ":" << prerequisites[i][1] << endl;
          prerequisite_set[prerequisites[i][0]].insert(prerequisites[i][1]);
        }

        vector<int> indegree(numCourse);
        vector<bool> visited(numCourse, false);
        
        // IF the above problem is represented as a DAG. indegree represents the number of incoming edges.
        for (int i = 0; i < numCourse; i++) {
           for (auto it = prerequisite_set[i].begin(); it != prerequisite_set[i].end(); it++) {
              ++indegree[*it];
           }
        }
        vector<vector<int>> result;
        vector<int> ans;
        // Return all possible topological sort combinations and sort the results .
        topological(prerequisite_set, visited, indegree, numCourse, ans, result);
        sort(result.begin(), result.end());
        if (result.empty()) {
          string str = "Invalid";
          return str;
        }
        string str;
        for (int x : result.front()) {
          str += to_string(x) + " ";
        }
        return str;
}

