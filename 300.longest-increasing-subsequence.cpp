/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.13%)
 * Total Accepted:    193.6K
 * Total Submissions: 482.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    // Super elegant solution from Discussions. BEAUTIFUL!
    int lengthOfLIS(vector<int>& nums) {
        vector<int> output;
        for (int i=0; i<nums.size(); i++){
            auto it = lower_bound(output.begin(), output.end(), nums[i]);
            if (it == output.end()) output.push_back(nums[i]);
            else *it = nums[i];
        }
        return output.size();
    }
};



// class Solution {
// public:
//     // There's a typical DP solution with O(N^2) Time and O(N) space 
//     // DP[i] means the result ends at i
//     // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
//     int lengthOfLIS(vector<int>& nums) {
//         int size = nums.size();
//         if (size == 0) return 0;
//         vector<int> dp(size, 1);
//         int output = 1;
//         // iterate the ith element of the array
//         for (int i=1; i<size; i++){
//             // iterate j, which includes the elements before the ith element of the array
//             for (int j=0; j<i; j++){
//                 if (nums[i] > nums[j]){
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
//             output = max(output, dp[i]);
//         }
//         return output;
        
//     }
// };

