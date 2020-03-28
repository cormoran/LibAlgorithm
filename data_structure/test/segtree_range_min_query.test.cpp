#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../segtree1.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;
    RangeMinimumQuery<ll, 10000000000ll> rmq(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << endl;
    }
    return 0;
}