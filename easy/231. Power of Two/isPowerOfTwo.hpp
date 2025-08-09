class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        int bits = 0;
        for (int i = 0; i < 31; i++)
            if (n & (1 << i))
                bits++;
        return (bits == 1);
    }
};