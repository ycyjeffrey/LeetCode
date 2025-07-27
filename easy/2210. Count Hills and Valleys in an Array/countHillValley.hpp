class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Determine the first index l s.t. nums[l] does not equal nums[0]
        int l = 1;
        while (l < nums.size() && nums[l] == nums[l - 1])
            l++;
            // Loop invariant: nums[0] == ... == nums[l - 1]
        int r = l;

        // Determine the last index end s.t. nums[end] does not equal nums[-1]
        int end = nums.size() - 2;
        while (end >= 0 && nums[end] == nums[end + 1])
            end--;
            // Loop invariant: nums[end + 1] == ... == nums[-1]

        int count = 0;
        while (r <= end) {
            // As r <= end, nums[r] != nums[-1], this means r cannot be out of bound
            while (nums[r] == nums[r + 1]) 
                r++;
            int val = nums[r];
            if ((nums[l - 1] < val && nums[r + 1] < val) || (nums[l - 1] > val && nums[r + 1] > val))
                count++;
            l = r = r + 1;
        }
        return count;
    }
};