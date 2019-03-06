/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (41.83%)
 * Total Accepted:    258.9K
 * Total Submissions: 617.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0, currBarIdx = 0;
        stack<int> st;
        while(currBarIdx < height.size()){
            while(!st.empty() && height[currBarIdx] > height[st.top()]){
                int topOfStack = st.top();
                st.pop();
                if (st.empty()) break;
                int numOfBars = currBarIdx - st.top() - 1;
                int boundedHeight = min(height[currBarIdx], height[st.top()]) - height[topOfStack];
                totalWater += numOfBars * boundedHeight;
            }
            st.push(currBarIdx++);
        }
        return totalWater;
    }
};

