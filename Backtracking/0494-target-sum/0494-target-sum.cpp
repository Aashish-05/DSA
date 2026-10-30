class Solution {
public:
//     int solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
//         if(idx==0){
//             if(nums[0]==0 && target==0) return 2;
//             if(nums[0]==target || target==0) return 1;
//             return 0;
//         }
//         if(dp[idx][target] !=-1) return dp[idx][target];
//         int not_take = solve(idx-1,target,nums,dp);
//         int take = 0;
//         if(nums[idx]<=target){
//             take = solve(idx-1,target-nums[idx],nums,dp);
//         }
//         return dp[idx][target]=take+not_take;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         int n=nums.size();
//         for(int x : nums) sum+=x;
//         // similiar to partition with given diff(gfg)
//         // divide into 2 subsets half +ve half -ve 
//         //s1-s2=target && s1+s2=sum;  // new target=(sum+target)/2;
//         if(abs(target)>sum || (sum+target)%2 !=0) return 0;
//         int t = (sum+target)/2;
//         vector<vector<int>>dp(n,vector<int>(t+1,-1));
//         return solve(n-1,t,nums,dp);
//     }


    /*-----------------------tabulation-----------------------------*/
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n=nums.size();
        for(int x : nums) sum+=x;
        if(abs(target)>sum || (sum+target)%2 !=0) return 0;
        int t = (sum+target)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,0));
        dp[0][0] = (nums[0] == 0) ? 2 : 1;
        if(nums[0] !=0 && nums[0]<=t){
            dp[0][nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                int not_take=dp[i-1][j];
                int take=0;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][t];
    }
};