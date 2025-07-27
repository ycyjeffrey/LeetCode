class Solution(object):
    def countHillValley(self, nums):
        # Determine the first index l s.t. nums[l] does not equal nums[0]
        l = 1
        while l < len(nums) and nums[l] == nums[l - 1]:
            l += 1
            # Loop invariant: nums[0] == ... == nums[l - 1]
        r = l

        # Determine the last index end s.t. nums[end] does not equal nums[-1]
        end = len(nums) - 2
        while end >= 0 and nums[end] == nums[end + 1]:
            end -= 1
            # Loop invariant: nums[end + 1] == ... == nums[-1]

        count = 0
        while r <= end:
            # As r <= end, nums[r] != nums[-1], this means r cannot be out of bound
            while nums[r] == nums[r + 1]:
                r += 1
            val = nums[r]
            if (nums[l - 1] < val and nums[r + 1] < val) or (nums[l - 1] > val and nums[r + 1] > val):
                count += 1
            l = r = r + 1
        return count