// # Intuition
// -> To solve this problem, 2 more functions will be added :- backtrack function and to check if the color assigned to the vertex is safe or not.

// # Approach
// -> Create an adjacency list of the given combination.
// -> Call the backtrack function for the first vertex.
// -> Run a loop for number of colors to be assigned to each of the vertex.
// -> check if the assigned color is safe for the vertex or not using safe function.
// -> if safe then assign the color and check for the next vertex else check for another color.
// -> if any of the backtrack of any vertex returns false then assign 0 and check again.
// -> if all the colors are assigned successfully then return true.

// # Complexity
// - Time complexity:
// <!-- Add your time complexity here, e.g. $$O(n)$$ -->

// - Space complexity:
// <!-- Add your space complexity here, e.g. $$O(n)$$ -->

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
