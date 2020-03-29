

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../segtree3.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<RangeMinimumAndRangeUpdateQuery<ll, (1ll << 31) - 1>> seg(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.query(s, t + 1) << endl;
        }
    }
    return 0;
}