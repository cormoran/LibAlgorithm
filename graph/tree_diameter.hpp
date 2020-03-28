#pragma once

#include "./graph_type.hpp"
#include "common/simple_header.hpp"
using pil = pair<int, ll>;

// 木 E の直径を求める
// 適当な点からの最遠点をu，uからの最遠点をtとすると，u-tが直径
// O(E)
ll diameter(const EdgeList &E) {
    // now からの最遠点を求めるDFS
    // -> (点, nowからの距離)
    function<pil(int, int)> dfs = [&](int now, int pre) {
        pil res = make_pair(now, 0);
        for (auto &e : E[now]) {
            if (e.to == pre) continue;
            pil tmp = dfs(e.to, now);
            tmp.second += e.cost;
            if (tmp.second > res.second) res = tmp;
        }
        return res;
    };
    pil a = dfs(0, -1);
    pil b = dfs(a.first, -1);
    // (a.first , b.first) が最遠点対
    return b.second;
}
