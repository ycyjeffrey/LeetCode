// Let N = folder.size(), L = max{folder[i].length(): 0 <= i < N}
// This solution has O(NLlog(N)) time complexity, which is slower then using trie (O(NL)).
// But this solution is more concise.

class Solution {
private:
    bool startswith(string a, string b) {
        if (a.length() >= b.length()) return false;
        a += '/';
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ret;
        int count = -1;
        // b starts with (a + '/') <=> b is a subfolder of a
        for (auto& name : folder) {
            if (count == -1) {
                ret.push_back(name);
                count++;
                continue;
            }
            if (!startswith(ret[count], name)) {
                ret.push_back(name);
                count++;
            }
        }
        return ret;
    }
};