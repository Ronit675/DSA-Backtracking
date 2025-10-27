// # Intuition
// First thought is to drive a formula for knight's move and check the next move is 1 greater than the previous or not and if not then return false

// # Approach
// -> If grid[0][0] is not equal to 0 then return false.
// -> call the backtrack function for the starting index.
// -> In backtrack function iterate through every element of the grid.
// -> If the element is at starting index then continue the loop.
// -> Check if |r2 - r1| = 2 AND |c2 - c1| = 1 AND |r2 - r1| = 1 AND |c2 - c1| = 2 AND grid[i][j] == grid[r][c] + 1.
// -> If the condition becomes true then jump to the next element by calling the backtrack function again.
// -> If the element reaches its last index which is equal to the 1 less than grid size then return true else false.

// # Complexity
// - Time complexity:
// O(N^4)

// - Space complexity:
// O(N^2)

// # Code
class Solution {
public:
    bool backtrack(vector<vector<int>>& grid, int r, int c, int n){
        if(n*n - 1 == grid[r][c]){
            return true;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 && j == 0){
                    continue;
                } 
                if(abs(r-i) <= 2 && abs(r-i) != 0 && abs(c-j) <= 2 && abs(c-j) != 0 && grid[i][j] == grid[r][c] + 1){
                    return backtrack(grid, i, j, n);
                }
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0){
            return false;
        }
        int n = grid.size();
        return backtrack(grid, 0, 0, n);
    }
};
