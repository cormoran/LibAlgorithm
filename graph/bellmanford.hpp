#pragma once

#include "./graph_type.hpp"
#include "common/simple_header.hpp"

constexpr ll INFL = 1LL << 60;

// コストが負の平路を含む場合要素ゼロで返す
// ret[i] == INFならiには到達不可
// O(VE)
vector<ll> bellmanford(const EdgeList &G, int start) {
    int N = G.size();
    vector<ll> dist(N, INFL);
    dist[start] = 0;
    rep(cnt, N) {
        bool updated = false;
        rep(i, N) {
            for (Edge e : G[i]) {
                if (dist[i] < INFL and dist[e.to] > dist[i] + e.cost) {
                    dist[e.to] = dist[i] + e.cost;
                    updated    = true;
                    if (cnt == N - 1) return {};
                }
            }
        }
        if (not updated) break;
    }
    return dist;
}
