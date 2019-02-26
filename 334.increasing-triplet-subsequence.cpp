/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.41%)
 * Total Accepted:    84K
 * Total Submissions: 213.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> newVec;
        // add the first number to a new vector
        newVec.push_back(nums[0]);
        // iterate through nums
        for (int i=0; i<nums.size(); i++){
            // if current number is larger than last number in new vector
            if (nums[i] > newVec.back()){
                // append number to new vector
                newVec.push_back(nums[i]);
            } 
            // if current number is smaller than last number in new vector
            if (nums[i] < newVec.back()){
                if (nums[i] > newVec[0]){
                    newVec[newVec.size()-1] = nums[i];
                } else if (newVec.size() == 1){
                    newVec.clear();
                    newVec.push_back(nums[i]);
                } else{
                    vector<int> numsToSort = nums;
                    // if newVec.size()=2, sort remaining nums to determine whether to replace the newVec or not
                    sort(numsToSort.begin()+i, numsToSort.end());
                    if (numsToSort.back() < newVec.back()){
                        newVec.clear();
                        newVec.push_back(nums[i]);
                    }
                }
            }
            if (newVec.size()>=3){
                break;
            }
        }
        // after iterating, check size of new number
        if (newVec.size() >= 3){
            return true;
        } else {
            return false;
        }
    }
};
