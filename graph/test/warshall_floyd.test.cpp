#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../warshall_floyd.hpp"
int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    rep(i, N) E[i].push_back(Edge(i, 0));
    auto dist = warshall_floyd(E);

    if (has_negative_cycle(dist)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, N) {
            rep(j, N) cout << (dist[i][j] < INFL ? to_string(dist[i][j]) : "INF") << (j == N - 1 ? "\n" : " ");
        }
    }
    return 0;
}
