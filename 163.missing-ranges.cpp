/*
 * @lc app=leetcode id=163 lang=cpp
 *
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (22.93%)
 * Total Accepted:    51.4K
 * Total Submissions: 224.1K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * 
 * 
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 * 
 * 
 */
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> output;  
        if(nums.empty()) {helper(output, lower, upper, 0, 0); return output;}  //if nums empty
        
        helper(output, lower, nums.front(), 0, 1);  //lower to nums.front()
        for(int i = 0; i < nums.size() - 1; i++) {
            helper(output, nums[i], nums[i+1], 1, 1);  //between each pair of numbers in nums
        }
        helper(output, nums.back(), upper, 1, 0); //nums.back() to upper
        
        return output;
    }
    
    void helper(vector<string> &output, int left, int right, int l, int r) // compare left and right, l (r) == 1 means left (right) is within the range
    {
        long d = (long)right - left;  //avoid overflow: INT_MAX - INT_MIN; 0 - INT_MIN; INT_MAX - (-1); etc.
        if(d == l + r) output.push_back(to_string(left + l));
        else if(d > l + r) output.push_back(to_string(left + l) + "->" + to_string(right - r));
    }
};


