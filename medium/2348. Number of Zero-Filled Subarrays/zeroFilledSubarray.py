class Solution(object):
    def zeroFilledSubarray(self, nums):
        ret = 0
        zeros = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                zeros += 1
            if i == len(nums) - 1 or nums[i + 1] != 0:
                ret += zeros * (zeros + 1) / 2
                zeros = 0
        return ret