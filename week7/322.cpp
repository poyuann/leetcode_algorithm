class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            // set a value that is guaranteed to bigger than the possible answer
            // the smallest possible coin value is 1, so there may not be anwer that has to have amount+1 coins to build up the amount
            int ub = amount + 1;
            // record the smallest coins to get the each amount
            vector<int> dp(ub , ub);
            // sort the coins so we could consider less cases
            sort(coins.begin(), coins.end());
            // start from 0 coins
            dp[0] = 0;
            // compute each amount coin numbers from 0
            for (int i = 1; i <= amount; ++i) {
                // consider the last coin as each coins value
                for (int j = 0; j < coins.size(); ++j) {
                    // ensure dp[i - coins[j]] is valid
                    if (i-coins[j]<0) {
                        continue;
                    }
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
            
            return dp[amount]!=ub?dp[amount]:-1;
        }
    };