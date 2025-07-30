class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxANDval = nums[0];
        int ret = 1, sizeCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == maxANDval)
                sizeCount++;
            else if (nums[i] > maxANDval) {
                maxANDval = nums[i];
                ret = sizeCount = 1;
            } else
                sizeCount = 0;
            ret = max(ret, sizeCount);
        }
        return ret;
    }
};