/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (45.94%)
 * Total Accepted:    186.8K
 * Total Submissions: 405.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // use DFS recursion backtracking
        vector<vector<int>> output;
        if (n<k) return output;
        vector<int> combination(0, k);
        combineDFS(output, combination, 0, 0, n, k);
        return output;
    }

private:
    void combineDFS(vector<vector<int>> &output, vector<int> &combination, int start, int num, int n, int k) {
        if (num == k){
            output.push_back(combination);
            return;
        }
        for (int i=start; i<n; i++){
            combination.push_back(i+1);
            combineDFS(output, combination, i+1, num+1, n, k);
            combination.pop_back();
        }
    }
};

