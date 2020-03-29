

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../segtree2.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeAddQuery<ll, 0ll> ruq(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            ruq.update(s - 1, t, x);
        } else {
            int i;
            cin >> i;
            cout << ruq.query(i - 1) << endl;
        }
    }
    return 0;
}