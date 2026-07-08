class Solution {
private:
    void solve(vector<int> nums, int ind, int n, vector<vector<int>> &ans, vector<int> curr){
        ans.push_back(curr);
        for(int i =ind; i<n; i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            solve(nums, i+1, n, ans, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        sort(nums.begin(), nums.end());
        solve(nums, 0, nums.size(), ans, curr);
        return ans;
    }
};