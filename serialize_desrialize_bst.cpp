/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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
class Codec {
      // Encodes a tree to a single string.
    int serializeUtil(TreeNode* root, string& serial) {
        if(!root) {
            serial.append("#");
            serial.append(" ");
            return 1;
        }
        serial.append(to_string(root->val));
        serial.append(" ");
        serializeUtil(root->left, serial);
        serializeUtil(root->right, serial);
        return 1;    
    }
    
      // Decodes your encoded data to tree.
    TreeNode* deserializeUtil(istringstream& iss) {
        string s;
        iss >> s;
        if(s == "#") {
                return NULL;
        } else {
                struct TreeNode* node = new TreeNode(stoi(s));
                node->left = deserializeUtil(iss);
                node->right = deserializeUtil(iss);
                return node;
        }
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial;
        serializeUtil(root, serial);
        return serial;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeUtil(iss);
    }
};
        
