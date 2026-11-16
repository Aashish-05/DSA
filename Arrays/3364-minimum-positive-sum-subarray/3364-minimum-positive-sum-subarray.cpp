class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int i=0,j=0;
        int n = nums.size();
        int sum = 0;
        while(i<n && j<n){
            sum+=nums[j];
            if(j-i+1>=l && j-i+1<=r){
                if(sum>0) ans = min(ans,sum);
            }
            if(j-i+1==r || j==n-1){
                sum=0;
                i++;
                j=i;
            }
            else j++;
        }
        return (ans==INT_MAX?-1:ans);
    }
};