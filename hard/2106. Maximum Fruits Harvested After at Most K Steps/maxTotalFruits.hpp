class Solution {
private:
    int binSearch1(vector<vector<int>>& fruits, int key) {
        // Guarantee: key <= fruits[-1][0]
        int l = 0, r = fruits.size() - 1;
        if (key <= fruits[l][0]) return l;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (fruits[m][0] >= key) r = m;
            else l = m;
        }
        return r;
    }
    int binSearch2(vector<vector<int>>& fruits, int key) {
        // Guarantee: key >= fruits[0][0]
        int l = 0, r = fruits.size() - 1;
        if (key >= fruits[r][0]) return r;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (fruits[m][0] > key) r = m;
            else l = m;
        }
        return l;
    }
    int countAmount(vector<vector<int>>& fruits, int lKey, int rKey) {
        // Find the smallest pos >= lKey and the largest pos <= rKey
        // Use the indices to return the amount
        int n = fruits.size();
        if (rKey < fruits[0][0] || lKey > fruits[n - 1][0]) return 0;
        int l = binSearch1(fruits, lKey);
        int r = binSearch2(fruits, rKey);
        if (l == 0) return fruits[r][1];
        return fruits[r][1] - fruits[l - 1][1];
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        // Approach: Traverse all possible routes
        // ( <- , -> ) = (k, 0), (k - 2, 1), (k - 4, 2),..., (2, k - 2), (0, k)
        // That is, determine a sliding window and use binSearch and prefix sum to count
        for (int i = 1; i < n; i++)
            fruits[i][1] += fruits[i - 1][1];
        
        int ret = INT_MIN;
        for (int i = 0; i <= k / 2; i++) {
            int l = startPos - (k - 2 * i);
            int r = startPos + i;
            ret = max(ret, countAmount(fruits, l, r));
        }
        for (int i = 0; i <= k / 2; i++) {
            int l = startPos - i;
            int r = startPos + (k - 2 * i);
            ret = max(ret, countAmount(fruits, l, r));
        }

        return ret;
    }
};