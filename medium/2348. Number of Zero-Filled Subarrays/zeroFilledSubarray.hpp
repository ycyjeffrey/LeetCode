class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ret = 0;
        long long zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros++;
            if (i == nums.size() - 1 || nums[i + 1] != 0) {
                ret += zeros * (zeros + 1) / 2;
                zeros = 0;
            }
        }
        return ret;
    }
};