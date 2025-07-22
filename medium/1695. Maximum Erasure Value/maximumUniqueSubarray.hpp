class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int windowSum = 0;
        int window[10001]; // Hash map to record the indices inside the window
        memset(window, -1, 10001 * sizeof(int));

        int l = 0;
        int ret = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (window[nums[r]] == -1) {
                windowSum += nums[r];
                ret = max(ret, windowSum);
                window[nums[r]] = r;
            } else {
                int repeatIndex = window[nums[r]];
                for (; l <= repeatIndex; l++) {
                    windowSum -= nums[l];
                    window[nums[l]] = -1;
                }
                windowSum += nums[r];
                window[nums[r]] = r;
            }
        }

        return ret;
    }
};