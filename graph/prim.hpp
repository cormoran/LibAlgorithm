#pragma once
#include "./graph_type.hpp"
#include "common/simple_header.hpp"
constexpr ll INFL = 1LL << 60;

bool operator<(Edge a, Edge b) { return a.cost < b.cost; }
bool operator>(Edge a, Edge b) { return a.cost > b.cost; }

// 連結無向グラフ E の最小全域木をプリム法求める
// O(ElogV)
vector<Edge> prim(const EdgeList &E) {
    int N = E.size(), start = 0;
    vector<Edge> ans;

    priority_queue<Edge, vector<Edge>, greater<Edge>> que;
    vector<bool> visited(N);
    int visited_num = 0;
    que.emplace(start, 0);

    while (visited_num < N and not que.empty()) {
        Edge now = que.top();
        que.pop();
        if (visited[now.to]) continue;
        visited[now.to] = true;
        visited_num++;
        ans.push_back(now);
        for (Edge e : E[now.to]) {
            if (not visited[e.to]) {
                que.emplace(e.to, e.cost);
            }
        }
    }
    assert(visited_num == N);  // 連結チェック
    return ans;
}