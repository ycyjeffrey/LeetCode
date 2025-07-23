class Solution(object):
    def maximumGain(self, s, x, y):
        xCount, yCount = 0, 0
        # Guarantee y >= x
        if x > y:
            s = s[::-1]
            x, y = y, x
        
        S = []
        aCount, bCount = 0, 0
        for c in s:
            if c != 'a' and c != 'b':
                while len(S) > 0:
                    if S[-1] == 'a':
                        aCount += 1
                    else:
                        bCount += 1
                    S.pop()
                xCount += min(aCount, bCount)
                aCount, bCount = 0, 0
            elif c == 'a' and len(S) > 0 and S[-1] == 'b':
                yCount += 1
                S.pop()
            else:
                S.append(c)
        while len(S) > 0:
            if S[-1] == 'a':
                aCount += 1
            else:
                bCount += 1
            S.pop()
        xCount += min(aCount, bCount)
        aCount, bCount = 0, 0
   
        return x * xCount + y * yCount