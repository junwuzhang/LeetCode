/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.09%)
 * Total Accepted:    202.4K
 * Total Submissions: 503K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // use recursion backtracking, recursively find how many combinations are possible
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > output;
        vector<int> combination;
        combinationSumHelper(candidates, target, output, combination, 0);
        return output;
    }
private:
    void combinationSumHelper(vector<int>& candidates, int target, vector<vector<int> > &output, vector<int> &combination, int begin) {
        // if target is NULL/zero, means reached the base case of recursion, add current combination to output
        if (!target){
            output.push_back(combination);
            return;
        }
        // for all cases where target is larger than current element in candidate (target has not been summed up)
        for (int i=begin; i != candidates.size() && target >= candidates[i]; i++){
            // only when i starts from begin or candidate is different from last candidate (to avoid reuse)
            if (i == begin || candidates[i] != candidates[i - 1]){
                combination.push_back(candidates[i]);
                // i+1 because of comparison between i and i-1
                combinationSumHelper(candidates, target-candidates[i], output, combination, i+1);
                combination.pop_back();
            }
        }
    }
};

