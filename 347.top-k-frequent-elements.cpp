/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (53.21%)
 * Total Accepted:    175.1K
 * Total Submissions: 328.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> output;
        priority_queue<int, vector<int>, greater<int> > pQueue;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]] += 1;
        }
        for(auto & i : m) {
            pQueue.push(i.second);
            // Size of the min heap is maintained at equal to or below k
            // Therefore pQueue stores a list of occurrence frequencies
            while(pQueue.size() > k) pQueue.pop();
        }
        // constructs the output vector again by comparing hashMap and pq
        for(auto & i : m) {
            if(i.second >= pQueue.top()) output.push_back(i.first);
        }
        return output;   
    }
};

