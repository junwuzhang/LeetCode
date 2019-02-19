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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        inorder(root, output);
        return output;
    }
    
    void inorder(TreeNode* root, vector<int>& output) {
        if (!root) {
            return;
        }
        inorder(root->left, output);
        output.push_back(root->val);
        inorder(root->right, output);
    }  
};