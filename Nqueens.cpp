// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->

// # Approach
// <!-- Describe your approach to solving the problem. -->

// # Complexity
// - Time complexity:
// <!-- Add your time complexity here, e.g. $$O(n)$$ -->

// - Space complexity:
// <!-- Add your space complexity here, e.g. $$O(n)$$ -->

// # Code
// ```cpp []
class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n){
        for(int i = 0; i<n; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void nQueen(vector<vector<string>> &ans, vector<string> &board, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(board, row, i, n)){
                board[row][i] = 'Q';
                nQueen(ans, board, row+1, n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueen(ans, board, 0, n);
        return ans;
    }
};
