class Solution(object):
    def longestSubarray(self, nums):
        consecutive = []
        leng = 1
        for i in range(len(nums)):
            if i < len(nums) - 1 and nums[i] == nums[i + 1]:
                leng += 1
            else:
                consecutive.append(leng)
                leng = 1
        if len(consecutive) == 1 and nums[0] == 0:
            return 0
        if len(consecutive) == 1 and nums[0] == 1:
            return len(nums) - 1
        ret = 0
        start = 0
        if nums[0] == 0:
            start = 1
        for i in range(start, len(consecutive), 2):
            if i >= len(consecutive) - 2 or consecutive[i + 1] > 1:
                ret = max(ret, consecutive[i])
            else:
                ret = max(ret, consecutive[i] + consecutive[i + 2])
        return ret