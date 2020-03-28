#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include "../bridge_and_articulation.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    auto ans = enumerate_bridges(E);
    sort(begin(ans), end(ans));
    for (pii p : ans) cout << p.first << " " << p.second << endl;
    return 0;
}
