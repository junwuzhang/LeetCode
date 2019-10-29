/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
public:
    double knightProbability(int N, int K, int r, int c) {
        // base case: if it reaches K moves, return the probability
        // stored in dp matrix
        if (dp.count(r) && dp[r].count(c) && dp[r][c].count(K)) {
            return dp[r][c][K];
        }
        if (r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if (K == 0) return 1;
        // from current position, recursively check probability in all directions
        double total = knightProbability(N, K - 1, r + 2, c + 1)
                    + knightProbability(N, K - 1, r + 1, c + 2)
                    + knightProbability(N, K - 1, r - 1, c + 2)
                    + knightProbability(N, K - 1, r - 2, c + 1)
                    + knightProbability(N, K - 1, r - 2, c - 1)
                    + knightProbability(N, K - 1, r - 1, c - 2)
                    + knightProbability(N, K - 1, r + 1, c - 2)
                    + knightProbability(N, K - 1, r + 2, c - 1);
        // prob is # of cases that stays in board divided by total
        // # of cases (8)
        double result  = total / 8;
        // fill in corresponding dp matrix
        dp[r][c][K] = result;
        return result;
    }
};
// @lc code=end

