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


# :heavy_check_mark: graph/graph_type.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_type.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Depends on

* :heavy_check_mark: <a href="../bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../common/simple_header.hpp.html">common/simple_header.hpp</a>


## Required by

* :heavy_check_mark: <a href="bellmanford.hpp.html">graph/bellmanford.hpp</a>
* :heavy_check_mark: <a href="dijkstra.hpp.html">graph/dijkstra.hpp</a>
* :heavy_check_mark: <a href="kruskal.hpp.html">graph/kruskal.hpp</a>
* :heavy_check_mark: <a href="prim.hpp.html">graph/prim.hpp</a>
* :heavy_check_mark: <a href="tree_diameter.hpp.html">graph/tree_diameter.hpp</a>
* :heavy_check_mark: <a href="warshall_floyd.hpp.html">graph/warshall_floyd.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/graph/test/bellmanford.test.cpp.html">graph/test/bellmanford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/dijkstra.test.cpp.html">graph/test/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/kruskal.test.cpp.html">graph/test/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/prim.test.cpp.html">graph/test/prim.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/tree__diameter.test.cpp.html">graph/test/tree__diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/warshall_floyd.test.cpp.html">graph/test/warshall_floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "common/simple_header.hpp"

struct Edge {
    int to;
    ll cost;
    int from;  // from は使わないことも多い
    Edge(int to, ll cost, int from = -1) : to(to), cost(cost), from(from) {}
};

using EdgeList = vector<vector<Edge>>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

