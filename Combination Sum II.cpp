// # Intuition
// -> To avoid the repetition of the elements we need to sort the elements first.
// -> And in the backtrack function avoid the same previous element.

// # Approach
// -> Same Procedure as Combination I.
// -> Just intially sort the array before calling the backtrack function.
// -> If elements is repeated and its greater than the passed index then move to the next element.
// -> break the loop if candidate is greater than target because no point in moving further for greter elements.
// -> While calling the backtrack function in the loop call for the next reference of the element to avoid.

// # Complexity
// - Time complexity:
// <!-- Add your time complexity here, e.g. $$O(n)$$ -->

// - Space complexity:
// <!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& answer, vector<int>& sum, int target, int i){
        if(target == 0){
            answer.push_back(sum);
            return;
        }
        for(int j = i; j<candidates.size(); j++){
            if(j>i && candidates[j] == candidates[j-1]){
                continue;
            }
            if(target < candidates[j]){
                break;
            }
            sum.push_back(candidates[j]);
            backtrack(candidates, answer, sum, target - candidates[j], j+1);
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> sum;
        backtrack(candidates, answer, sum, target, 0);
        return answer;
    }
};
