class Solution {
public:
    int solve(int idx,vector<int>&arr,vector<int>&dp){
        if(idx==0) return arr[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = arr[idx]+solve(idx-2,arr,dp);
        int notpick = solve(idx-1,arr,dp);
        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>temp1,temp2;
        vector<int>dp1(nums.size(),-1),dp2(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1.size()-1,temp1,dp1),solve(temp2.size()-1,temp2,dp2));
    }
};