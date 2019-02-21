/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (44.18%)
 * Total Accepted:    70.8K
 * Total Submissions: 160.3K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks. Tasks
 * could be done without original order. Each task could be done in one
 * interval. For each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // use the idea of filling to keep track of maximum # of iterations
        unordered_map<char, int> m;
        int count = 0, output = 0;
        int size = tasks.size();
        // count frequency of each tasks
        for (auto i : tasks) {
            m[i]++;
            count = max(count, m[i]);
        }
        // least number of occurances if tasks.size() != 0 
        // by taking any task and expand to satisfy idle requirements
        // count - 1 to account for the case before the last idle
        // for items after the last idle, add them in the following iteration operation
        output = (count - 1) * (n + 1);
        
        for (auto task : m){
            if (task.second == count) output++;            
        }
        
        return max(int(tasks.size()), output);
    }
};
