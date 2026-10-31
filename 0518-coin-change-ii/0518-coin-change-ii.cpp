class Solution {
public:
    // int solve(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
    //     if(idx==0){
    //         if(amount%coins[0]==0  || amount==0) return 1;
    //         else return 0;
    //     }
    //     if(dp[idx][amount] !=-1) return dp[idx][amount];
    //     int not_take = solve(idx-1,amount,coins,dp);
    //     int take = 0;
    //     if(coins[idx]<=amount){
    //         take = solve(idx,amount-coins[idx],coins,dp);
    //     }
    //     return dp[idx][amount]=take+not_take;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //     return solve(n-1,amount,coins,dp);
    // }

    /*----------------------Tabulation------------------------------*/
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        dp[0][0]=1;
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned long long not_take = dp[i-1][j];
                unsigned long long take = 0;
                if(coins[i]<=j){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};