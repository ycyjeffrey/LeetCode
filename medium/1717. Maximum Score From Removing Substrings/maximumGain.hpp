class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int xCount = 0, yCount = 0;
        // Guarantee y >= x
        if (x > y) {
            reverse(s.begin(), s.end());
            swap(x, y);
        }
        stack<char> S;
        // Greedily find "ba" using a stack
        for (auto& c : s) {
            if (c != 'a' && c != 'b') {
                // Erase S, which can only be in the form "a...ab...b"
                int aCount = 0, bCount = 0;
                while (!S.empty()) {
                    if (S.top() == 'a') aCount++;
                    else bCount++;
                    S.pop();
                }
                xCount += min(aCount, bCount);
            } else if (c == 'a' && !S.empty() && S.top() == 'b') {
                yCount++;
                S.pop();
            } else {
                S.push(c);
            }
        }
        int aCount = 0, bCount = 0;
        while (!S.empty()) {
            if (S.top() == 'a') aCount++;
            else bCount++;
            S.pop();
        }
        xCount += min(aCount, bCount);
        return x * xCount + y * yCount;
    }
};