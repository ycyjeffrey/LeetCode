class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        if (n <= 9)
            return {1, n - 1};
        int memory = n;
        int n1 = 0, power = 1;
        while (n > 9) {
            int digit = (n % 10 != 1)? 1 : 2;
            n1 += power * digit;
            n = (n - digit) / 10;
            power *= 10;
        }
        return {n1, memory - n1};
    }
};