#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include "../strongly_connected_components_ant.hpp"
#include "../strongly_connected_components_tarjan.hpp"

#define all(v) v.begin(), v.end()

struct UnionFind {
    int n;
    vector<int> p;
    UnionFind(int nn) : n(nn) {
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) p[y] = x;
    }
    bool query(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    auto scc  = strongly_connected_components_tarjan(E);
    auto scc2 = strongly_connected_components_ant(E);

    UnionFind uf(N);
    for (auto &group : scc)
        for (int v : group) uf.unite(group.front(), v);

    int Q;
    cin >> Q;
    rep(i, Q) {
        int u, v;
        cin >> u >> v;
        bool ans  = uf.query(u, v);
        bool ans2 = scc2[u] == scc2[v];
        assert(ans == ans2);
        cout << ans << endl;
    }
    return 0;
}
