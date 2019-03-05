/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 *
 * https://leetcode.com/problems/find-the-celebrity/description/
 *
 * algorithms
 * Medium (35.47%)
 * Total Accepted:    75.1K
 * Total Submissions: 211.5K
 * Testcase Example:  '[[1,1,0],[0,1,0],[1,1,1]]'
 *
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among
 * them, there may exist one celebrity. The definition of a celebrity is that
 * all the other n - 1 people know him/her but he/she does not know any of
 * them.
 * 
 * Now you want to find out who the celebrity is or verify that there is not
 * one. The only thing you are allowed to do is to ask questions like: "Hi, A.
 * Do you know B?" to get information of whether A knows B. You need to find
 * out the celebrity (or verify there is not one) by asking as few questions as
 * possible (in the asymptotic sense).
 * 
 * You are given a helper function bool knows(a, b) which tells you whether A
 * knows B. Implement a function int findCelebrity(n). There will be exactly
 * one celebrity if he/she is in the party. Return the celebrity's label if
 * there is a celebrity in the party. If there is no celebrity, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: graph = [
 * [1,1,0],
 * [0,1,0],
 * [1,1,1]
 * ]
 * Output: 1
 * Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] =
 * 1 means person i knows person j, otherwise graph[i][j] = 0 means person i
 * does not know person j. The celebrity is the person labeled as 1 because
 * both 0 and 2 know him but 1 does not know anybody.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: graph = [
 * [1,0,1],
 * [1,1,0],
 * [0,1,1]
 * ]
 * Output: -1
 * Explanation: There is no celebrity.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The directed graph is represented as an adjacency matrix, which is an n x n
 * matrix where a[i][j] = 1 means person i knows person j while a[i][j] = 0
 * means the contrary.
 * Remember that you won't have direct access to the adjacency matrix.
 * 
 * 
 */
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        // for each row in the adjacency matrix (for each candidate in the group)
        for (int i=0; i<n; i++){
            // if A knows B, A must not be candidate, but B might !!THIS IS THE CORE PART OF THE ALGORITHM!!
            if(knows(candidate, i)){
                candidate = i;
            }
        }
        // Check if candidate fits the criteria
        for (int j=0; j<n; j++){
            if (!knows(j, candidate) || knows(candidate, j) && (candidate != j)){
                return -1;
            }
        }
        return candidate;    
    }
};


    // NOT A GOOD SOLUTION
    // // initialize every element in adjacency matrix to zero
    // int matrix[n][n] = {0};
    // int sumOfLastRow = INT_MAX;
    // int sumOfCurrRow = 0;
    // int output = 0;
    // // construct adjacency matrix with bool helper function, celebrity is the row in adjacency matrix with least sum
    // // for each row
    // for (int i=0; i<n; i++){
    //     sumOfCurrRow = 0;
    //     cout << "now checking row number: " << i << endl;
    //     // for each column
    //     for (int j=0; j<n; j++){
    //         // if the current cell is 1
    //         if (knows(i, j)){
    //             // adds it to matrix
    //             matrix[i][j] = 1;
    //             // adds one to sum of current row
    //             sumOfCurrRow += 1;
    //             cout << "sumOfCurrRow is now: " << sumOfCurrRow << endl;
    //         }
    //     }
    //     // if sum of current row is less than sum of last row
    //     if (sumOfCurrRow < sumOfLastRow){
    //         cout << "sumOfCurrRow is less than sumOfLastRow" << endl;
    //         // update output
    //         output = i;
    //         cout << "output updated with current row #, which is: " << output << endl;
    //         // set last row to be current "least sum row" for comparison
    //         sumOfLastRow = sumOfCurrRow;
    //         cout << "sumOfLastRow is now: " << sumOfLastRow << endl;
    //     } else if (sumOfCurrRow == sumOfLastRow){
    //         output = -1;
    //     }
    // }
    // return output;

