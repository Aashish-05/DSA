// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
// Note: Each element must be in exactly one subset.
// Examples: Input: arr = [1, 5, 11, 5] Output: true Explanation: The two parts are [1, 5, 5] and [11]
//Problem Link: https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,5,11,5};
    int n = nums.size();
    int total=0;
    for(int  i=0;i<n;i++){
        total+=nums[i];
    }
    if(total%2 !=0) return false;
    int sum = total/2;
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]=(dp[i-1][j-nums[i-1]]) || (dp[i-1][j]);    // Agar humse total number of subsets pochege to dp[i][j]=(dp[i-1][j-nums[i-1]])+(dp[i-1][j]); 
            }                                                       // plus isiliye kiya kyuki total = include+exclude (+=all possible ways);
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}