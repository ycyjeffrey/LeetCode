class Basket {
public:
    int type;
    int amount;
    Basket(int type, int amount) : type(type), amount(amount) {}
    void operator=(const Basket& other) {
        if (this == &other) return;
        this->type = other.type;
        this->amount = other.amount;
        return;
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        Basket basket1(fruits[0], 1);
        int i = 1;
        while (i < fruits.size() && fruits[i] == fruits[i - 1]) {
            basket1.amount++;
            i++;
        }

        if (i == fruits.size()) return basket1.amount;
        Basket basket2(fruits[i], 1);
        i++;

        Basket consecutive(basket2.type, basket2.amount);
        int ret = INT_MIN;
        while (i < fruits.size()) {
            // Update basket1/2 by fruits[i]
            if (fruits[i] == basket1.type)
                basket1.amount++;
            else if (fruits[i] == basket2.type)
                basket2.amount++;
            else {
                // Put previous consecutive type into basket1 and put fruits[i] into basket2
                ret = max(ret, basket1.amount + basket2.amount);
                basket1 = consecutive;
                basket2 = Basket(fruits[i], 1);
            }

            // Update consecutive
            if (fruits[i] == consecutive.type)
                consecutive.amount++;
            else
                consecutive = Basket(fruits[i], 1);
            
            // Update index
            i++;
        }
        ret = max(ret, basket1.amount + basket2.amount);
        return ret;
    }
};