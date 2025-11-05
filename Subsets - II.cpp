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
    void Ps(vector<vector<int>>& ans, vector<int>& subarr, vector<int>& nums, int i){
        int n = nums.size();
        if(i == n){
            ans.push_back(subarr);
            return; 
        }
        subarr.push_back(nums[i]);
        Ps(ans, subarr, nums, i+1);
        subarr.pop_back();
        int idx = i+1;
        while(idx<n && nums[idx] == nums[idx-1]){
            idx++;
        }
        Ps(ans, subarr, nums, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subarr;
        Ps(ans, subarr, nums, 0);
        return ans;
    }
};
```
