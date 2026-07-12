class Solution {
private:
     vector<int> leftRow,upperDia, lowerDia;

    bool canPlace(int row, int col, int n, vector<string> &board){
        if(leftRow[row]) return false;

        if(upperDia[(n-1)+(col-row)]) return false;

        if(lowerDia[row+col]) return false;

        return true;
    }
    void solve(int col, int n, vector<string> &board ,vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(canPlace(i, col, n, board)){
                board[i][col] = 'Q';
                leftRow[i] = 1;
                upperDia[(n-1)+(col-i)] = 1;
                lowerDia[i+col] = 1;
                solve(col+1, n, board, ans);
                board[i][col] = '.';
                leftRow[i] = 0;
                upperDia[(n-1)+(col-i)] = 0;
                lowerDia[i+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n, '.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        leftRow.resize(n, 0);
        upperDia.resize(2*n-1, 0);
        lowerDia.resize(2*n-1, 0);
        solve(0, n, board, ans);
        return ans;
    }
};