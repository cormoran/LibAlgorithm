#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
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
    auto ans = enumerate_articulations(E);
    sort(begin(ans), end(ans));
    for (int a : ans) cout << a << endl;
    return 0;
}
