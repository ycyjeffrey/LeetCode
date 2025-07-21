class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n <= 2)
            return s;
        string ret;
        ret += s[0];
        ret += s[1];
        int count = 2;
        for (int i = 2; i < n; i++) {
            if (s[i] == ret[count - 2] && ret[count - 2] == ret[count - 1])
                continue;
            else {
                ret += s[i];
                count++;
            }
        }
        return ret;
    }
};