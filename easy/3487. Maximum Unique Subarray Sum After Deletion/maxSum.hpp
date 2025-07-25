class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxNum = INT_MIN;
        for (auto& v : nums)
            maxNum = max(maxNum, v);
        if (maxNum <= 0) return maxNum;
        bool hash[101] = {false};
        int ret = 0;
        for (auto& v : nums) {
            if (v > 0 && !hash[v]) {
                ret += v;
                hash[v] = true;
            }
        }
        return ret;
    }
};