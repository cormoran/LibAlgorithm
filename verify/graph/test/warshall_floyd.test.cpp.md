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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/test/warshall_floyd.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cb3e5c672d961db00b76e36ddf5c068a">graph/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/test/warshall_floyd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/graph_type.hpp.html">graph/graph_type.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/warshall_floyd.hpp.html">graph/warshall_floyd.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "../warshall_floyd.hpp"
int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    rep(i, N) E[i].push_back(Edge(i, 0));
    auto dist = warshall_floyd(E);

    if (has_negative_cycle(dist)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, N) {
            rep(j, N) cout << (dist[i][j] < INFL ? to_string(dist[i][j]) : "INF") << (j == N - 1 ? "\n" : " ");
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/test/warshall_floyd.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#line 2 "graph/warshall_floyd.hpp"

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
#line 3 "graph/graph_type.hpp"

struct Edge {
    int to;
    ll cost;
    int from;  // from は使わないことも多い
    Edge(int to, ll cost, int from = -1) : to(to), cost(cost), from(from) {}
};

using EdgeList = vector<vector<Edge>>;
#line 5 "graph/warshall_floyd.hpp"

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
#line 3 "graph/test/warshall_floyd.test.cpp"
int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back(Edge(b, c));
    }
    rep(i, N) E[i].push_back(Edge(i, 0));
    auto dist = warshall_floyd(E);

    if (has_negative_cycle(dist)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, N) {
            rep(j, N) cout << (dist[i][j] < INFL ? to_string(dist[i][j]) : "INF") << (j == N - 1 ? "\n" : " ");
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

