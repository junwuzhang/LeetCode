/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.50%)
 * Total Accepted:    158.7K
 * Total Submissions: 488.3K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            while (left < right && nums[left] == nums[left + 1]) left++; // skip duplicates from the left
            while (right > left && nums[right] == nums[right - 1]) right--; // skip duplicates from the right
            int mid = (left + right) / 2;
            // if target happens to be in the middle
            if (nums[mid] == target) return true;
            // if middle number in the array is less than the rightmost number, 
            // sorted array on the right is shorter than sorted array on the right
            if (nums[mid] < nums[right]){
                if (nums[right] >= target && target > nums[mid]){
                    left = mid + 1;
                } else{
                    right = mid - 1;
                }
            } else {
                if (nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};
