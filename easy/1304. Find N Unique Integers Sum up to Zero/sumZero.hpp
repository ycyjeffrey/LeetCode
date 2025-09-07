class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret(n, 0);
        for (int i = 0; i < n / 2; i++) {
            ret[2 * i] = i + 1;
            ret[2 * i + 1] = -(i + 1);
        }
        return ret;
    }
};