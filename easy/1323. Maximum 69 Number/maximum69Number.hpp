class Solution {
public:
    int maximum69Number (int num) {
        int nowNum = num;
        int inc = 3;
        int retInc = 0;
        while (nowNum> 0) {
            if (nowNum % 10 == 6)
                retInc = inc;
            nowNum /= 10;
            inc *= 10;
        }
        return num + retInc;
    }
};