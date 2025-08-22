class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = INT_MAX, r = INT_MIN, u = INT_MIN, d = INT_MAX;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    u = max(u, i);
                    d = min(d, i);
                }
        return (r + 1 - l) * (u + 1 - d);
    }
};