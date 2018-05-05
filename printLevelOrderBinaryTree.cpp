class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        vector<int> temp;
        vector<vector<int>> result;
        queue<TreeNode*> q;
         if(!root) return result;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                result.push_back(temp);
                temp.clear();
                if(!q.empty()) {
                  q.push(NULL);
                }
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
