class Solution(object):
    def totalFruit(self, fruits):
        type1 = 0
        type2 = 0
        while type2 + 1 < len(fruits) and fruits[type2] == fruits[type2 + 1]:
            type2 += 1
        if (type2 + 1 == len(fruits)):
            return type2 - type1 + 1
        type2 += 1

        ptr = type2
        consecutive = type2
        ret = -1
        while ptr < len(fruits):
            if fruits[ptr] == fruits[type1] or fruits[ptr] == fruits[type2]:
                ptr += 1
            else:
                ret = max(ret, ptr - type1)
                type1 = consecutive
                type2 = ptr
            if ptr < len(fruits) and fruits[ptr] != fruits[consecutive]:
                consecutive = ptr
        ret = max(ret, ptr - type1)
        return ret