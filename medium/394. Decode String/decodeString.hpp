class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> S;
        int i = 0;
        string ret;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                S.push({0, ""});
                while (isdigit(s[i])) {
                    S.top().first = 10 * S.top().first + s[i] - '0';
                    i++;
                }
                i++;
                while (isalpha(s[i])) {
                    S.top().second += s[i];
                    i++;
                }
            } else if (isalpha(s[i])) {
                if (!S.empty()) S.top().second += s[i];
                else ret += s[i];
                i++;
            } else { // s[i] == ']'
                auto [freq, str] = S.top();
                S.pop();
                if (!S.empty()) {
                    for (int j = 0; j < freq; j++)
                        S.top().second += str;
                } else {
                    for (int j = 0; j < freq; j++)
                        ret += str;
                }
                i++;
            }
        }
        return ret;
    }
};