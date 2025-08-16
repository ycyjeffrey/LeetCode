class Solution(object):
    def largestGoodInteger(self, num):
        ret = -1
        for i in range(2, len(num)):
            if num[i] == num[i - 1] and num[i - 1] == num[i - 2] and ord(num[i]) > ret:
                ret = ord(num[i]);
        if ret == -1:
            return ""
        return chr(ret) * 3