#pragma once
#include "common/simple_header.hpp"
using EdgeList = vector<vector<int>>;

struct LowestCommonAncestor {
    vector<vector<int>> parent;  // [i][j] : 頂点jの2^i上の親
    EdgeList E;
    vector<int> depth;
    int N, log2N;

    LowestCommonAncestor(const EdgeList &E) : E(E) {
        N     = E.size();
        log2N = floor(log2(N) + 1);
        depth.resize(N, -1);
        parent.resize(log2N, vector<int>(N, -1));
        calc_depth();
        doubling();
    }
    // a, b の lca を計算
    int query(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);
        rep(i, log2N) {
            if (((depth[b] - depth[a]) >> i) & 1) b = parent[i][b];
            if (a == b)
                return a;
            else {
                for (int i = log2N - 1; i >= 0; i--) {
                    if (parent[i][a] != parent[i][b]) {
                        a = parent[i][a];
                        b = parent[i][b];
                    }
                }
                return parent[0][a];
            }
        }
        assert(0);
    }

  private:
    // now を根とする木の深さを計算
    void calc_depth(int now = 0, int pre = -1, int dep = 0) {
        parent[0][now] = pre;
        depth[now]     = dep;
        for (int nxt : E[now]) {
            if (nxt == pre) continue;
            calc_depth(nxt, now, dep + 1);
        }
    }
    void doubling() {
        rep(i, log2N - 1) {
            rep(j, N) {
                if (parent[i][j] >= 0)
                    parent[i + i][j] = parent[i][parent[i][j]];
                else
                    parent[i + 1][j] = -1;
            }
        }
    }
};
