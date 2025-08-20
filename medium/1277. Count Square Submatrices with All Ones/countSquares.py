class Solution(object):
    def countSquares(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        ret = 0
        for i in range(m):
            dp[i][0] = (matrix[i][0] == 1)
            ret += dp[i][0]
        for j in range(1, n):
            dp[0][j] = (matrix[0][j] == 1)
            ret += dp[0][j]
        for i in range(1, m):
            for j in range(1, n):
                if (matrix[i][j] == 0):
                    dp[i][j] = 0
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
                    ret += dp[i][j]
        return ret