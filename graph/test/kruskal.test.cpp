#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../kruskal.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
        E[b].push_back(Edge(a, c));
    }
    auto mst = kruskal(E);
    ll ans   = 0;
    for (auto &e : mst) ans += e.cost;
    cout << ans << endl;
    return 0;
}
