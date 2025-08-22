class Solution(object):
    def minimumArea(self, grid):
        l, d, r, u = 2000, 2000, -1, -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    l = min(l, j)
                    r = max(r, j)
                    u = max(u, i)
                    d = min(d, i)
        return (r + 1 - l) * (u + 1 - d)