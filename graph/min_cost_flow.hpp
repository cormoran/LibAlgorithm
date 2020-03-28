#pragma once

#include "common/simple_header.hpp"

struct Edge {
    int to;
    ll capacity, cost, rev;
};

constexpr ll INFL = 1LL << 60;

struct Flow {
    int N;
    vector<vector<Edge>> E;

    Flow(int n) : N(n) { E.resize(N); }
    void add_arc(int from, int to, ll cap, ll cost = 0) {
        E[from].push_back(
            Edge{to, cap, cost,
                 (ll)E[to].size()});                                    // E[to].size() は下で追加する逆辺
        E[to].push_back(Edge{from, 0, -cost, (ll)E[from].size() - 1});  // 逆辺
    }
    // s -> t に f だけ流す時の最小費用を計算，流せない時 - 1
    // O(F|V||E|)
    // 流すとグラフが壊れる
    ll min_cost_flow(int s, int t, ll f) {
        vector<int> prev_v(N), prev_e(N);

        auto bellmanford = [&](int s) {
            vector<ll> dist(N, INFL);
            dist[s]      = 0;
            bool updated = true;
            while (updated) {
                updated = false;
                rep(v, N) {
                    if (dist[v] >= INFL) continue;
                    rep(i, E[v].size()) {
                        auto &e = E[v][i];
                        if (e.capacity > 0 and dist[e.to] > dist[v] + e.cost) {
                            dist[e.to]   = dist[v] + e.cost;
                            prev_v[e.to] = v;
                            prev_e[e.to] = i;
                            updated      = true;
                        }
                    }
                }
            }
            return dist;
        };

        ll res = 0;
        while (f > 0) {
            auto dist = bellmanford(s);
            if (dist[t] == INFL) return -1;
            ll d = f;
            // s -> t の最小コスト経路上の，最小容量 d を求める
            for (int v = t; v != s; v = prev_v[v]) {
                d = min(d, E[prev_v[v]][prev_e[v]].capacity);
            }
            // d だけ流す
            for (int v = t; v != s; v = prev_v[v]) {
                auto &e = E[prev_v[v]][prev_e[v]];
                e.capacity -= d;
                E[v][e.rev].capacity += d;
            }
            f -= d;
            res += d * dist[t];  // 流した費用
        }
        return res;
    }
};
