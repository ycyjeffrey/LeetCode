class Solution(object):
    def countMaxOrSubsets(self, nums):
        twoPow = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072]

        def isTarget(self, nums, target, i, ORval):
            if i == len(nums):
                if ORval == target:
                    return 1
                else:
                    return 0
            if ORval == target:
                return twoPow[len(nums) - i]
            return isTarget(self, nums, target, i + 1, ORval) + isTarget(self, nums, target, i + 1, ORval | nums[i])
        
        target = 0
        for num in nums:
            target = target | num
        return isTarget(self, nums, target, 0, 0)