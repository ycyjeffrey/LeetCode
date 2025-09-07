class Solution(object):
    def sumZero(self, n):
        ret = [i for i in range(1, n // 2 + 1)] + [-i for i in range(1, n // 2 + 1)]
        if n % 2 == 1:
            ret.append(0)
        return ret