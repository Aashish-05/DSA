/* Minimum Sum Partition Question Link: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1

 Ques: Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

 Input: arr[] = [1, 6, 11, 5] Output: 1
 Explanation: 
 Subset1 = {1, 5, 6}, sum of Subset1 = 12 
 Subset2 = {11}, sum of Subset2 = 11 
 Hence, minimum difference is 1.  */

#include <bits/stdc++.h>
using namespace std;
 vector<int>subset(vector<int>&arr,int sum,vector<int>&Points){
       int n = arr.size();
       vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
       for(int i=0;i<n+1;i++){
           dp[i][0]=1;
       }
       for(int i=1;i<n+1;i++){
           for(int j=1;j<sum+1;j++){
               if(arr[i-1]<=j){
                   dp[i][j]=(dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
               }
               else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       for(int i=0;i<=sum/2;i++){
           if(dp[n][i]==true){
               Points.push_back(i);
           }
       }
       return Points;
   }
int main(){                               // FLOW = we had to minimize |s2-s1|,s2=total-s1,now mujhe ye pta lgana hai ki kon se points jai jinpe mera sum true aa rha hai points
    vector<int>arr = {1,6,11,5};          // subset sum ki help se aa jayga
    int n = arr.size();
    int range=0;
    for(int i=0;i<n;i++){
        range+=arr[i];
    }
    vector<int>Points;
    subset(arr,range,Points);
    int mn=INT_MAX;
    for(int i=0;i<Points.size();i++){
        mn = min(mn,range-2*Points[i]);
    }
    cout<<mn;
}