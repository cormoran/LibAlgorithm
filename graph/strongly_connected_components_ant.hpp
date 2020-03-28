#pragma once
#include "common/simple_header.hpp"
using EdgeList = vector<vector<int>>;

// 有向グラフ E を強連結成分に分解(蟻本)
// O(N + M) N: 頂点数, M: 辺数
// -> トポロジカル順序（順序が同じものは同じ強連結成分）0 が root
vector<int> strongly_connected_components_ant(const EdgeList &E) {
    int N = E.size();
    EdgeList rE(N);
    rep(i, N) for (int nxt : E[i]) rE[nxt].push_back(i);  // 逆辺
    vector<char> used(N);
    vector<int> vs;  // DFS帰りがけ順
    vector<int> topological_no(N);
    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (int nxt : E[v])
            if (not used[nxt]) dfs(nxt);
        vs.push_back(v);
    };
    function<void(int, int)> rdfs = [&](int v, int k) {
        topological_no[v] = k;
        used[v]           = true;
        for (int nxt : rE[v])
            if (not used[nxt]) rdfs(nxt, k);
    };
    rep(v, N) if (not used[v]) dfs(v);
    fill(begin(used), end(used), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
        if (not used[vs[i]]) rdfs(vs[i], k++);
    return topological_no;
}

// 2-satを解く
// N: 変数の数 max(x), cnf : (x1 => x2) AND (-x1 => x2) AND ... ,  -x means !x
// need -N <= xi <= N, xi != 0
vector<bool> two_satisfiability(int N, vector<pair<int, int>> formula) {
    EdgeList E((N + 1) * 2);
    rep(i, formula.size()) {
        int a = formula[i].first, b = formula[i].second;
        cerr << "(" << a << ", " << b << ")" << endl;
        assert(a != 0 and b != 0 and abs(a) <= N and abs(b) <= N);
        E[a + N].push_back(b + N);
    }
    auto scc = strongly_connected_components_ant(E);
    vector<bool> is_true(N + 1);
    for (int i = 1; i <= N; i++) {
        if (scc[i + N] == scc[-i + N]) return {};  // not satisfiable
        is_true[i] = scc[i + N] > scc[-i + N];
        cerr << is_true[i] << " @ ";
    }
    cerr << endl;
    return is_true;
}

// cnf を 2satを解くための形に変形
// @warning 動作未検証!!!!
vector<pair<int, int>> cnf_to_impl(const vector<pair<int, int>> &cnf) {
    vector<pair<int, int>>
        impl;  // (x1 => x2) AND (-x1 =>> x3) AND ... な論理式
    rep(i, cnf.size()) {
        int a = cnf[i].first, b = cnf[i].second;
        assert(a != 0 and b != 0);
        impl.emplace_back(-a, b);  // !a => b
        impl.emplace_back(-b, a);  // !b => a
    }
    return impl;
}
