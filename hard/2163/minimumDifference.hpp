class Solution {
public:
    long long edgeCase(vector<int>& nums) {
        assert(nums.size() == 3);
        int a = nums[0] - nums[1];
        int b = nums[1] - nums[2];
        int c = nums[0] - nums[3];
        return min(a, min(b, c));
    }
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        // Deal with edge case
        if (n == 1)
            return edgeCase(nums);

        array<long long, 100001> dp1; // dp1[i] = the minimum n - 1 number sum in nums[0] to nums[i + n - 2], i = 0, 1,..., n
        array<long long, 100001> dp2; // dp2[i] = the maximum n nunmber sum in nums[i + n] to nums[3n - 1], i = 0, 1,..., n

        // Initialize dp1 using a max heap
        // Base case: nums[0] to nums[n - 2] have exactly n - 1 numbers
        priority_queue<int> max_heap;
        dp1[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            dp1[0] += nums[i];
            max_heap.push(nums[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (nums[i + n - 2] < max_heap.top()) {
                int del = max_heap.top();
                max_heap.pop();
                max_heap.push(nums[i + n - 2]);
                dp1[i] = dp1[i - 1] - del + nums[i + n - 2];
            } else dp1[i] = dp1[i - 1];
        }
    
        // Initialize dp2 using a min heap
        priority_queue<int, vector<int>, greater<int>> min_heap;
        dp2[n] = 0;
        // Base case: nums[2n] to nums[3n - 1] have exactly n numbers
        for (int i = 2 * n; i < 3 * n; i++) {
            dp2[n] += nums[i];
            min_heap.push(nums[i]);
        }
        for (int i = n - 1; i >= 0; i--)
            if (nums[i + n] > min_heap.top()) {
                int del = min_heap.top();
                min_heap.pop();
                min_heap.push(nums[i + n]);
                dp2[i] = dp2[i + 1] - del + nums[i + n];
            } else dp2[i] = dp2[i + 1];

        // The last number in the first part can be nums[n - 1], nums[n + 1],..., nums[2n - 1]
        // If it is nums[i + n - 1], first part min sum is dp1[i] + nums[i + n - 1], second part max sum is dp2[i]
        long long ret = INT64_MAX;
        for (int i = 0; i <= n; i++)
            ret = min(ret, dp1[i] + nums[i + n - 1] - dp2[i]);

        return ret;
    }
};