/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (38.95%)
 * Total Accepted:    121.9K
 * Total Submissions: 312.8K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while (left < right){
            // skip duplicates from left and right
            // while (left < right && nums[left] == nums[left+1]) left++;
            // while (right > left && nums[right] == nums[right-1]) right--;
            if (nums[left]<nums[right]) break;
            mid = left + (right-left) /2;
            if (nums[right] < nums[mid]){
                left = mid + 1;
            } else if (nums[right] == nums[mid]) {
                left++;
                right--;
            } else{
                right = mid;
            }
        }
        return nums[left];
    }
};

