
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../segtree1.hpp"
#include "common/simple_header.hpp"
using pll    = pair<ll, ll>;
const ll MOD = 998244353;

struct Func {
    using T = pll;
    T query_merge(const T& l, const T& r) const {
        return pll((l.first * r.first) % MOD, ((r.first * l.second) % MOD + r.second) % MOD);
    }
    T update(const T& data, const T& new_data) const { return new_data; }
    static constexpr T query_unit() { return pll(1, 0); }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pll> init(N);
    rep(i, N) cin >> init[i].first >> init[i].second;
    SegmentTree<Func> seg(init);

    while (Q--) {
        ll t, a, b, c;
        cin >> t >> a >> b >> c;
        if (t == 0) {
            seg.update(a, pll(b, c));
        } else {
            auto p = seg.query(a, b);
            cout << ((p.first * c) % MOD + p.second) % MOD << endl;
        }
    }
    return 0;
}