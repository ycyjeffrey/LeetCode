class Solution(object):
    def getNoZeroIntegers(self, n):
        if n <= 9:
            return [1, n - 1]
        memory, n1, power = n, 0, 1
        while n > 9:
            digit = 1 if n % 10 != 1 else 2
            n1 += power * digit
            n = (n - digit) // 10
            power *= 10
        return [n1, memory - n1]