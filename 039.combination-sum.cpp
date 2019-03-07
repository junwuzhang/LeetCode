/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.62%)
 * Total Accepted:    308.1K
 * Total Submissions: 658.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        }
        // for all cases where target is larger than current element in candidate (target has not been summed up)
        for (int i=begin; i<candidates.size() && target >= candidates[i]; i++){
            combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target-candidates[i], output, combination, i);
            combination.pop_back();
        }
    }
};
