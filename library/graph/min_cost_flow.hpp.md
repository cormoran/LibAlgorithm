---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/min_cost_flow.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/min_cost_flow.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Depends on

* :heavy_check_mark: <a href="../bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../common/simple_header.hpp.html">common/simple_header.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/test/min_cost_flow.test.cpp.html">graph/test/min_cost_flow.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/min_cost_flow.hpp"

#line 2 "common/simple_header.hpp"

#line 1 "bits/stdc++.hpp"
// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2018 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#include <cassert>
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
#include <cstdio>
#include <cstdlib>
//#include <cstring>
#include <ctime>

#include <ccomplex>
// #include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
// #include <ctgmath>
// #include <cuchar>
// #include <cwchar>
// #include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#line 4 "common/simple_header.hpp"
using namespace std;
using ll = long long;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)
constexpr int INF = 1 << 28;
#line 4 "graph/min_cost_flow.hpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

