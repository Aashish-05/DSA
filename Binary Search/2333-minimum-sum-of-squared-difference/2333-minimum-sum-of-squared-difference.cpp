
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        long long k = 1LL * k1 + k2;

        if (k >= total) return 0;

        // Minimum operations required to make every difference <= x
        auto operations = [&](int x) -> long long {
            long long need = 0;
            for (int d : diff) {
                if (d > x) need += d - x;
            }
            return need;
        };

        // Find the smallest feasible maximum difference
        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (operations(mid) <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int x = low;
        long long used = operations(x);
        long long remaining = k - used;

        long long ans = 0;

        for (int d : diff) {
            int value = min(d, x);
            ans += 1LL * value * value;
        }

        // Use remaining operations to reduce x to x - 1
        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= x && x > 0) {
                ans -= 2LL * x - 1;
                remaining--;
            }
        }

        return ans;
    }
};
