#define POWERLEN 20
long long power[POWERLEN];
long long prefix[POWERLEN];
class Solution {
private:
    void init() {
        power[0] = 1;
        for (int i = 1; i < POWERLEN; i++)
            power[i] = power[i - 1] * 4;
        prefix[0] = 3;
        for (int i = 1; i < POWERLEN - 1; i++)
            prefix[i] = prefix[i - 1] + (i + 1) * (power[i + 1] - power[i]);
        return;
    }
    int log4(const int x) const {
        if (x <= 3)
            return 0;
        return log4(x / 4) + 1;
    }
    long long query(int l, int r) {
        long long a = log4(l), b = log4(r);
        if (a == 0 && b == 0)
            return (r - l + 2) / 2;
        return (prefix[b - 1] - prefix[a] + (a + 1) * (power[a + 1] - l) + (b + 1) * (r - power[b] + 1) + 1) / 2;   
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        init();
        long long ret = 0;
        for (auto& q : queries)
            ret += query(q[0], q[1]);
        return ret;
    }
};