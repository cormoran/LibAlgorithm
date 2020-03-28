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


# :heavy_check_mark: graph/test/strongly_connected_components__topological_sort.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cb3e5c672d961db00b76e36ddf5c068a">graph/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/test/strongly_connected_components__topological_sort.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/strongly_connected_components_ant.hpp.html">graph/strongly_connected_components_ant.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/strongly_connected_components_tarjan.hpp.html">graph/strongly_connected_components_tarjan.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include "../strongly_connected_components_ant.hpp"
#include "../strongly_connected_components_tarjan.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    auto scc1 = strongly_connected_components_tarjan(E);
    reverse(begin(scc1), end(scc1));
    vector<int> ans1;
    {
        for (vector<int> g : scc1) {
            sort(begin(g), end(g));
            for (int a : g) ans1.push_back(a);
        }
    }
    auto scc2 = strongly_connected_components_ant(E);
    vector<int> ans2(N);
    {
        vector<pair<int, int>> P(N);
        rep(i, N) P[i] = make_pair(scc2[i], i);
        sort(begin(P), end(P));
        rep(i, N) ans2[i] = P[i].second;
    }
    assert(ans1 == ans2);
    for (int a : ans1) cout << a << endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/test/strongly_connected_components__topological_sort.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
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
#line 3 "graph/strongly_connected_components_ant.hpp"
using EdgeList = vector<vector<int>>;

// 有向グラフ E を強連結成分に分解(蟻本)
// O(N + M) N: 頂点数, M: 辺数
// -> トポロジカル順序（順序が同じものは同じ強連結成分）0 が root
vector<int> strongly_connected_components_ant(const EdgeList &E) {
    int N = E.size();
    EdgeList rE(N);
    rep(i, N) for (int nxt : E[i]) rE[nxt].push_back(i);  // 逆辺
    vector<char> used(N);
    vector<int> vs;  // DFS帰りがけ順
    vector<int> topological_no(N);
    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (int nxt : E[v])
            if (not used[nxt]) dfs(nxt);
        vs.push_back(v);
    };
    function<void(int, int)> rdfs = [&](int v, int k) {
        topological_no[v] = k;
        used[v]           = true;
        for (int nxt : rE[v])
            if (not used[nxt]) rdfs(nxt, k);
    };
    rep(v, N) if (not used[v]) dfs(v);
    fill(begin(used), end(used), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
        if (not used[vs[i]]) rdfs(vs[i], k++);
    return topological_no;
}

// 2-satを解く
// N: 変数の数 max(x), cnf : (x1 => x2) AND (-x1 => x2) AND ... ,  -x means !x
// need -N <= xi <= N, xi != 0
vector<bool> two_satisfiability(int N, vector<pair<int, int>> formula) {
    EdgeList E((N + 1) * 2);
    rep(i, formula.size()) {
        int a = formula[i].first, b = formula[i].second;
        cerr << "(" << a << ", " << b << ")" << endl;
        assert(a != 0 and b != 0 and abs(a) <= N and abs(b) <= N);
        E[a + N].push_back(b + N);
    }
    auto scc = strongly_connected_components_ant(E);
    vector<bool> is_true(N + 1);
    for (int i = 1; i <= N; i++) {
        if (scc[i + N] == scc[-i + N]) return {};  // not satisfiable
        is_true[i] = scc[i + N] > scc[-i + N];
        cerr << is_true[i] << " @ ";
    }
    cerr << endl;
    return is_true;
}

// cnf を 2satを解くための形に変形
// @warning 動作未検証!!!!
vector<pair<int, int>> cnf_to_impl(const vector<pair<int, int>> &cnf) {
    vector<pair<int, int>>
        impl;  // (x1 => x2) AND (-x1 =>> x3) AND ... な論理式
    rep(i, cnf.size()) {
        int a = cnf[i].first, b = cnf[i].second;
        assert(a != 0 and b != 0);
        impl.emplace_back(-a, b);  // !a => b
        impl.emplace_back(-b, a);  // !b => a
    }
    return impl;
}
#line 3 "graph/strongly_connected_components_tarjan.hpp"
using EdgeList = vector<vector<int>>;

// 非連結を含む，グラフ E を強連結成分に分解(Tarjan's algorithm)
// O(N + M) N: 頂点数, M: 辺数
// -> 強連結成分ごとのグループ
// グループはトポロジカル順序の逆順（のはず）http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A&lang=jp
// でチェック
vector<vector<int>> strongly_connected_components_tarjan(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    stack<int> stk;
    vector<bool> on_stack(N);
    vector<vector<int>> scc;
    function<void(int, int)> dfs = [&](int now, int pre) {
        stk.push(now);
        on_stack[now] = true;
        ord[now]      = cnt++;
        low[now]      = ord[now];
        for (int nxt : E[now]) {
            if (ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
            } else if (on_stack[nxt]) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            }
        }
        if (ord[now] == low[now]) {
            scc.push_back({});
            while (true) {
                int v = stk.top();
                stk.pop();
                scc.back().push_back(v);
                on_stack[v] = false;
                if (v == now) break;
            }
        }
    };
    // 連結グラフならdfs(0)だけでOK
    rep(i, N) if (ord[i] < 0) dfs(i, -1);
    return scc;
}
#line 4 "graph/test/strongly_connected_components__topological_sort.test.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    EdgeList E(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    auto scc1 = strongly_connected_components_tarjan(E);
    reverse(begin(scc1), end(scc1));
    vector<int> ans1;
    {
        for (vector<int> g : scc1) {
            sort(begin(g), end(g));
            for (int a : g) ans1.push_back(a);
        }
    }
    auto scc2 = strongly_connected_components_ant(E);
    vector<int> ans2(N);
    {
        vector<pair<int, int>> P(N);
        rep(i, N) P[i] = make_pair(scc2[i], i);
        sort(begin(P), end(P));
        rep(i, N) ans2[i] = P[i].second;
    }
    assert(ans1 == ans2);
    for (int a : ans1) cout << a << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

