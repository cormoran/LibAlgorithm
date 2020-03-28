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


# :heavy_check_mark: data_structure/test/union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2f0dc85cbb0980b745ae32d3fa8bfd47">data_structure/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/test/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:27:33+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/union_find.hpp.html">data_structure/union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../union_find.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            uf.unite(u, v);
        else
            cout << (uf.query(u, v) ? 1 : 0) << endl;
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/test/union_find.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

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
#line 3 "data_structure/union_find.hpp"

// 0 to n-1 でも1 to nでもOK
struct UnionFind {
    int n;
    vector<int> p;
    UnionFind(int nn) {
        n = nn + 1;  // 1-based safe
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) { return p[x] == x ? x : (p[x] = root(p[x])); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) p[y] = x;
    }
    bool query(int x, int y) { return root(x) == root(y); }
    map<int, vector<int>> get_group() {
        map<int, vector<int>> res;
        rep(i, p.size()) { res[root(i)].push_back(i); }
        return res;
    }
};

//
struct UnionFindWithSize {
    int n;
    vector<int> p;
    vector<int> size;
    UnionFindWithSize(int nn) {
        n = nn + 1;  // 1-based safe
        p.resize(n);
        size.resize(n);
        rep(i, n) p[i]    = i;
        rep(i, n) size[i] = 1;
    }
    int root(int x) { return p[x] == x ? x : (p[x] = root(p[x])); }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            p[y] = x;
            size[x] += size[y];
        }
    }
    bool query(int x, int y) { return root(x) == root(y); }
    int query_size(int x) { return size[root(x)]; }
};
#line 4 "data_structure/test/union_find.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            uf.unite(u, v);
        else
            cout << (uf.query(u, v) ? 1 : 0) << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

