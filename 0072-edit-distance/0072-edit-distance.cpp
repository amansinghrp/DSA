class Solution {
public:
    int minDistance(string w1, string w2) {
        int m = w1.size();
        int n = w2.size();

        //bottom up
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        //base case
        for(int j =0; j<=n; j++){
            dp[0][j] = j;
        }
        for(int i =0; i<= m; i++){
            dp[i][0] = i;
        }

        for(int i =1; i<=m; i++){
            for(int j =1; j<= n; j++){
                if(w1[i-1] == w2[j-1]){
                    //match - dont do anything
                    dp[i][j] = 0+dp[i-1][j-1];
                }
                else{
                    //return minimum of (insert, delete and replace operations)
                    dp[i][j] = min(
                        1+dp[i-1][j],//delete the character at w1
                        min(
                            1 + dp[i-1][j-1], //replaced w1[i] with w2[j]
                            1 + dp[i][j-1] //insert w2[j] in w1 --> w2[j] matched -> move j but i is still pending to be matched
                        )
                    );
                }
            }
        }

        return dp[m][n];
    }
};