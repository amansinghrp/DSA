class Solution {
private:
    bool canPlace(char num, int row, int col,vector<vector<char>>& board){
        for(int i =0; i<9; i++){
            if(board[i][col] == num) return false;

            if(board[row][i] == num) return false;

            if(board[3 * (row/3) + (i/3)][3*(col/3) + (i%3)] == num) return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i =0; i<9; i++){
            for(int j  =0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int num = '1'; num<='9'; num++){
                        if(canPlace(num, i, j, board)){
                            board[i][j] = num;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};