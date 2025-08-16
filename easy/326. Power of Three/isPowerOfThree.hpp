class Solution {
public:
    bool isPowerOfThree(int n) {
        long long power = 1;
        while (power <= n) {
            if (power == n)
                return true;
            power *= 3;
        }
        return false;
    }
};