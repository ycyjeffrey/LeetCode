class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        available = [True] * len(fruits)
        ret = len(fruits)
        for i in range(len(fruits)):
            for j in range(len(baskets)):
                if available[j] and baskets[j] >= fruits[i]:
                    available[j] = False
                    ret -= 1
                    break
        return ret