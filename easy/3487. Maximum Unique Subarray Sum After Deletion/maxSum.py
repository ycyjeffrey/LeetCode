class Solution(object):
    def maxSum(self, nums):
        maxNum = -200
        for v in nums:
            maxNum = max(maxNum, v)
        if maxNum < 0:
            return maxNum
        hash = [False] * 101
        ret = 0
        for v in nums:
            if v > 0 and not hash[v]:
                ret += v
                hash[v] = True
        return ret