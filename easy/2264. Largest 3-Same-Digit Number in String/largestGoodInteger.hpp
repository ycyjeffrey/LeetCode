class Solution {
public:
    string largestGoodInteger(string num) {
        int ret = -1;
        for (int i = 2; i < num.length(); i++)
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2] && num[i] - '0' > ret)
                ret = num[i] - '0';
        if (ret == -1) return "";
        return string(3, ret + '0');
    }
};