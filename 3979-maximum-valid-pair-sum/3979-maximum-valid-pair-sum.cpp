class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int mx = nums[0];
        int ans = 0;
        for(int i=k;i<nums.size();i++){
            mx = max(mx,nums[i-k]);
            ans = max(ans,nums[i]+mx);
        }
        return ans;
    }
};