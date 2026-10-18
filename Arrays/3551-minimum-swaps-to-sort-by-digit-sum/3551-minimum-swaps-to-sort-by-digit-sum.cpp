#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store tuple: {{digit_sum, value}, original_index}
        vector<pair<pair<int, int>, int>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        // Default sort compares pair.first (digit_sum, then value)
        sort(items.begin(), items.end());
        
        vector<bool> visited(n, false);
        int total_swaps = 0;
        
        // Trace permutation cycles
        for (int i = 0; i < n; ++i) {
            // Skip if already in the correct position or visited
            if (visited[i] || items[i].second == i) {
                continue;
            }
            
            int cycle_size = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = items[curr].second;
                cycle_size++;
            }
            
            if (cycle_size > 0) {
                total_swaps += (cycle_size - 1);
            }
        }
        
        return total_swaps;
    }
};