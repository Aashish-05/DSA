class Solution {
public:
// int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
//     if(j<0 || j>=matrix.size()) return 1e9;
//     if(i==matrix.size()-1) return matrix[i][j];
//     if(dp[i][j] !=1e9) return dp[i][j];
//     int down=matrix[i][j]+solve(i+1,j,matrix,dp);
//     int rightDiag = matrix[i][j]+solve(i+1,j+1,matrix,dp);
//     int leftDiag = matrix[i][j]+solve(i+1,j-1,matrix,dp);
//     return dp[i][j]=min(down,min(rightDiag,leftDiag));
// }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>>dp(n,vector<int>(n,1e9));
//         int ans = INT_MAX;
//         for(int i=0;i<n;i++){
//             ans = min(ans,solve(0,i,matrix,dp));
//         }
//         return ans;
//     }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>>dp(n,vector<int>(n,1e9));
            for(int j=0;j<n;j++){
                dp[n-1][j]=matrix[n-1][j];
            }
            for(int i=n-2;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    int up = matrix[i][j]+dp[i+1][j];
                    int rightDia=INT_MAX,leftDia=INT_MAX;
                    if(j<n-1) rightDia = matrix[i][j]+dp[i+1][j+1];
                    if(j>0) leftDia = matrix[i][j]+dp[i+1][j-1];
                    dp[i][j]=min(dp[i][j],min(up,min(rightDia,leftDia)));

                }
            }
            return *min_element(dp[0].begin(),dp[0].end());
        }
};