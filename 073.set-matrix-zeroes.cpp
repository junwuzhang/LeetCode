/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.85%)
 * Total Accepted:    188.8K
 * Total Submissions: 485.8K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int modified = -INT_MAX;
        // check the first row
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    for (int k=0; k<matrix[i].size(); k++){
                        if (matrix[i][k] != 0){
                            matrix[i][k] = modified;
                        }
                    }
                    for (int k=0; k<matrix.size(); k++){
                        if (matrix[k][j] != 0){
                            matrix[k][j] = modified;
                        }
                    }
                }
            }
        }
        
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == modified) {
                    matrix[i][j] = 0;                    
                }
            }
        }
    }
};
