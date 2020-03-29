

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../segtree2.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeUpdateQuery<ll, (1ll << 31) - 1> ruq(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            ruq.update(s, t + 1, x);
        } else {
            int i;
            cin >> i;
            cout << ruq.query(i) << endl;
        }
    }
    return 0;
}