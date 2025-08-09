class Solution(object):
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        bits = 0
        for i in range(31):
            if (n & (1 << i)):
                bits += 1
        return (bits == 1)