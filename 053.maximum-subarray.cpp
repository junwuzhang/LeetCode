/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.75%)
 * Total Accepted:    468.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int output = nums[0], currSum = 0;
        for (int i = 0; i<size; i++){
            currSum += nums[i];
            // cout << "currSum += nums[i] is: " << currSum << endl;
            output = max(currSum, output);
            // cout << "output = max(currSum, output) is: " << output << endl;
            // resets currSum if currSum dips below zero
            currSum = max(currSum, 0);
            // cout << "currSum = max(currSum, 0) is: " << currSum << endl;
        }
        return output;
    }
};

