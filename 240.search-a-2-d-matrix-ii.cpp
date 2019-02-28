/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (40.16%)
 * Total Accepted:    160.3K
 * Total Submissions: 398.5K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from top right because when currNum < target, we can go down, otherwise we must go left
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = 0, j = n - 1, currNum = 0;
        while (i<matrix.size() && j>=0){
            currNum = matrix[i][j];
            if (currNum > target){
                j--;
            } else if (currNum < target){
                i++;
            } else{
                return true;
            }
        }
        return false;
    }
};
    // // BRUTE FORCE:
    // for (int i=0; i<matrix.size(); i++){
    //     for (int j=0; j<matrix[i].size(); j++){
    //         if (matrix[i][j] == target) return true;
    //     }
    // }
    // return false;

    // // Recursion:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     // start from top right because when currNum < target, we can go down, otherwise we must go left
    //     int m = matrix.size();
    //     if (m == 0) return false;
    //     int n = matrix[0].size();
    //     if (n == 0) return false;
    //     int startingRowIdx = 0, startingColIdx = matrix[0].size() - 1;
    //     return searchMatrixHelper(matrix, target, startingRowIdx, startingColIdx);
    // }

    // bool searchMatrixHelper(vector<vector<int>>& matrix, int target, int currRowIdx, int currColIdx){
    //     int currNum = matrix[currRowIdx][currColIdx];
    //     if (currNum == target){
    //         cout << "true!" << endl;
    //         return true;
    //     }
    //     else {
    //         if (currNum < target){
    //             if (currRowIdx+1 < matrix.size()) {
    //                 // cout << "currNum < target, move down one row" << endl;
    //                 return searchMatrixHelper(matrix, target, currRowIdx+1, currColIdx);
    //             }
    //             else {
    //                 // cout << "currNum < target, move down out of row limit, return false" << endl;
    //                 return false;
    //             }
    //         } else if (currNum > target) {
    //             if (currColIdx-1 >= 0) {
    //                 // cout << "currNum > target, move left one column" << endl;
    //                 return searchMatrixHelper(matrix, target, currRowIdx, currColIdx-1);
    //             }
    //             else {
    //                 // cout << "currNum > target, move left out of column limit, return false" << endl;
    //                 return false;
    //             }
    //         }            
    //     }
    //     return false;
    // }

