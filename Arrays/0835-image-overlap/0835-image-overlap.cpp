class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxOverlap = 0;
        for (int rowOff = -n + 1; rowOff < n; rowOff++) {
            for (int colOff = -n + 1; colOff < n; colOff++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (colOff + j > n - 1 || colOff + j < 0 ||
                            rowOff + i > n - 1 || rowOff + i < 0)
                            continue;
                        if (A[rowOff + i][j + colOff] == B[i][j] &&
                            B[i][j] == 1) {
                            count++;
                        }
                    }
                }
                maxOverlap = max(maxOverlap, count);
            }
        }
        return maxOverlap;
    }
};