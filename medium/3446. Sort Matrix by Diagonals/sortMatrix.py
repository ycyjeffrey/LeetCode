class Solution(object):
    def sortMatrix(self, grid):
        n = len(grid)
        ret = [[0 for i in range(n)] for j in range(n)]
        for i in range(n):
            diag = []
            for j in range(n - i):
                diag.append(grid[i + j][j])
            diag.sort()
            for j in range(n - i):
                ret[i + j][j] = diag[n - i - 1 - j]
        for i in range(1, n):
            diag = []
            for j in range(n - i):
                diag.append(grid[j][i + j])
            diag.sort()
            for j in range(n - i):
                ret[j][i + j] = diag[j]
        return ret