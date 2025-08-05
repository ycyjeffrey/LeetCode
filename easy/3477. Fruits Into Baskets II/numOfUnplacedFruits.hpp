class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        bitset<100> available;
        int ret = fruits.size();
        for (int i = 0; i < fruits.size(); i++) {
            for (int j = 0; j < baskets.size(); j++) {
                if (available[j] == 0 && baskets[j] >= fruits[i]) {
                    available.set(j);
                    ret--;
                    break;
                }
            }
        }
        return ret;
    }
};