/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.90%)
 * Total Accepted:    264.4K
 * Total Submissions: 803.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
        int start, end;
    vector<int> searchRange(vector<int>& nums, int target) {
        int midPt, left, right;
        // find left index
        initialize(nums);
        while(start < end){
            midPt = (start + end) / 2;
            if (nums[midPt] >= target) end = midPt;
            else start = midPt + 1;
        }
        left = start;
        // find right index
        initialize(nums);
        while(start < end){
            midPt = (start + end) / 2;
            if (nums[midPt] > target) end = midPt;
            else start = midPt + 1;
        }
        right = start;
        // return stuff
        return left == right? vector<int> {-1, -1} : vector<int> {left, right - 1};
        
    }
private:
    void initialize(vector<int>& nums){
        start = 0;
        end = nums.size();
    }
};
