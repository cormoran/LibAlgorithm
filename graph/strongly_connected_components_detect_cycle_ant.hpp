#pragma once
#include "./strongly_connected_components_ant.hpp"
#include "common/simple_header.hpp"

// 有向グラフに閉路があるかどうかを判定
bool detect_cycle_ant(const EdgeList &E) {
    auto scc = strongly_connected_components_ant(E);
    set<int> found;
    for (int v : scc) {
        if (found.count(v)) return true;
        found.insert(v);
    }
    return false;
}
