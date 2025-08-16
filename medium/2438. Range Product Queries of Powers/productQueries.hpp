#define p 1000000007
class SegTree {
private:
    vector<long long> tree;
    vector<int> arr;
    int n;

    int left(const int& node) { return 2 * node + 1; }
    int right(const int& node) { return 2 * node + 2; }
    int mid(const int& l, const int& r) { return l + (r - l) / 2; }

    void build(const int& node, const int& start, const int& end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int m = mid(start, end);
        build(left(node), start, m);
        build(right(node), m + 1, end);
        tree[node] = (tree[left(node)] * tree[right(node)]) % p;
        return;
    }
    void update(const int& node, const int& start, const int& end, const int& idx, const int& val) {
        if (start == end) {
            tree[node] = val;
            arr[idx] = val;
            return;
        }
        int m = mid(start, end);
        update(left(node), start, m, idx, val);
        update(right(node), m + 1, end, idx, val);
        tree[node] = (tree[left(node)] * tree[right(node)]) % p;
        return;
    }
    long long query(const int& node, const int& start, const int& end, const int& l, const int& r) {
        if (start >= l && end <= r)
            return tree[node];
        if (end < l || start > r)
            return 1;
        int m = mid(start, end);
        long long L = query(left(node), start, m, l, r);
        long long R = query(right(node), m + 1, end, l, r);
        return (L * R) % p;
    }

public:
    SegTree(vector<int>& a) : arr(a), n(a.size()) {
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    
    void update(const int& idx, const int& val) {
        update(0, 0, n - 1, idx, val);
        return;
    }
    long long query(const int& l, const int& r) {
        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> arr;
        int power = 1;
        while (n > 0) {
            if (n % 2 == 1)
                arr.push_back(power);
            n /= 2;
            power *= 2;
        }
        SegTree tree(arr);
        vector<int> answers;
        for (auto& v : queries)
            answers.push_back(tree.query(v[0], v[1]));
        return answers;
    }
};