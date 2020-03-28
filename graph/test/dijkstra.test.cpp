#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../dijkstra.hpp"
int main() {
    int N, M, R;
    cin >> N >> M >> R;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    auto dist = dijkstra(E, R);
    for (ll d : dist) cout << (d < INFL ? to_string(d) : "INF") << endl;
    return 0;
}
