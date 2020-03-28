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


# :heavy_check_mark: graph/test/max_flow.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cb3e5c672d961db00b76e36ddf5c068a">graph/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/test/max_flow.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/max_flow.hpp.html">graph/max_flow.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../max_flow.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    Flow f(V);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        f.add_arc(u, v, c);
    }
    Flow f2 = f;
    ll a    = f.ford_fulkerson(0, V - 1);
    ll b    = f2.dinic(0, V - 1);
    assert(a == b);
    cout << a << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/test/max_flow.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#line 2 "graph/max_flow.hpp"

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
#line 4 "graph/max_flow.hpp"

struct Edge {
    int to;
    ll cap, rev;
};

constexpr ll INFL = 1LL << 60;

struct Flow {
    int N;
    vector<vector<Edge>> E;

    Flow(int n) : N(n) { E.resize(N); }
    void add_arc(int from, int to, ll cap) {
        E[from].push_back(Edge{
            to, cap, (ll)E[to].size()});                         // E[to].size() は下で追加する逆辺
        E[to].push_back(Edge{from, 0, (ll)E[from].size() - 1});  // 逆辺
    }
    // s -> t の 最大流を求める
    // bad O(F|E|)
    // 流すとグラフが壊れる
    ll ford_fulkerson(int s, int t) {
        vector<char> used(N);
        function<ll(int, int, ll)> dfs = [&](int v, int t, ll f) {
            if (v == t) return f;
            used[v] = true;
            for (auto &e : E[v]) {
                if (not used[e.to] and e.cap > 0) {
                    ll d = dfs(e.to, t, min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        E[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return (ll)0;
        };
        ll flow = 0;
        for (;;) {
            fill(begin(used), end(used), false);
            ll f = dfs(s, t, INFL);
            if (f == 0) return flow;
            flow += f;
        }
    }
    // s -> t の 最大流を求める
    // bad O(|E||V|^2)
    // 流すとグラフが壊れる
    ll dinic(int s, int t) {
        vector<int> depth(N, -1), iter(N, 0);
        auto bfs =
            [&](int s) {  // s からの距離を，すべての辺のコスト=1として計算
                fill(begin(depth), end(depth), -1);
                queue<int> que;
                depth[s] = 0;
                que.push(s);
                while (que.size()) {
                    int v = que.front();
                    que.pop();
                    for (auto &e : E[v]) {
                        if (e.cap > 0 and
                            depth[e.to] < 0) {  // cap > 0 and not visited then
                            depth[e.to] = depth[v] + 1;
                            que.push(e.to);
                        }
                    }
                }
                return depth;
            };
        function<ll(int, int, ll)> dfs = [&](int v, int t,
                                             ll f) {  // 増加パスを見つける
            if (v == t) return f;
            for (int &i = iter[v]; i < E[v].size(); i++) {
                Edge &e = E[v][i];
                if (e.cap > 0 and depth[v] < depth[e.to]) {
                    ll d = dfs(e.to, t, min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        E[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return (ll)0;
        };
        ll flow = 0;
        for (;;) {
            bfs(s);
            if (depth[t] < 0) return flow;
            fill(begin(iter), end(iter), 0);
            ll f;
            while ((f = dfs(s, t, INFL)) > 0) flow += f;
        }
    }
};
#line 3 "graph/test/max_flow.test.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    Flow f(V);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        f.add_arc(u, v, c);
    }
    Flow f2 = f;
    ll a    = f.ford_fulkerson(0, V - 1);
    ll b    = f2.dinic(0, V - 1);
    assert(a == b);
    cout << a << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

