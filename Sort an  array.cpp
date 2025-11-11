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
    void merge(vector<int> &nums, int left, int mid, int right){
        int n = nums.size();
        vector<int> temp;
        int i = left;
        int j = mid+1;
        while(i<=mid && j<=right){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<= right){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k = left; k<=right; k++){
            nums[k] = temp[k - left];
        }
    }
    void mergesort(vector<int> &nums, int left, int right){
        if(left >= right){
            return;
        }
        int mid = (left + right)/2;
        mergesort(nums, left, mid);
        mergesort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        mergesort(nums, 0, n-1);
        return nums;
    }
};
