class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Sort
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        // Delete same elements
        vector<int> toSwap1, toSwap2;
        int ptr1 = 0, ptr2 = 0, n = basket1.size();
        while (ptr1 < n && ptr2 < n) {
            if (basket1[ptr1] == basket2[ptr2]) {
                ptr1++;
                ptr2++;
            }
            else if (basket1[ptr1] < basket2[ptr2])
                toSwap1.push_back(basket1[ptr1++]);
            else
                toSwap2.push_back(basket2[ptr2++]);
        }
        while (ptr1 < n)
            toSwap1.push_back(basket1[ptr1++]);
        while (ptr2 < n)
            toSwap2.push_back(basket2[ptr2++]);
        
        // If # of different elements are not equal, then it is not feasible 
        if (toSwap1.size() != toSwap2.size())
            return -1;

        // If there is a different element with odd #, then it is not feasible
        if (toSwap1.size() % 2 == 1)
            return -1;
        int m = toSwap1.size() / 2;
        for (int i = 0; i < 2 * m; i += 2)
            if (toSwap1[i] != toSwap1[i + 1] || toSwap2[i] != toSwap2[i + 1])
                return -1;

        // Count cost
        // There are two methods to swap:
        // 1. Directly swapping a and b, which costs min(a, b)
        // 2. Using x = min(min(basket1), min(basket2)) to swap, which costs 2 * x
        int min1 = *min_element(basket1.begin(), basket1.end());
        int min2 = *min_element(basket2.begin(), basket2.end());
        int x = min(min1, min2);
        int swapCount = 0;
        ptr1 = ptr2 = 0;
        long long ret = 0;
        while (swapCount < m) {
            if (toSwap1[ptr1] < toSwap2[ptr2]) {
                ret += (2 * x < toSwap1[ptr1])? 2 * x : toSwap1[ptr1];
                ptr1 += 2;
            } else {
                ret += (2 * x < toSwap2[ptr2])? 2 * x : toSwap2[ptr2];
                ptr2 += 2;
            }
            swapCount++;
        }

        return ret;
    }
};