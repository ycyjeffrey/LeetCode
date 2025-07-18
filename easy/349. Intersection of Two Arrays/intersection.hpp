class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        array<bool, 1001> freq;
        for (auto& val : nums1)
            freq[val] = true;

        vector<int> ret;
        for (auto& val : nums2)
            if (freq[val]) {
                ret.push_back(val);
                freq[val] = false;
            }

        return ret;
    }
};