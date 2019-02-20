/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.26%)
 * Total Accepted:    476.8K
 * Total Submissions: 2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a=0, b=0, c=0;
        int start=0, end=0;
        int n = nums.size();
        
        set<vector<int>> outputSet;
        
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++){
            a = nums[i];
            start = i+1;
            end = n-1;
            while (start < end){
                b = nums[start];
                c = nums[end];
                if (a + b + c == 0){
                    vector<int> singleVec;
                    singleVec.push_back(c);
                    singleVec.push_back(b);
                    singleVec.push_back(a);
                    outputSet.insert(singleVec);
                    start = start + 1;
                    end = end - 1;
                }
                else if (a+b+c > 0){
                    end = end - 1;
                } else {
                    start = start + 1;
                }
            }          
        } 

        vector<vector<int>> output(outputSet.begin(), outputSet.end());
        return output; 
    }
};
