#pragma once
#include "./graph_type.hpp"
#include "common/simple_header.hpp"
constexpr ll INFL = 1LL << 60;

bool operator<(Edge a, Edge b) { return a.cost < b.cost; }
bool operator>(Edge a, Edge b) { return a.cost > b.cost; }

struct UnionFind {
    int n;
    vector<int> p;
    UnionFind(int nn) : n(nn) {
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) { return p[x] == x ? x : (p[x] = root(p[x])); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) p[y] = x;
    }
    bool query(int x, int y) { return root(x) == root(y); }
};

// 連結無向グラフ E の最小全域木をクラスカル法で求める
// 非連結グラフの場合は最小連結森が求まる
// O(ElogV)
vector<Edge> kruskal(const EdgeList &E) {
    vector<Edge> edges;
    rep(i, E.size()) for (auto &e : E[i])
        edges.push_back(Edge(e.to, e.cost, i));
    sort(begin(edges), end(edges));

    vector<Edge> ans;
    UnionFind uf(E.size());
    for (auto &e : edges) {
        if (not uf.query(e.from, e.to)) {
            ans.push_back(e);
            uf.unite(e.from, e.to);
        }
    }
    return ans;
}