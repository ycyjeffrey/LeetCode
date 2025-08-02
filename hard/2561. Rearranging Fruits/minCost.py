class Solution(object):
    def minCost(self, basket1, basket2):
        # Sort
        basket1.sort()
        basket2.sort()

        #Delete same elements
        toSwap1 = []
        toSwap2 = []
        ptr1 = 0
        ptr2 = 0
        n = len(basket1)
        while ptr1 < n and ptr2 < n:
            if basket1[ptr1] == basket2[ptr2]:
                ptr1 += 1
                ptr2 += 1
            elif basket1[ptr1] < basket2[ptr2]:
                toSwap1.append(basket1[ptr1])
                ptr1 += 1
            else:
                toSwap2.append(basket2[ptr2])
                ptr2 += 1
        while ptr1 < n:
            toSwap1.append(basket1[ptr1])
            ptr1 += 1
        while ptr2 < n:
            toSwap2.append(basket2[ptr2])
            ptr2 += 1

        # If # of different elements are not equal, then it is not feasible
        if len(toSwap1) != len(toSwap2):
            return -1

        # If there is a different element with odd #, then it is not feasible
        if len(toSwap1) % 2 == 1:
            return -1
        m = len(toSwap1) / 2
        for i in range(0, 2 * m, 2):
            if toSwap1[i] != toSwap1[i + 1] or toSwap2[i] != toSwap2[i + 1]:
                return -1

        # Count cost
        # There are two methods to swap:
        # 1. Directly swapping a and b, which costs min(a, b)
        # 2. Using x = min(min(basket1), min(basket2)) to swap, which costs 2 * x
        x = min(min(basket1), min(basket2))
        swapCount = 0
        ptr1 = 0
        ptr2 = 0
        ret = 0
        while swapCount < m:
            if toSwap1[ptr1] < toSwap2[ptr2]:
                if 2 * x < toSwap1[ptr1]:
                    ret += 2 * x
                else:
                    ret += toSwap1[ptr1]
                ptr1 += 2
            else:
                if 2 * x < toSwap2[ptr2]:
                    ret += 2 * x
                else:
                    ret += toSwap2[ptr2]
                ptr2 += 2
            swapCount += 1

        return ret