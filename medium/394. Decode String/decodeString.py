class Solution(object):
    def decodeString(self, s):
        S = []
        i = 0
        ret = ''
        while i < len(s):
            if s[i].isdigit():
                S.append([0, ''])
                while s[i].isdigit():
                    S[-1][0] = 10 * S[-1][0] + int(s[i])
                    i += 1
                i += 1
                while s[i].isalpha():
                    S[-1][1] += s[i]
                    i += 1
            elif s[i].isalpha():
                if len(S) != 0:
                    S[-1][1] += s[i]
                else:
                    ret += s[i]
                i += 1
            else: # s[i] == ']'
                freq = S[-1][0]
                str = S[-1][1]
                S.pop()
                if len(S) != 0:
                    for j in range(freq):
                        S[-1][1] += str
                else:
                    for j in range(freq):
                        ret += str
                i += 1
        return ret