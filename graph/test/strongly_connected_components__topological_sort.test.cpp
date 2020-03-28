#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "../strongly_connected_components_ant.hpp"
#include "../strongly_connected_components_tarjan.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    auto scc1 = strongly_connected_components_tarjan(E);
    reverse(begin(scc1), end(scc1));
    vector<int> ans1;
    {
        for (vector<int> g : scc1) {
            sort(begin(g), end(g));
            for (int a : g) ans1.push_back(a);
        }
    }
    auto scc2 = strongly_connected_components_ant(E);
    vector<int> ans2(N);
    {
        vector<pair<int, int>> P(N);
        rep(i, N) P[i] = make_pair(scc2[i], i);
        sort(begin(P), end(P));
        rep(i, N) ans2[i] = P[i].second;
    }
    assert(ans1 == ans2);
    for (int a : ans1) cout << a << endl;
    return 0;
}
