class Solution {
public:
// int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
//     if(i==0 && j==0 && grid[i][j] !=1) return 1;
//     if(i<0 || j<0) return 0;
//     if(dp[i][j] !=-1) return dp[i][j];
//     if(grid[i][j] !=1){
//         int up = solve(i-1,j,dp,grid);
//         int left = solve(i,j-1,dp,grid);
//         return dp[i][j] = up+left;
//     }
//     else return dp[i][j]=0;
// }
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return solve(m-1,n-1,dp,grid);
//     }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        // first column
        for(int i=1;i<m;i++){
            if(grid[i][0] !=1) dp[i][0]=dp[i-1][0];
            else dp[i][0]=0;
        }
        // first row;
        for(int j=1;j<n;j++){
            if(grid[0][j] !=1) dp[0][j]=dp[0][j-1];
            else dp[0][j]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j] !=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};