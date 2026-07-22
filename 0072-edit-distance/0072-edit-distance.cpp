class Solution {
private:
    int solve(int i, int j, string &w1, string &w2,  vector<vector<int>>&dp){
        if(i < 0){
            //w1 finished, empty --> nonempty
            return j+1;//insert all remaining
        }
        if(j < 0){
            //w2 finished --> nonempty --> empty
            return i+1;//delete all remining 
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i] == w2[j]){
            //match - dont do anything
            return dp[i][j] = 0+solve(i-1, j-1, w1, w2, dp);
        }
        else{
            //return minimum of (insert, delete and replace operations)
            return dp[i][j] = min(
                1+solve(i-1, j, w1, w2, dp),//delete the character at w1
                min(
                    1 + solve(i-1, j-1, w1, w2, dp), //replaced w1[i] with w2[j]
                    1 + solve(i, j-1, w1, w2, dp) //insert w2[j] in w1 --> w2[j] matched -> move j but i is still pending to be matched
                )
            );
        }
    }
public:
    int minDistance(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, w1, w2, dp);
    }
};