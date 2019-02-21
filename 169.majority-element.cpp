/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.34%)
 * Total Accepted:    344.9K
 * Total Submissions: 671.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // std::map<int,int> numCount;
        // int size = nums.size();
        // for (int i=0; i<size; i++){
        //     int currNum = nums[i];
        //     if (!numCount.count(currNum)){
        //         numCount.insert(pair<int, int>(currNum, 1));
        //     } else numCount[currNum] += 1;            
        //     if (numCount[currNum] > (size/2)){
        //         return currNum;
        //     }
        // }
        // return 0;       
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
