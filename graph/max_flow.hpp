#pragma once

#include "common/simple_header.hpp"

struct Edge {
    int to;
    ll cap, rev;
};

constexpr ll INFL = 1LL << 60;

struct Flow {
    int N;
    vector<vector<Edge>> E;

    Flow(int n) : N(n) { E.resize(N); }
    void add_arc(int from, int to, ll cap) {
        E[from].push_back(Edge{
            to, cap, (ll)E[to].size()});                         // E[to].size() は下で追加する逆辺
        E[to].push_back(Edge{from, 0, (ll)E[from].size() - 1});  // 逆辺
    }
    // s -> t の 最大流を求める
    // bad O(F|E|)
    // 流すとグラフが壊れる
    ll ford_fulkerson(int s, int t) {
        vector<char> used(N);
        function<ll(int, int, ll)> dfs = [&](int v, int t, ll f) {
            if (v == t) return f;
            used[v] = true;
            for (auto &e : E[v]) {
                if (not used[e.to] and e.cap > 0) {
                    ll d = dfs(e.to, t, min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        E[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return (ll)0;
        };
        ll flow = 0;
        for (;;) {
            fill(begin(used), end(used), false);
            ll f = dfs(s, t, INFL);
            if (f == 0) return flow;
            flow += f;
        }
    }
    // s -> t の 最大流を求める
    // bad O(|E||V|^2)
    // 流すとグラフが壊れる
    ll dinic(int s, int t) {
        vector<int> depth(N, -1), iter(N, 0);
        auto bfs =
            [&](int s) {  // s からの距離を，すべての辺のコスト=1として計算
                fill(begin(depth), end(depth), -1);
                queue<int> que;
                depth[s] = 0;
                que.push(s);
                while (que.size()) {
                    int v = que.front();
                    que.pop();
                    for (auto &e : E[v]) {
                        if (e.cap > 0 and
                            depth[e.to] < 0) {  // cap > 0 and not visited then
                            depth[e.to] = depth[v] + 1;
                            que.push(e.to);
                        }
                    }
                }
                return depth;
            };
        function<ll(int, int, ll)> dfs = [&](int v, int t,
                                             ll f) {  // 増加パスを見つける
            if (v == t) return f;
            for (int &i = iter[v]; i < E[v].size(); i++) {
                Edge &e = E[v][i];
                if (e.cap > 0 and depth[v] < depth[e.to]) {
                    ll d = dfs(e.to, t, min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        E[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return (ll)0;
        };
        ll flow = 0;
        for (;;) {
            bfs(s);
            if (depth[t] < 0) return flow;
            fill(begin(iter), end(iter), 0);
            ll f;
            while ((f = dfs(s, t, INFL)) > 0) flow += f;
        }
    }
};
