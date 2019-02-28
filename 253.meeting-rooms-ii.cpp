/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 *
 * https://leetcode.com/problems/meeting-rooms-ii/description/
 *
 * algorithms
 * Medium (42.13%)
 * Total Accepted:    128K
 * Total Submissions: 303.9K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 * required.
 * 
 * Example 1:
 * 
 * 
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * 
 * Example 2:
 * 
 * 
 * Input: [[7,10],[2,4]]
 * Output: 1
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
    int minMeetingRooms(vector<Interval>& intervals) {
        /* 1. Sort the given meetings by their start time.
            2. Initialize a new min-heap and add the first meeting's ending time to the heap. 
                We simply need to keep track of the ending times as that tells us when a meeting room will get free.
            3. For every meeting room check if the minimum element of the heap i.e. the room at the top of the heap is free or not.
            4. If the room is free, then we extract the topmost element and add it back with the ending time of the current meeting 
                we are processing.
            5. If not, then we allocate a new room and add it to the heap.
            6. After processing all the meetings, the size of the heap will tell us the number of rooms allocated. This will be the 
                minimum number of rooms needed to accommodate all the meetings. */

        int output = 1;
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto interval : intervals){
            // if the ending time of the room with the earliest starting time is earlier than starting time of current room:
                // pop that room from the heap to make the room available
            if(!minHeap.empty() && minHeap.top() <= interval.start) minHeap.pop();
            // if the room with the earliest starting time is not free, append the ending time of the current room to the min heap
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};

