#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include "../min_cost_flow.hpp"

int main() {
    int V, E, F;
    cin >> V >> E >> F;
    Flow f(V);
    rep(i, E) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        f.add_arc(u, v, c, d);
    }
    cout << f.min_cost_flow(0, V - 1, F) << endl;
    return 0;
}
