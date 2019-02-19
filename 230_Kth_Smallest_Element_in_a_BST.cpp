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
    int kthSmallest(TreeNode* root, int k) {
        int output = -INT_MAX;
        vector<int> nodes;
        inorder(root, k, output);
        return output;        
    }

    void inorder(TreeNode* root, int &k, int &output){
        if (!root){
            return;
        }
        inorder(root->left, k, output);
        if(k>0 && (root->val)>output){
            output = root->val;
            k--;
        }
        inorder(root->right, k, output);
    }
};