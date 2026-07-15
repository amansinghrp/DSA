class Solution {
private:
    bool solve(int ind, int &n, string &s, vector<string>& wordDict, unordered_set<string>& st, vector<int> &dp){
        if(ind == n) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i =ind; i<n; i++){
            if(st.find(s.substr(ind, i-ind+1)) != st.end()){
                if(solve(i+1, n, s, wordDict, st, dp)){
                    return dp[i] = 1;
                }
            }
        }

        return dp[ind] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n, -1);
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        return solve(0, n, s, wordDict, st, dp);
    }
};