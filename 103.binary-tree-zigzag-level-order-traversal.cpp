/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (40.27%)
 * Total Accepted:    193.4K
 * Total Submissions: 480K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > output;
        if (root == NULL) return output;
        else{
            zigzagHelper(root, 0, output);
        }
        return output;
    }

    void zigzagHelper(TreeNode* &root, int level, vector<vector<int> > &output){
        if (!root) return;
        vector<int> singleVec;
        // if first element of the level
        if (output.size() <= level){
            singleVec.push_back(root->val);
            output.push_back(singleVec);
        } else{
            // if this is an odd level (1, 3, 5, 7...), traverse from left to right
            if (level % 2 != 0){
                output[level].insert(output[level].begin(), root->val);
            } else if (level % 2 == 0){
                output[level].push_back(root->val);
            }
        }
        zigzagHelper(root->left,  level+1, output);
        zigzagHelper(root->right, level+1, output);
    }
};
