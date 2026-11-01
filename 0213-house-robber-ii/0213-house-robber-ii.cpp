class Solution {
public:
     int sum(int idx, vector<int>&nums, vector<int>&dp){
        if(idx ==0 ) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        long long pick = nums[idx]+sum(idx-2,nums,dp);
        long long not_pick = sum(idx-1,nums,dp);
        return dp[idx]=max(pick, not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = sum(n-2, nums, dp1);
        int case2 = sum(n-1, nums, dp2);

        vector<int> temp(nums.begin()+1, nums.end());
        vector<int> dp3(n, -1);

        case2 = sum(temp.size()-1, temp, dp3);

        return max(case1, case2);
    }
};
