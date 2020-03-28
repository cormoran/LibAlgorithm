#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include "../tree_diameter.hpp"

int main() {
    int N;
    cin >> N;
    EdgeList E(N);
    rep(i, N - 1) {
        int s, t, w;
        cin >> s >> t >> w;
        E[s].emplace_back(t, w);
        E[t].emplace_back(s, w);
    }
    cout << diameter(E) << endl;
    return 0;
}
