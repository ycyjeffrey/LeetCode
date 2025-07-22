class Solution(object):
    def maximumUniqueSubarray(self, nums):
        windowSum = 0
        window = [-1] * 10001

        l = 0
        ret = 0
        for r in range(0, len(nums)):
            num = nums[r]
            if window[num] == -1:
                windowSum += num
                window[num] = r
                ret = max(ret, windowSum)
            else:
                repeatIndex = window[num]
                while l <= repeatIndex:
                    windowSum -= nums[l]
                    window[nums[l]] = -1
                    l += 1
                windowSum += num
                window[num] = r
        
        return ret