class Solution {
private:
    int twoPow[18] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
    void isTarget(const vector<int>& nums, const int& target, int i, int ORval, int& ret) {
        if (i == nums.size()) {
            ret += (ORval == target);
            return;
        }
        if (ORval == target) {
            ret += twoPow[nums.size() - i];
            return;
        }
        isTarget(nums, target, i + 1, ORval, ret);
        isTarget(nums, target, i + 1, ORval | nums[i], ret);
        return;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (const int& num : nums)
            target = target | num;
        int ret = 0;
        isTarget(nums, target, 0, 0, ret);
        return ret;
    }
};