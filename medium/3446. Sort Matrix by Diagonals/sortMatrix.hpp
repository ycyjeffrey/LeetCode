class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ret(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            vector<int> diag(n - i);
            for (int j = 0; j < n - i; j++)
                diag[j] = grid[i + j][j];
            sort(diag.begin(), diag.end());
            for (int j = 0; j < n - i; j++)
                ret[i + j][j] = diag[n - i - 1 - j];
        }
        for (int i = 1; i < n; i++) {
            vector<int> diag(n - i);
            for (int j = 0; j < n - i; j++)
                diag[j] = grid[j][i + j];
            sort(diag.begin(), diag.end());
            for (int j = 0; j < n - i; j++)
                ret[j][i + j] = diag[j];
        }
        return ret;
    }
};