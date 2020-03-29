

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../binary_indexed_tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;
    BinaryIndexedTree<ll> rsq(A);

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0)
            rsq.update(a, b);
        else
            cout << rsq.query(a, b) << endl;
    }
    return 0;
}