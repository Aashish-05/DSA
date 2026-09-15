class Solution {
public:
    bool check(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        while (i + k - 1 < n) {
            if (check(i, i + k - 1, s)) {
                i += k;
                ans++;
            } else if ((i+k<n) && check(i,i+k,s)) {
                i+=k+1;
                ans++;
            } else {
                i++;
            }
        }
        return ans;
    }
};