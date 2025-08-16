class Solution(object):
    def isPowerOfFour(self, n):
        power = 1
        while power <= n:
            if power == n:
                return True
            power *= 4
        return False