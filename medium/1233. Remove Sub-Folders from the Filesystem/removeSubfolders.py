class Solution(object):
    def removeSubfolders(self, folder):
        folder.sort()
        ret = []
        for name in folder:
            if len(ret) == 0:
                ret.append(name)
                continue
            if not name.startswith(ret[-1] + '/'):
                ret.append(name)
        return ret