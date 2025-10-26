// # Intuition
// -> First thought is to divide the string and check if the string is valid palindrome or not.
// -> if the left part is palindrome then check for right and repeat the division step else backtrack.

// # Approach
// -> 

// # Complexity
// - Time complexity:
// -> O(N^2N)

// - Space complexity:
// -> O(N)

// # Code
class Solution {
public:
    bool isvalid(string part){
        int i = 0; 
        int j = part.size()-1;
        while(i<=j){
            if(part[i] != part[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string s, vector<vector<string>>& ans, vector<string>& partition){
        if(s.size() == 0){
            ans.push_back(partition);
        }
        for(int i = 0; i<s.size(); i++){
            string part = s.substr(0,i+1);
            if(isvalid(part)){
                partition.push_back(part);
                backtrack(s.substr(i+1), ans, partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        backtrack(s, ans, partition);
        return ans;
   }
};
```
