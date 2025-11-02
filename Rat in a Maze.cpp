// # Intuition
// -> First thought is what variables and vectors are required to solve this question
// -> vector to store string for answers, visited array to mark visited cell, a string to strore answer.

// # Approach
// -> call the backtrack function for 1st index and pass an empty string.
// -> declare direction array and mark the cell visited.
// -> run a loop for all 4 directions.
// -> Check for the direciton wether visited or not, maze value is 1 or not, and also check the boundries.
// -> if all conditions are satisfied then add the direction in string and call the backtrack function.
// -> pop_back the string to allow other direction to be added for another answer.
// -> mark visited = 0 for the cell when done iterating. To allow other paths to check.

// # Complexity
// - Time complexity:
// O(4^N^2)

// - Space complexity:
// O(N^2 + L*M)

class Solution {
  public:
  
    void backtrack(vector<vector<int>>& maze, string s, vector<vector<int>>& vis, int r, int c, vector<string>& ans){
        int n= maze.size();
        if(r == n-1 && c == n-1){
            ans.push_back(s);
            return;
        }
        int dirx[] = {1,0,0,-1};
        int diry[] = {0,-1,1,0};
        
        vis[r][c] = 1;
        for(int i = 0; i<4; i++){
            int x = dirx[i] + r;
            int y = diry[i] + c;
            if(x>=0 && y>=0 && x<n && y<n && !vis[x][y] && maze[x][y]){
                if(dirx[i] == 0 && diry[i] == 1){
                    s = s+'R';
                }
                else if(dirx[i] == 1 && diry[i] == 0){
                    s = s+'D';
                }
                else if(dirx[i] == 0 && diry[i] == -1){
                    s = s+'L';
                }
                else{
                    s = s+'U';
                }
                backtrack(maze, s, vis, x, y, ans);
                s.pop_back();
            }
        }
        vis[r][c] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        backtrack(maze,"", vis, 0, 0, ans);
        return ans;
    }
};
