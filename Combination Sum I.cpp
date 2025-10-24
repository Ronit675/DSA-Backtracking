// # Intuition
// -> To check for the same element to know how many times that number can fit in the sum and backtrack if the number is not fit and move to the next number.

// # Approach
// -> Declare a 2d and 1d array for storing the answers.
// -> Create and call a backtrack function which initially starts with the first element.
// -> In the backtrack function run a loop that starts from i till the size of the given array.
// -> push the element in the 1d array and call the backtrack function again for the same element with reducing the current element value from the target.
// -> In the backtrack function ensure that the target is not 0 and if it becomes 0 then push the 1d answer array in 2d array and return.
// -> before pushing the element check if the element is smaller then the target or not and if not then continue and check for other given array elements.
// -> Pop the element back if the element is not suitable for the answer or if the answer is found to check for the other elements

// # Complexity
// - Time complexity:
// O(N(T/M+1))

// - Space complexity:
// O(T/M)

// # Code

class Solution {
public:
    // Logic
    void combinationSumAns(vector<vector<int>>& ans, vector<int>& candidates , vector<int>& combi, int target, int i){
        if(target == 0){
            ans.push_back(combi);
            return;
        }
        for(int j = i; j<candidates.size(); j++){
            if(target < candidates[j]){
                continue;
            }
            combi.push_back(candidates[j]);
            combinationSumAns(ans, candidates, combi, target - candidates[j], j);
            combi.pop_back();
        }

    }

    // Declaration only
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        combinationSumAns(ans, candidates, combi, target, 0);
        return ans;
    }
};
