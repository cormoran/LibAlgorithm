

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../segtree3.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<RangeSumQueryAndRangeAddQuery<ll>> seg(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            seg.update(s - 1, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.query(s - 1, t) << endl;
        }
    }
    return 0;
}