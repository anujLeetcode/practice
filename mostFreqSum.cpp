/*

Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    unordered_map<int, int> sum_map; // sum -> count
    int max_count = 0;
    int findFrequentTreeSumUtil(TreeNode* root) {
        if(!root) return 0;
        int left = findFrequentTreeSumUtil(root->left);
        int right = findFrequentTreeSumUtil(root->right);
        sum_map[root->val + left + right] += 1;
        if(sum_map[root->val + left + right] > max_count) {
            max_count = sum_map[root->val + left + right];
        }
        return root->val + left + right;
        
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
      vector<int>  result;
      findFrequentTreeSumUtil(root);
      for(auto it : sum_map) {
        if(it.second == max_count) {
          result.push_back(it.first);
        } 
      }
      return result;
    }
};
