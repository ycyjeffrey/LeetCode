class Solution(object):
    def makeFancyString(self, s):
        if len(s) <= 2:
            return s
        ret = s[0:2]
        count = 2
        for i in range(2, len(s)):
            if s[i] == ret[count - 1] and ret[count - 1] == ret[count - 2]:
                continue
            else:
                ret += s[i]
                count += 1
        return ret