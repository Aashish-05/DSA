// QUES-0/1 Knapsack by Top-Down approach
// Recursive ki base condition convert ho jti hai dp-initialization me and recursive calls convert ho jti hai dp-filling me

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 5;
    int w = 10;
    vector<int> val = {60, 100, 120, 150, 200};
    vector<int> wt = {5, 10, 8, 12, 15};
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w];
}