// Recursion -> memorization -> Tabulation
// 0/1 Knapsack by memorization 
//  problem link:https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1 

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&val,vector<int>&wt,int n,int w,int dp[6][11]){
    if(n==0 || w==0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(wt[n-1]<=w){
        return dp[n][w] = max(val[n-1]+solve(val,wt,n-1,w-wt[n-1],dp), solve(val,wt,n-1,w,dp));
    }
    else{
        return dp[n][w] = solve(val,wt,n-1,w,dp);
    }
}
int main(){
    int n = 5;
    int w = 10;
    vector<int> val = {60, 100, 120, 150, 200};
    vector<int> wt = {5, 10, 8, 12, 15};
    int dp[6][11];
    memset(dp,-1,sizeof(dp));
    cout<<solve(val,wt,n,w,dp);
}

