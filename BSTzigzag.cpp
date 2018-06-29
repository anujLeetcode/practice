/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;
        
        queue<TreeNode*> q;
        if(!root) return result;
        bool reverse_vector = false;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
          TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(reverse_vector) {
                  reverse(temp.begin(), temp.end());
                  reverse_vector = false;
                } else {
                  reverse_vector = true;
                }
                result.push_back(temp);
                temp.clear();
                if(!q.empty())
                   q.push(NULL);
            } else {
                temp.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }    
        }
        return result;     
    }
};
