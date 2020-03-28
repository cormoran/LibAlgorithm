#pragma once
#include "common/simple_header.hpp"
using EdgeList = vector<vector<int>>;

// 非連結を含む，グラフ E を強連結成分に分解(Tarjan's algorithm)
// O(N + M) N: 頂点数, M: 辺数
// -> 強連結成分ごとのグループ
// グループはトポロジカル順序の逆順（のはず）http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A&lang=jp
// でチェック
vector<vector<int>> strongly_connected_components_tarjan(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    stack<int> stk;
    vector<bool> on_stack(N);
    vector<vector<int>> scc;
    function<void(int, int)> dfs = [&](int now, int pre) {
        stk.push(now);
        on_stack[now] = true;
        ord[now]      = cnt++;
        low[now]      = ord[now];
        for (int nxt : E[now]) {
            if (ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
            } else if (on_stack[nxt]) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            }
        }
        if (ord[now] == low[now]) {
            scc.push_back({});
            while (true) {
                int v = stk.top();
                stk.pop();
                scc.back().push_back(v);
                on_stack[v] = false;
                if (v == now) break;
            }
        }
    };
    // 連結グラフならdfs(0)だけでOK
    rep(i, N) if (ord[i] < 0) dfs(i, -1);
    return scc;
}