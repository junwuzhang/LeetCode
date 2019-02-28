/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.68%)
 * Total Accepted:    304.5K
 * Total Submissions: 876.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> output;
        if (intervals.empty()) return vector<Interval>{};
        // sort the vector of intervals based on starting position
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        for (auto interval : intervals){
            if (output.empty() || output.back().end < interval.start) output.push_back(interval);
            else
                output.back().end = max(output.back().end, interval.end);
        }
        return output;        
    }
};


    // if (ins.empty()) return vector<Interval>{};
    // vector<Interval> res;
    // sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    // res.push_back(ins[0]);
    // for (int i = 1; i < ins.size(); i++) {
    //     if (res.back().end < ins[i].start) res.push_back(ins[i]);
    //     else
    //         res.back().end = max(res.back().end, ins[i].end);
    // }
    // return res;

