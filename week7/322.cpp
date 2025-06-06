class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int ub = amount + 1;
            vector<int> dp(ub , ub);
            sort(coins.begin(), coins.end());
            dp[0] = 0;
            for (int i = 1; i <= amount; ++i) {
                for (int j = 0; j < coins.size(); ++j) {
                    if (i-coins[j]<0) {
                        continue;
                    }
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
            
            return dp[amount]!=ub?dp[amount]:-1;
        }
    };