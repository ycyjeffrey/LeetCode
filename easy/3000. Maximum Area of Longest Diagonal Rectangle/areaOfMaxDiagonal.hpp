class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int diagSq = INT_MIN;
        int area = INT_MIN;
        for (auto& rec : dimensions) {
            int nowDiagSq = rec[0] * rec[0] + rec[1] * rec[1];
            if (nowDiagSq > diagSq) {
                diagSq = nowDiagSq;
                area = rec[0] * rec[1];
            } else if (nowDiagSq == diagSq)
                area = max(area, rec[0] * rec[1]);
        }
        return area;
    }
};