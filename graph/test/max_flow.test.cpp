#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../max_flow.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    Flow f(V);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        f.add_arc(u, v, c);
    }
    Flow f2 = f;
    ll a    = f.ford_fulkerson(0, V - 1);
    ll b    = f2.dinic(0, V - 1);
    assert(a == b);
    cout << a << endl;
    return 0;
}
