/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (39.24%)
 * Total Accepted:    198.4K
 * Total Submissions: 505.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        if (preStart >= preEnd || inStart >= inEnd){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        int dis = find(inorder.begin()+inStart, inorder.begin()+inEnd, preorder[preStart]) - inorder.begin() - inStart;
        root->left  = buildTreeHelper(preorder, preStart+1,     preStart+1+dis, inorder, inStart,     inStart+dis);
        root->right = buildTreeHelper(preorder, preStart+1+dis, preEnd,         inorder, inStart+dis+1, inEnd      );
        return root;
    }
};
