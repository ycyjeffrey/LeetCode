class Solution {
private:
    vector<int> m_arr;
    void m_init(const int& n) {
        m_arr.resize(n);
        for (int i = 0; i < n / 2; i++)
            m_arr[i] = i + 1;
        for (int i = n / 2; i < n; i++)
            m_arr[i] = n - i - 1;
        return;
    }
    bool m_boundCheck(const int& r, const int& c, const int& n) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        m_init(n);
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m_arr[i]; j++) {
                // Across
                int r = n - 1 - j;
                int c = i;
                for (int k = r - 1; k <= r + 1; k++) {
                    if (m_boundCheck(k, c - 1, n))
                        dp[r][c] = max(dp[r][c], dp[k][c - 1]);
                }
                dp[r][c] += fruits[r][c];

                // Down
                swap(r, c);
                for (int k = c - 1; k <= c + 1; k++) {
                    if (m_boundCheck(r - 1, k, n))
                        dp[r][c] = max(dp[r][c], dp[r - 1][k]);
                }
                dp[r][c] += fruits[r][c];
            }

        // Diagonal
        dp[0][0] = fruits[0][0];
        for (int i = 1; i < n; i++)
            dp[i][i] = dp[i - 1][i - 1] + fruits[i][i];
        
        return dp[n - 1][n - 2] + dp[n - 2][n - 1] + dp[n - 1][n - 1];
    }
};