#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  typedef struct TreeNode TreeNode;


 */
class Solution {
    queue<TreeNode*> q;
    void largestValuesUtil(TreeNode* root, vector<int>& result, queue<TreeNode*> q) {
        q.push(root);
        q.push(NULL);
        int level = 0;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(!q.empty()){
                if(!temp) {
                    level++;
                    q.push(NULL);
                }
            }
            if(temp && temp->left) {
                q.push(temp->left);
            } else if(temp && temp->right) {
                q.push(temp->right);
            }    
        }
        vector<int> ans;
        TreeNode* temp = q.front();
        q.pop();
        vector<int> ans;
        ans.push_back(temp->val);
        level = 0;
        while(!q.empty()) { 
          TreeNode* temp = q.front();
          bool first_insert = true;
          q.pop();  
          if(!temp) {
              level++;
              first_insert = true;
          } else {
             if (first_insert) {
               ans[level] = temp->val;
               first_insert = false;
             } else {
               ans[level] = max(temp->val, result[level]);
             }
          }
        }
        result = ans;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        largestValuesUtil(root, result, q);
        return result;
        
    }
};
