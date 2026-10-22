class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(j<0 || j>=n) return 1e9;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j] !=1e9) return dp[i][j];
        int down = matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int leftdiagonal = matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        int rightdiagonal = matrix[i][j]+solve(i+1,j+1,n,matrix,dp);
        return dp[i][j]=min(down,min(leftdiagonal,rightdiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int miniSum = INT_MAX;
        for(int j=0;j<n;j++){
            miniSum=min(miniSum,solve(0,j,n,matrix,dp));
        }
        return miniSum;
    }
};