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
   bool isLeaf(TreeNode* root) {
       if(!root) return false;
       else return (root->left == NULL && root->right == NULL);
   }
    
   void leftBoundary(TreeNode* root, vector<int> &result) {
     if(!root) return;
     if(isLeaf(root)) return;
     result.push_back(root->val);
     if (root->left) {
       leftBoundary(root->left, result);
     } else {
       leftBoundary(root->right, result);
     }
     return;  
   }
    
   void rightBoundary(TreeNode* root, vector<int> &result) {
     if(!root) return;
     if(isLeaf(root)) return;
     if (root->right) {
       rightBoundary(root->right, result);
     } else {     
       rightBoundary(root->left, result);
     }
     result.push_back(root->val);
     return;  
   }
    
     void addLeafNodes(TreeNode* root, vector<int> &result) {
     if(!root) return;
     if(isLeaf(root)) {
         result.push_back(root->val);
         return;
     }
     addLeafNodes(root->left, result);
     addLeafNodes(root->right, result);
     return;  
   }
    
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
      vector<int> result;
      if(!root)return result;
      result.push_back(root->val);
      leftBoundary(root->left, result);
      addLeafNodes(root->left, result);
      addLeafNodes(root->right, result);
      rightBoundary(root->right, result);
      
      return result;
    }
};
