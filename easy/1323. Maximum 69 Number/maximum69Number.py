class Solution(object):
    def maximum69Number (self, num):
        nowNum = num
        inc = 3
        retInc = 0
        while nowNum > 0:
            if nowNum % 10 == 6:
                retInc = inc
            nowNum /= 10
            inc *= 10
        return num + retInc