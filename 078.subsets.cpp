/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.70%)
 * Total Accepted:    326.7K
 * Total Submissions: 644K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> subVec;
        backtrack(nums, output, subVec, 0);
        return output;
    }

    void backtrack(vector<int>& nums, vector<vector<int>> &output, vector<int> &subVec, int start) {
        output.push_back(subVec);
        for (int i=start; i<nums.size(); i++){
            subVec.push_back(nums[i]);
            backtrack(nums, output, subVec, i+1);
            subVec.pop_back();
        }
    }
};
