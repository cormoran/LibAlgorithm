#pragma once

#include "./graph_type.hpp"
#include "common/simple_header.hpp"

constexpr ll INFL = 1LL << 60;

// O(V^3)
vector<vector<ll>> warshall_floyd(const EdgeList &G) {
    int N = G.size();
    vector<vector<ll>> dist(N, vector<ll>(N, INFL));
    rep(i, N) for (const Edge &e : G[i]) dist[i][e.to] = e.cost;
    rep(k, N) rep(i, N) rep(j, N) if (dist[i][k] < INFL and dist[k][j] < INFL)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

// warshall floydの結果から，負閉路検出
bool has_negative_cycle(vector<vector<ll>> &dist) {
    rep(i, dist.size()) if (dist[i][i] < 0) return true;
    return false;
}
