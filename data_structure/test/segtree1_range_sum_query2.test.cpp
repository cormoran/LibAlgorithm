

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../segtree1.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeSumQuery<ll, 0ll> rsq(N, 0);

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0)
            rsq.update(a - 1, b);
        else
            cout << rsq.query(a - 1, b) << endl;
    }
    return 0;
}