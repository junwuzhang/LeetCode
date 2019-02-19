class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int dp[amount + 1];
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
        return (dp[amount] < amount) ? dp[amount] : -1;
        
    }
};