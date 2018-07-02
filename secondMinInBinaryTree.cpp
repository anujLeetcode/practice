/*
671. Second Minimum Node In a Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Pick One
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.*/

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
    int findMin(TreeNode* root, int& min_val) {
        if(!root) return -1;
        if(root->val != min_val) return root->val;
        int left = findMin(root->left, min_val);
        int right = findMin(root->right, min_val);
        if(left == -1) return right;
        else if(right == -1) return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return findMin(root, root->val);      
    }
};
