class Solution {
private:
    void putin(const vector<vector<int>>& mat, vector<int>& ret, const int& r, const int& c, const int& length) {
        bool state = (r + c + length) % 2;
        for (int i = 0; i < length; i++) {
            int row = state? r + length - i - 1 : r + i;
            int col = state? c + i : c + length - i - 1;
            ret.push_back(mat[row][col]);
        }
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ret;
        int r = 0, c = 0, length = 0;
        while (length < min(m, n)) {
            length++;
            putin(mat, ret, r, c, length);
        }
        while (r < m - n) { // If m <= n, then this block is not executed
            r++;
            putin(mat, ret, r, c, length);
        }
        while (c < n - m) { // If n <= m, then this block is not executed
            c++;
            putin(mat, ret, r, c, length);
        }
        while (length >= 1) {
            r++;
            c++;
            length--;
            putin(mat, ret, r, c, length);
        }
        return ret;
    }
};