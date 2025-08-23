class Rectangle {
public:
    bool nothing;
    int l, r, u, d;
    Rectangle() : nothing(true), l(0), r(0), u(0), d(0) {}
    Rectangle(const vector<vector<int>>& grid, const int& r1, const int& r2, const int& c1, const int& c2) {
        l = u = INT_MAX;
        r = d = INT_MIN;
        nothing = true;
        for (int i = r1; i <= r2; i++)
            for (int j = c1; j <= c2; j++)
                if (grid[i][j] == 1) {
                    nothing = false;
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, i);
                }
    }
    Rectangle operator=(const Rectangle& other) {
        nothing = other.nothing;
        l = other.l;
        r = other.r;
        u = other.u;
        d = other.d;
        return *this;
    }
    int getArea() {
        if (nothing) return 500000;
        return (r - l + 1) * (d - u + 1);
    }
    int split2(vector<vector<int>>& grid) {
        int minArea = 500000;
        vector<Rectangle> ret(2);
        for (int i = u; i < d; i++) {
            Rectangle rec1(grid, u, i, l, r);
            Rectangle rec2(grid, i + 1, d, l, r);
            int area = rec1.getArea() + rec2.getArea();
            if (area < minArea)
                minArea = area;
        }
        for (int j = l; j < r; j++) {
            Rectangle rec1(grid, u, d, l, j);
            Rectangle rec2(grid, u, d, j + 1, r);
            int area = rec1.getArea() + rec2.getArea();
            if (area < minArea)
                minArea = area;
        }
        return minArea;
    }
};

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minArea = 500000;
        vector<vector<Rectangle>> cand;
        for (int i = 0; i < m - 1; i++) {
            Rectangle rec1(grid, 0, i, 0, n - 1);
            Rectangle rec2(grid, i + 1, m - 1, 0, n - 1);
            cand.push_back({rec1, rec2});
        }
        for (int j = 0; j < n - 1; j++) {
            Rectangle rec1(grid, 0, m - 1, 0, j);
            Rectangle rec2(grid, 0, m - 1, j + 1, n - 1);
            cand.push_back({rec1, rec2});
        }
        for (auto& recs : cand) {
            minArea = min(minArea, recs[0].split2(grid) + recs[1].getArea());
            minArea = min(minArea, recs[0].getArea() + recs[1].split2(grid));
        }
        return minArea;
    }
};