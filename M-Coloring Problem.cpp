class Solution {
  public:
    
    bool isSafe(vector<int> &color, vector<vector<int>> adjL, int i, int cc){
        for(int neighbour: adjL[cc]){
            if(color[neighbour] == i){
                return false;
            }
        }
        return true;
    }
  
    bool backtrack(int v, int m, int cc, vector<int> &color, vector<vector<int>> adjL){
        if(cc == v){
            return true;
        }
        for(int i = 1; i<=m; i++){
            if(isSafe(color, adjL, i, cc)){
                color[cc] = i;
                if(backtrack(v, m, cc+1, color, adjL)){
                    return true;
                }
                color[v] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        
        // code here
        vector<vector<int>> adjL(v);
        for(auto it : edges){
            adjL[it[0]].push_back(it[1]);
            adjL[it[1]].push_back(it[0]);
        }
        vector<int> color(v,0);
        if(backtrack(v, m, 0, color, adjL)){
            return true;
        };
        return false;
    }
};
