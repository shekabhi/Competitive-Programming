// Binary Indexed Tree (Fenwik Tree)
// 0 based indexing

struct BIT {
    vector<int> bit;  
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0ll);
    }

    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int get(int idx) { //
        int ret = 0;
        for (++idx; idx > 0ll; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};
