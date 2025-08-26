class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        diagSq, area = -1, -1
        for rec in dimensions:
            nowDiagSq = rec[0] * rec[0] + rec[1] * rec[1]
            if nowDiagSq > diagSq:
                diagSq, area = nowDiagSq, rec[0] * rec[1]
            elif nowDiagSq == diagSq:
                area = max(area, rec[0] * rec[1])
        return area