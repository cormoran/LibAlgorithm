#pragma once
#include "common/simple_header.hpp"
using EdgeList = vector<vector<int>>;
using pii      = pair<int, int>;

// 非連結を含む，グラフ E の橋を列挙
// O(N + M) N: 頂点数, M: 辺数
vector<pii> enumerate_bridges(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    vector<pii> bridges;
    function<void(int, int)> dfs = [&](int now, int pre) {
        ord[now] = cnt++;
        low[now] = ord[now];
        for (int nxt : E[now]) {
            if (ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
                if (ord[now] < low[nxt]) {
                    bridges.emplace_back(min(now, nxt), max(now, nxt));
                }
            } else if (nxt != pre) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            }
        }
    };
    // 連結グラフならdfs(0)だけでOKなはず
    rep(i, N) if (ord[i] < 0) dfs(i, -1);
    return bridges;
}

// 非連結を含む，グラフ E の関節点（切断点）を列挙
// O(N + M) N: 頂点数, M: 辺数
vector<int> enumerate_articulations(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    vector<int> articulations;
    function<void(int, int)> dfs = [&](int now, int pre) {
        ord[now] = cnt++;
        low[now] = ord[now];

        bool is_articulation = false;
        int dfs_children     = 0;

        for (int nxt : E[now]) {
            if (ord[nxt] < 0) {
                // not visited
                dfs_children++;
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
                if (pre >= 0 and ord[now] <= low[nxt]) {
                    is_articulation = true;
                }
            } else if (nxt != pre) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            }
        }
        if (pre < 0 and dfs_children > 1) is_articulation = true;
        if (is_articulation) articulations.push_back(now);
    };
    // 連結グラフならdfs(0)だけでOKなはず
    rep(i, N) if (ord[i] < 0) dfs(i, -1);
    return articulations;
}
