class Solution(object):
    def isPowerOfThree(self, n):
        power = 1
        while power <= n:
            if power == n:
                return True
            power *= 3
        return False