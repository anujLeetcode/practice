/*
617. Merge Two Binary Trees
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTreesUtil(TreeNode* root, TreeNode* t1, TreeNode* t2) {
        
        if(t1 && t2) {
          root = new TreeNode(t1->val + t2->val);
          root->left = mergeTreesUtil(root->left, t1->left, t2->left);
          root->right = mergeTreesUtil(root->right, t1->right, t2->right);
        } else if(t1 && !t2) {
          root = new TreeNode(t1->val);
          root->left = mergeTreesUtil(root->left, t1->left, NULL);
          root->right = mergeTreesUtil(root->left, t1->right, NULL); 
        } else if(t2 && !t1){
          root = new TreeNode(t2->val); 
          root->left = mergeTreesUtil(root->left, NULL, t2->left);
          root->right = mergeTreesUtil(root->right, NULL, t2->right);
        } else {
            return NULL;
        }
        
        return root;
        
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = NULL;
        return mergeTreesUtil(root, t1, t2);
        
    }
};
