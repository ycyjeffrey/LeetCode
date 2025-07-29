class Solution {
private:
    void UpdateClosestBit(int *bitIndex, int num, int index) {
        int bit = 0;
        while (num > 0) {
            if (num & 1) bitIndex[bit] = index;
            bit++;
            num = num >> 1;
        }
        return;
    }

    int FindTargetIndex(const int* bitIndex, int target) {
        // The target only has bits that nums[i + 1],..., nums[n - 1] have
        // This means if the target has the k-th bit, then bitIndex[k] has been updated
        int farthest = INT_MIN;
        int bit = 0;
        while (target > 0) {
            if (target & 1) farthest = max(farthest, bitIndex[bit]);
            bit++;
            target = target >> 1;
        }
        return farthest;
    }
    
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int bitIndex[32] = {0}; // bitIndex[i] == The closest index that has the i-th bit
        vector<int> ret(n);

        // Base case
        int maxORval = nums[n - 1];
        ret[n - 1] = 1;
        UpdateClosestBit(bitIndex, nums[n - 1], n - 1);

        for (int i = n - 2; i >= 0; i--) {
            // Determine ret
            maxORval = maxORval | nums[i];
            int target = maxORval & (~nums[i]);
            if (target == 0) ret[i] = 1;
            else ret[i] = FindTargetIndex(bitIndex, target) - i + 1;
            // Update bitIndex
            UpdateClosestBit(bitIndex, nums[i], i);
        }

        return ret;
    }
};