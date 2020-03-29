#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../segtree1.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeMinimumQuery<ll, 1ll << 31> rmq(N, (1ll << 31) - 1);
    while (Q--) {
        int t;
        ll a, b;
        cin >> t >> a >> b;

        if (t == 0)
            rmq.update(a, b);
        else
            cout << rmq.query(a, b + 1) << endl;
    }
    return 0;
}