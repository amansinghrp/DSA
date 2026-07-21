class Solution {
private:
    int LIS(int ind, int &n, int last, vector<int> &nums){
        if(ind >= n){
            return 0;
        }
        int notTake = 0;
        notTake =  0 + LIS(ind+1, n, last, nums);
        int take = 0;
        if(last == -1 || nums[ind] > nums[last]){
            take = 1 + LIS(ind+1, n, ind, nums);
        }
        return max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i =0; i<=n; i++){
            dp[n][i] = 0;
        }

        for(int ind = n-1; ind>= 0; ind--){
            for(int last = ind-1; last>=-1; last--){
                int notTake = 0;
                notTake =  0 + dp[ind+1][last+1];
                int take = 0;
                if(last == -1 || nums[ind] > nums[last]){
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][last+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};