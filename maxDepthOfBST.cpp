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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        if (ldepth > rdepth)  return ldepth + 1;
        return rdepth + 1;
    }
};
