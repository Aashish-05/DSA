class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    for (int a = 0; a < m; a++) {
                        arr[i][a] = 0;
                    }
                    for (int b = 0; b < n; b++) {
                        arr[b][j] = 0;
                    }
                }
            }
        }
        matrix = arr;
    }
};