class Solution(object):
    def generate(self, numRows):
        ret = [[1]]
        for i in range(1, numRows):
            ret.append([1])
            for j in range(1, i):
                ret[i].append(ret[i - 1][j - 1] + ret[i - 1][j])
            ret[i].append(1)
        return ret