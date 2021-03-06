/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 *
 * https://leetcode.com/problems/flatten-2d-vector/description/
 *
 * algorithms
 * Medium (43.34%)
 * Total Accepted:    52.6K
 * Total Submissions: 121.4K
 * Testcase Example:  '["Vector2D","next","next","next","hasNext","hasNext","next","hasNext"]\n[[[[1,2],[3],[4]]],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * Design and implement an iterator to flatten a 2d vector. It should support
 * the following operations: next and hasNext.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
 * 
 * iterator.next(); // return 1
 * iterator.next(); // return 2
 * iterator.next(); // return 3
 * iterator.hasNext(); // return true
 * iterator.hasNext(); // return true
 * iterator.next(); // return 4
 * iterator.hasNext(); // return false
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * Please remember to RESET your class variables declared in Vector2D, as
 * static/class variables are persisted across multiple test cases. Please see
 * here for more details.
 * You may assume that next() call will always be valid, that is, there will be
 * at least a next element in the 2d vector when next() is called.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * As an added challenge, try to code it using only iterators in C++ or
 * iterators in Java.
 * 
 */
class Vector2D {
    // iterator solution
private:
    vector<vector<int>> data;
    vector<vector<int>>::iterator i, end;
    int colPos = 0;
public:
    Vector2D(vector<vector<int>> v) {
        data = v;
        i = data.begin();
        end = data.end();
    }
    
    int next() {
        hasNext();
        return (*i)[colPos++];
    }
    
    bool hasNext() {
        // while hasn't finished iterating the entire 2D vector but have finished iterating one row
        while(i != end && colPos == (*i).size()){
            // move to the next row
            i++;
            // reset column position to 0
            colPos = 0;
        }
        return i != end;
    }
};

// // Naive 2D to 1D solution:
// class Vector2D {
//     queue<int> q;

// public:
//     Vector2D(vector<vector<int>> v) {
//         for (vector<int> vec : v){
//             for (int i : vec){
//                 q.push(i);
//             }
//         }
//     }
    
//     int next() {
//         int nextNum = q.front();
//         q.pop();
//         return nextNum;
//     }
    
//     bool hasNext() {
//         return !q.empty();
//     }
// };

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

