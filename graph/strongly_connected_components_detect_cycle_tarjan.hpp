#pragma once
#include "./strongly_connected_components_tarjan.hpp"
#include "common/simple_header.hpp"

// 有向グラフに閉路があるかどうかを判定
bool detect_cycle_tarjan(const EdgeList &E) {
    auto scc = strongly_connected_components_tarjan(E);
    bool res = false;
    for (auto &g : scc) res |= g.size() > 1;
    return res;
}