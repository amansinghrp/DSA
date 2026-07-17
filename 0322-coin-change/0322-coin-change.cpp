class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        for(int j = 0; j<= amount; j++){
            dp[n][j] = 1e9;
        }
        for(int ind = n-1; ind>=0; ind--){
            for(int amt = 1; amt <= amount; amt++){
                int notTake = 0+dp[ind+1][amt];
                int take = 1e9;
                if(coins[ind] <= amt){
                    take = 1+dp[ind][amt-coins[ind]];
                }
                dp[ind][amt]= min(take, notTake);
            }
        }
        int ans = dp[0][amount];
        if(ans == 1e9){
            return -1;
        } 
        return ans;
    }
};