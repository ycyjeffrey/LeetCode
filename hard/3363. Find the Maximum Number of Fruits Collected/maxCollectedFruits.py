class Solution(object):
    def maxCollectedFruits(self, fruits):
        def boundCheck(r, c, n):
            return r >= 0 and r < n and c >= 0 and c < n
        
        n = len(fruits)
        arr = [i + 1 for i in range(n // 2)] + [n - i - 1 for i in range(n // 2, n)]
        dp = [[0 for i in range(n)] for j in range(n)]
        for i in range(n - 1):
            for j in range(arr[i]):
                # Across
                r = n - 1 - j
                c = i
                for k in range(r - 1, r + 2):
                    if boundCheck(k, c - 1, n):
                        dp[r][c] = max(dp[r][c], dp[k][c - 1])
                dp[r][c] += fruits[r][c]

                # Down
                r = i
                c = n - 1 - j
                for k in range(c - 1, c + 2):
                    if boundCheck(r - 1, k, n):
                        dp[r][c] = max(dp[r][c], dp[r - 1][k])
                dp[r][c] += fruits[r][c]

        # Diagonal
        dp[0][0] = fruits[0][0]
        for i in range(1, n):
            dp[i][i] = dp[i - 1][i - 1] + fruits[i][i]
        
        for i in range(n):
            print(dp[i])
        return dp[n - 2][n - 1] + dp[n - 1][n - 2] + dp[n - 1][n - 1]