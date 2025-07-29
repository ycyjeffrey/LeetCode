class Solution(object):
    def smallestSubarrays(self, nums):
        def UpdateClosestBit(self, bitIndex, num, index):
            # The target only has bits that nums[i + 1],..., nums[n - 1] have
            # This means if the target has the k-th bit, then bitIndex[k] has been updated
            bit = 0
            while num > 0:
                if num & 1 == 1:
                    bitIndex[bit] = index
                bit += 1
                num = num >> 1
            return
        
        def FindTargetIndex(self, bitIndex, target):
            farthest = -10e6
            bit = 0
            while target > 0:
                if target & 1 == 1:
                    farthest = max(farthest, bitIndex[bit])
                bit += 1
                target = target >> 1
            return farthest
        
        bitIndex = [0] * 32 # bitIndex[i] == The closest index that has the i-th bit
        ret = [0] * len(nums)

        # Base case
        maxORval = nums[-1]
        ret[-1] = 1
        UpdateClosestBit(self, bitIndex, nums[-1], len(nums) - 1)

        for i in range(len(nums) - 2, -1, -1):
            # Determine ret
            maxORval = maxORval | nums[i]
            target = maxORval & (~nums[i])
            if target == 0:
                ret[i] = 1
            else:
                ret[i] = FindTargetIndex(self, bitIndex, target) - i + 1
            # Update bitIndex
            UpdateClosestBit(self, bitIndex, nums[i], i)
        
        return ret