#define ll long long

class FenwickTree {
public:
    vector<ll> BIT;
    int n;
    FenwickTree(int size) {
        n = size;
        BIT.resize(size + 1, 0);
    }

    void update(int idx, ll val) {
        idx++;
        while (idx <= n) {
            BIT[idx] += val;
            idx += idx & (-idx);
        }
    }

    ll query(int idx) {
        idx++;
        ll sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

    ll rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = pos[nums1[i]];
        }

        FenwickTree left(n), right(n);
        vector<int> freq(n, 1);
        for (int val : mapped) {
            right.update(val, 1);
        }

        ll ans = 0;
        for (int j = 0; j < n; ++j) {

            int idx = mapped[j];
            right.update(idx, -1);

            ll leftCount = left.query(idx - 1);
            ll rightCount = right.query(n - 1) - right.query(idx);

            ans += leftCount * rightCount;

            left.update(idx, 1);
        }

        return ans;
    }
};
