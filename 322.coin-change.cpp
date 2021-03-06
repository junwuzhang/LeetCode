/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (28.94%)
 * Total Accepted:    161.1K
 * Total Submissions: 556.9K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int i=1; i<=amount; i++){
            for (int j=0; j<coins.size(); j++){
                // if current coin cannot make up the entire amount
                if (coins[j] <= i){
                    /* the number of coins dp[i] needed for amount i is the min of current 
                     * number of coins needed dp[i] and number needed for total amount minus 
                     * value of current coin j plus 1 (because we just used coin j once)
                     */
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);                    
                }                
            }
        }
        return (dp[amount] <= amount) ? dp[amount] : -1;        
    }
};
