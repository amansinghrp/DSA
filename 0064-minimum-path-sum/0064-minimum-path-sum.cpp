class Solution {
private:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i >= m) return 1e7;
        if(j >= n) return 1e7;
        if(i == m-1 && j == n-1){
            return grid[m-1][n-1];
        }

        if(dp[i][j] != -1) return dp[i][j];

        int down = grid[i][j] + solve(i+1, j, m, n, grid, dp);
        int right = grid[i][j] + solve(i, j+1, m, n, grid, dp);

        return dp[i][j] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, grid, dp);
    }
};