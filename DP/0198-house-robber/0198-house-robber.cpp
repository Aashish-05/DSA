class Solution {
public:

    // TC: O(n) SC: O(n)+O(n); Memorization
    // int solve(int idx,vector<int>&nums,vector<int>&dp){
    //     if(idx==0) return nums[idx];
    //     if(idx<0) return 0;
    //     if(dp[idx] !=-1) return dp[idx];
    //     int pick = nums[idx]+solve(idx-2,nums,dp);
    //     int notpick = solve(idx-1,nums,dp);
    //     return dp[idx]=max(pick,notpick);
    // }
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n,-1);
    //     return solve(n-1,nums,dp);
    // }

    // Tabulation TC:O(n) SC:O(n);
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        int neg = 0;
        for(int i=1;i<nums.size();i++){
            int pick;
            if(i>1) pick = nums[i]+dp[i-2];
            else  pick = nums[i];
            int notpick = dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[nums.size()-1];
    }
};