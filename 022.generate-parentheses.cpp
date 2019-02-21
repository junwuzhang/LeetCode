/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (52.92%)
 * Total Accepted:    297.8K
 * Total Submissions: 562.5K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        backtrack(output, "", n, 0);
        return output;
    }

    void backtrack(vector<string> &output, string str, int l, int r){
        // if no more left or right parenthesis to add
        if (l == 0 && r == 0){
            // cout << "current string: " << str << endl;
            output.push_back(str);
        }
        // if there are still more left parenthesis to add
        if (l > 0){
            // cout << "l, r: " << l << ", "<< r << endl;
            // cout << "added left parenthesis: " << str+'(' << endl;
            backtrack(output, str+'(', l-1, r+1);
        }
        // if there are still more right parenthesis to add
        if (r > 0){
            // cout << "l, r: " << l << ", "<< r << endl;
            // cout << "added right parenthesis: " << str+')' << endl;
            backtrack(output, str+')', l, r-1);
        }
    }
};


