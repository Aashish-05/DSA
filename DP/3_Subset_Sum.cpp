// Subset-sum: Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 
// QuesLink : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;
    int n  = arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];

}