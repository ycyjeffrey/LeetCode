class Solution(object):
    def findDiagonalOrder(self, mat):
        def putin(self, ret, r, c, length):
            state = (r + c + length) % 2
            for i in range(length):
                row = r + length - i - 1 if state else r + i
                col = c + i if state else c + length - i - 1
                ret.append(mat[row][col])

        m, n = len(mat), len(mat[0])
        ret = []
        r, c, length = 0, 0, 0
        while length < min(m, n):
            length += 1
            putin(self, ret, r, c, length)
        while r < m - n: # If m <= n, then this block is not executed
            r += 1
            putin(self, ret, r, c, length)
        while c < n - m: # If n <= m, then this block is not executed
            c += 1
            putin(self, ret, r, c, length)
        while length >= 1:
            r += 1
            c += 1
            length -= 1
            putin(self, ret, r, c, length)
        return ret