class Solution {
public:
    // int solve(int idx1,int idx2,string &s1,string &s2,vector<vector<int>>&dp){
    //     if(idx1<0 || idx2<0) return 0;
    //     if(dp[idx1][idx2] !=-1) return dp[idx1][idx2];
    //     if(s1[idx1]==s2[idx2]){
    //         return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,s1,s2,dp);
    //     }
    //     else return dp[idx1][idx2]=max(solve(idx1-1,idx2,s1,s2,dp),solve(idx1,idx2-1,s1,s2,dp));
    // }
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return solve(n-1,m-1,s1,s2,dp);
    // }


    /*--------------------------Tabulation-----------------------------*/
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};