class Solution(object):
    def longestSubarray(self, nums):
        maxANDval = nums[0]
        ret = sizeCount = 1
        for i in range(1, len(nums)):
            if nums[i] == maxANDval:
                sizeCount += 1
            elif nums[i] > maxANDval:
                maxANDval = nums[i]
                ret = sizeCount = 1
            else:
                sizeCount = 0
            ret = max(ret, sizeCount)
        return ret