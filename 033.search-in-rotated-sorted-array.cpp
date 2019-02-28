/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.60%)
 * Total Accepted:    368.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find index of smallest number (find pivot index)
        // binary search to find target index
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left + right) / 2;
            // if target happens to be in the middle
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]){
                if (nums[right]>=target && target >= nums[mid]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }

            } else {
                if (nums[left]<=target && target <= nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
