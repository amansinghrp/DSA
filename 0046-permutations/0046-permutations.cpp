class Solution {
private:
    void solve(int ind, int &n, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, vector<int> &mp){
        if(ind >= n){
            ans.push_back(curr);
        }

        for(int i=0; i<n; i++){
            int toCheck = nums[i] >=0 ? nums[i] : nums[i] + 21;
            if(!mp[toCheck]){
                curr.push_back(nums[i]);
                mp[toCheck] =1;
                solve(ind+1, n, nums, curr, ans, mp);
                mp[toCheck]=0;
                curr.pop_back();
            } 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>mp(21, 0);
        vector<vector<int>> ans;
        vector<int>curr;
        solve(0, n, nums, curr, ans, mp);
        return ans;
    }
};