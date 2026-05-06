/* Problem: Count Subsets with Given Difference
You are given an integer array arr of size n and an integer diff.

Divide the array into two subsets S1 and S2 such that:

∣S1−S2∣=diff

Return the number of ways to achieve this.
📥 Input
First line: integer n
Second line: n space-separated integers
Third line: integer diff
📤 Output
Print the number of subsets satisfying the condition */

// Approach = |sum(s1)-sum(s2)|==diff and we know that sum(s1)+sum(s2)==total adding both equation will give 2*sum(s1)=total+diff; now its a count subset sum prob; 

#include <bits/stdc++.h>
using namespace std;
int subset(vector<int>&arr,int sum){
    int n = arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]= (dp[i-1][j-arr[i-1]]) + (dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int diff;
    cin>>diff;
    int total = 0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    int sum1 = (diff+total)/2;
    cout<<subset(arr,sum1);
}


// TARGET SUM BHI SAME HAI