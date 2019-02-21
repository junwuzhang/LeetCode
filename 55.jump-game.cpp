/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (31.20%)
 * Total Accepted:    233.6K
 * Total Submissions: 748.3K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return false;
        vector<int> dp(size, 0);
        int reach = 0;
        // maximum reach at every index equals to its maximum reach plus the sum of reach of its previous items
        // dp[i] indicates the max of (its own reach + sum of previous reach, previous reach)
        for (int i=0; i<size; i++){
            if (reach < i) return false;
            reach = max(nums[i]+i, reach);
        }
        return true;
    }    
};

