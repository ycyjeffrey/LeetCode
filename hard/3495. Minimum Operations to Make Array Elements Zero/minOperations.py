class Solution(object):
    power, prefix = [0] * 20, [0] * 19
    def init(self):
        self.power[0] = 1
        for i in range(1, len(self.power)):
            self.power[i] = self.power[i - 1] * 4
        self.prefix[0] = 3
        for i in range(1, len(self.prefix)):
            self.prefix[i] = self.prefix[i - 1] + (i + 1) * (self.power[i + 1] - self.power[i])
    def log4(self, x):
        if x <= 3:
            return 0
        return self.log4(x // 4) + 1
    def query(self, l, r):
        a, b = self.log4(l), self.log4(r)
        if b == 0:
            return (r - l + 2) // 2
        return (self.prefix[b - 1] - self.prefix[a] + (a + 1) * (self.power[a + 1] - l) + (b + 1) * (r - self.power[b] + 1) + 1) // 2
    def minOperations(self, queries):
        self.init()
        ret = 0
        for q in queries:
            ret += self.query(q[0], q[1])
        return ret