#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
    void addOperatorsUtil(string& num, int target, int start, int curr, int prev, string expr, vector<string>& result) {
        cout << expr << ":" << curr << endl;
        if(start == num.size() && curr == target) {
            result.push_back(expr);
            return;
        }
        int temp = 0;
        for(int i = start; i < num.size(); i++) {
            temp = temp * 10 + num[i] - '0';
            if(expr.empty()) {
                //cout << "empty" << endl;
                addOperatorsUtil(num, target , i+1 ,curr+temp, curr, to_string(temp), result);
            } else {
              //cout << "addOperatorsUtil" << endl;
              addOperatorsUtil(num, target , i+1, curr + temp, curr, expr + "+"+ to_string(temp), result);
              addOperatorsUtil(num, target , i+1, curr - temp, curr, expr + "-" + to_string(temp), result);
              addOperatorsUtil(num, target , i+1 , (curr - prev) * temp + prev, prev, expr + "*" +  to_string(temp), result);
            }  
        }
        
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        addOperatorsUtil(num, target, 0, 0, 0, "", result);
        return result;
        
    }
};

int main() {
  class Solution obj;
  obj.addOperators("125", 5);
}
