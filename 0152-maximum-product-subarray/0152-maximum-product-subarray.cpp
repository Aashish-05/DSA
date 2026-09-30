class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int oldMax = maxi;
            int oldMin = mini;

            maxi = max({x, x * oldMax, x * oldMin});
            mini = min({x, x * oldMax, x * oldMin});

            ans = max(ans, maxi);
        }

        return ans;
    }
};