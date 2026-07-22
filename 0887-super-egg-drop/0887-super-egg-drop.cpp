class Solution {
public:
    int solve(int eggs, int floor, vector<vector<int>>&dp){
        //k      n
        if(floor == 0) return 0;
        if(floor == 1) return 1;
        if(eggs == 1) return floor;
        if(dp[eggs][floor] != -1) return dp[eggs][floor];
        int ans = 1000000;
        for(int i = 1; i<= floor; i++){
            int below = solve(eggs-1, i-1, dp); //move below when egg broke, check for lower floors
            int above = solve(eggs, floor-i, dp); //move above if egg didnt break, check for above remining floors
            int moves = 1 + max(below, above);//take the worst possible case of each flooor
            ans = min(ans, moves); //take the best out of those worst cases
        }
        return dp[eggs][floor] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1, vector<int>(n+1, 0));
        for(int floor = 1; floor<= n; floor++){
            dp[1][floor] = floor;
            dp[0][floor] = 0;
        }
        for(int eggs = 0; eggs<=k; eggs++){
            dp[eggs][0] = 0;
            dp[eggs][1] = 1;
        }

        for(int eggs=2; eggs<=k; eggs++){
            for(int floor = 2; floor<=n; floor++){
                int ans = 1000000;
                int low = 1, high = floor, mid;
                while(low <= high){
                    mid = low + (high-low)/2;
                    int below = dp[eggs-1][mid-1]; //move below when egg broke, check for lower floors
                    int above = dp[eggs][floor-mid]; //move above if egg didnt break, check for above remining floors
                    int moves = 1 + max(below, above);//take the worst possible case of each flooor
                    ans = min(ans, moves); //take the best out of those worst cases

                    if(below < above){
                        //above is more than below and we need more in worst case so
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }
                dp[eggs][floor] = ans;
            }
        }
        return dp[k][n];
    }
};