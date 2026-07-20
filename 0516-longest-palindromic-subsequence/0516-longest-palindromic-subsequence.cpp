class Solution {
private:
    int LCS(string &t1, string &t2){
        int m = t1.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1, -1));

        //basse case reflecting end of either strings
        for(int i =0; i<=m; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i =1; i<=m; i++){
            for(int j =1; j<=m; j++){
                if(t1[i-1] == t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return LCS(s, t);
    }
};