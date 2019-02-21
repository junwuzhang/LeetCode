/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (53.15%)
 * Total Accepted:    335.8K
 * Total Submissions: 631.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        int end = nums.size();
        int begin = 0;
        permute(output, nums, begin, end);
        return output;
    }

    void permute(vector<vector<int>> &output, vector<int>& nums, int begin, int end){
        if (begin >= end){
            output.push_back(nums);
            cout << "!!pushed back!!" << endl;
            // // debug printing
            // cout << "current nums is: ";
            // for (auto i : nums)
            //     cout << i << " ";
            // cout << endl;
            return;
        }
        for (int i=begin; i<end; i++){
            // debug printing
            cout << "before swap nums is: ";
            for (auto i : nums)
                cout << i << " ";
            cout << endl;
            swap(nums[begin], nums[i]);
            cout << "after swap nums is: ";
            for (auto i : nums)
                cout << i << " ";
            cout << endl;            
            permute(output, nums, begin+1, end);
            cout << "!swapping back!" << endl;
            swap(nums[begin], nums[i]);
        }
    }
};
// key to the question: for loop + backtrack
