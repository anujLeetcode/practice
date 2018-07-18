/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    queue<TreeNode*> q;
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> result;
      if(!root) return result;
      q.push(root);
      //q.push(NULL);
      while(!q.empty()) {
          int n = q.size();
          result.push_back(q.back()->val);
          for(int i = 0; i < n; i++) {
             TreeNode* temp = q.front();
             q.pop();
             if(temp) {
                if(temp->left) {
                    q.push(temp->left);
                } 
                if(temp->right) {
                    q.push(temp->right);
                }
             }
          }
      }
      return result;
    }
};
