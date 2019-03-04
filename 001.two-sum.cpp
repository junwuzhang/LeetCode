/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (41.84%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++){
            int currNum = nums[i];
            int complement = target - currNum;
            if (m.find(complement) != m.end()){
                return vector<int>{m[complement], i};
            }
            m[currNum] = i;
        }
        return vector<int>{};
    }
};

    // // BRUTE FORCE
    // vector<int> outputVect;
    // for (int i=0; i<nums.size(); i++) {
    //     for (int j=i+1; j<nums.size(); j++){
    //         if (nums[i] + nums[j] == target) {
    //             outputVect.push_back(i);
    //             outputVect.push_back(j);                   
    //         } 
    //     }
    // }        
    // return outputVect;

