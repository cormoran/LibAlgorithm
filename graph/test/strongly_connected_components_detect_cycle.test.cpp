#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include "../strongly_connected_components_detect_cycle_ant.hpp"
#include "../strongly_connected_components_detect_cycle_tarjan.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    assert(detect_cycle_tarjan(E) == detect_cycle_ant(E));
    cout << (detect_cycle_tarjan(E) ? 1 : 0) << endl;
    return 0;
}
