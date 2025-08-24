class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool startwithzero = (nums[0] == 0);
        vector<int> consecutive;
        int len = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                len++;
            else {
                consecutive.push_back(len);
                len = 1;
            }
        }
        if (consecutive.size() == 1 && startwithzero)
            return 0;
        if (consecutive.size() == 1 && !startwithzero)
            return nums.size() - 1;
        int ret = 0;
        for (int i = startwithzero? 1 : 0; i < consecutive.size(); i += 2) {
            if (i >= consecutive.size() - 2 || consecutive[i + 1] > 1)
                ret = max(ret, consecutive[i]);
            else
                ret = max(ret, consecutive[i] + consecutive[i + 2]);
        }
        return ret;
    }
};