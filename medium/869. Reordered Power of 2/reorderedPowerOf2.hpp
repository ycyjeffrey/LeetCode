class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<string>> table = {{"1", "2", "4", "8"}, {"16", "23", "46"}, {"128", "256", "125"}, {"0124", "0248", "0469", "1289"}, {"13468", "23678", "35566"}, {"011237", "122446", "224588"}, {"0145678", "0122579", "0134449", "0368888"}, {"11266777", "23334455", "01466788"}, {"112234778", "234455668", "012356789"}, {"0112344778"}};
        int count[10] = {0};
        int len = 0;
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
            len++;
        }
        string s = "";
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < count[i]; j++)
                s += i +'0';
        for (auto& str : table[len - 1])
            if (s == str)
                return true;
        return false;
    }
};