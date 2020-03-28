#pragma once

#include "./graph_type.hpp"
#include "common/simple_header.hpp"

constexpr ll INFL = 1LL << 60;

struct State {
    int index;
    ll cost;
    State(int i, ll c) : index(i), cost(c) {}
    bool operator>(const State &r) const { return cost > r.cost; }
};

// O(ElogV)
vector<ll> dijkstra(const EdgeList &G, int start) {
    priority_queue<State, vector<State>, greater<State>> que;
    vector<ll> dist(G.size(), INFL);
    que.emplace(start, 0);
    dist[start] = 0;
    while (not que.empty()) {
        State now = que.top();
        que.pop();
        for (Edge e : G[now.index]) {
            if (dist[e.to] > now.cost + e.cost) {
                State nxt  = State(e.to, now.cost + e.cost);
                dist[e.to] = nxt.cost;
                que.push(nxt);
            }
        }
    }
    return dist;
}
