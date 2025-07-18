class Solution(object):
    def intersection(self, nums1, nums2):
        freq = [False] * 1001
        for val in nums1:
            freq[val] = True
        
        ret = []
        for val in nums2:
            if freq[val]:
                ret.append(val)
                freq[val] = False
        
        return ret
        