# from headq import *
class Solution(object):
    def edgeCase(self, nums):
        a = nums[0] - nums[1]
        b = nums[1] - nums[2]
        c = nums[0] - nums[2]
        return min(a, min(b, c))
    def minimumDifference(self, nums):
        n = len(nums) / 3
        if n == 1:
            return self.edgeCase(nums)
        dp1 = [0] * (len(nums) + 1) # dp1[i] = the minimum n - 1 number sum in nums[0] to nums[i + n - 2], i = 0, 1,..., n
        dp2 = [0] * (len(nums) + 1) # dp2[i] = the maximum n nunmber sum in nums[i + n] to nums[3n - 1], i = 0, 1,..., n

        # Initialize dp1 using a max heap
        # Base case: nums[0] to nums[n - 2] have exactly n - 1 numbers
        max_heap = []
        dp1[0] = 0
        for i in range(n - 1):
            dp1[0] += nums[i]
            heappush(max_heap, -nums[i])

        for i in range(1, n + 1):
            if nums[i + n - 2] < -max_heap[0]:
                dp1[i] = dp1[i - 1] - (-max_heap[0]) + nums[i + n - 2]
                heappop(max_heap)
                heappush(max_heap, -nums[i + n - 2])
            else:
                dp1[i] = dp1[i - 1]

        # Initialize dp2 using a min heap
        # Base case: nums[2n] to nums[3n - 1] have exactly n numbers
        min_heap = []
        dp2[n] = 0
        for i in range(3 * n - 1, 2 * n - 1, -1):
            dp2[n] += nums[i]
            heappush(min_heap, nums[i])

        for i in range(n - 1, -1, -1):
            if nums[i + n] > min_heap[0]:
                dp2[i] = dp2[i + 1] - min_heap[0] + nums[i + n]
                heappop(min_heap)
                heappush(min_heap, nums[i + n])
            else:
                dp2[i] = dp2[i + 1]


        # The last number in the first part can be nums[n - 1], nums[n + 1],..., nums[2n - 1]
        # If it is nums[i + n - 1], first part min sum is dp1[i] + nums[i + n - 1], second part max sum is dp2[i]
        ret = 1e10
        for i in range(0, n + 1):
            ret = min(ret, dp1[i] + nums[i + n - 1] - dp2[i])

        return ret