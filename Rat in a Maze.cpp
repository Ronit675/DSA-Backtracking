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
