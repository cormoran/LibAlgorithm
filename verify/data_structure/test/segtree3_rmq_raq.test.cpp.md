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


# :heavy_check_mark: data_structure/test/segtree3_rmq_raq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2f0dc85cbb0980b745ae32d3fa8bfd47">data_structure/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/test/segtree3_rmq_raq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 21:00:00+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/segtree3.hpp.html">data_structure/segtree3.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp


#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../segtree3.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> init(N, 0);
    SegmentTree<RangeMinimumAndRangeAddQuery<ll, (1ll << 31) - 1>> seg(init);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.query(s, t + 1) << endl;
        }
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/test/segtree3_rmq_raq.test.cpp"


#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#line 2 "data_structure/segtree3.hpp"

#include <cassert>
#include <functional>
#include <vector>

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
#line 33 "bits/stdc++.hpp"
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
#line 68 "bits/stdc++.hpp"
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
#line 93 "bits/stdc++.hpp"

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
#line 8 "data_structure/segtree3.hpp"

template <class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    OP op;
    int n;
    vector<T> data;  // query cache
    vector<T> pool;  // update pool for lazy propagation
    SegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        pool.resize(2 * n - 1, op.update_unit());
    }
    SegmentTree(const vector<T> &vec) {
        n = 1;
        while (n < vec.size()) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        pool.resize(2 * n - 1, op.update_unit());
        rep(i, vec.size()) data[n + i - 1] = vec[i];
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }
    // a[i] = f(a[i], v) for i in [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }

  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if (out_of_range(a, b, l, r)) return;
        if (within_range(a, b, l, r)) {
            pool[i] = op.update(pool[i], v);
            data[i] = i > n - 2 ? op.query_unit() : op.query_merge(data[left_child(i)], data[right_child(i)]);  // i is leaf or not
            data[i] = op.query_apply(data[i], pool[i], l, r);
            return;
        }
        // lazy propagation
        int m = (l + r) / 2;
        update(l, m, left_child(i), l, m, pool[i]);
        update(m, r, right_child(i), m, r, pool[i]);
        pool[i] = op.update_unit();
        // new value
        update(a, b, left_child(i), l, m, v);
        update(a, b, right_child(i), m, r, v);
        data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
    }
    // index(a) の値を求める, 今node[i],
    T query(int a, int b, int i, int l, int r) {
        if (out_of_range(a, b, l, r) or (int) data.size() <= i) return op.query_unit();
        if (within_range(a, b, l, r)) return data[i];
        int m = (l + r) / 2;
        T vl  = query(a, b, left_child(i), l, m);
        T vr  = query(a, b, right_child(i), m, r);
        return op.query_apply(op.query_merge(vl, vr), pool[i], max(a, l), min(b, r));  // TODO
    }
    bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    int left_child(int i) { return i * 2 + 1; }
    int right_child(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }
};

// T update(const T &data, const T &new_data) : data[i] = update(data[i], new_value)
// T query_merge(const T &left, const T &right) : merge children's query results
// T query_apply(const T &data, const T &pool, int l, int r) : apply pool of [l, r) to the query result

template <class T1, T1 INF>
struct RangeMinimumAndRangeUpdateQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return new_data == INF ? data : new_data; }
    T query_merge(const T &left, const T &right) { return min(left, right); }
    T query_apply(const T &data, const T &pool, int l, int r) { return update(data, pool); }
    static constexpr T update_unit() { return INF; }
    static constexpr T query_unit() { return INF; }
};

template <class T1, T1 INF>
struct RangeMinimumAndRangeAddQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return data + new_data; }
    T query_merge(const T &left, const T &right) { return min(left, right); }
    T query_apply(const T &data, const T &pool, int l, int r) { return (data == INF ? 0 : data) + pool; }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit() { return INF; }
};

template <class T1>
struct RangeSumQueryAndRangeAddQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return data + new_data; }
    T query_merge(const T &left, const T &right) { return left + right; }
    T query_apply(const T &data, const T &pool, int l, int r) { return data + pool * max(r - l, 0); }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit() { return 0; }
};
template <class T1, T1 INF>
struct RangeSumQueryAndRangeUpdateQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return new_data == INF ? data : new_data; }
    T query_merge(const T &left, const T &right) { return left + right; }
    T query_apply(const T &data, const T &pool, int l, int r) { return pool == INF ? data : pool * max(r - l, 0); }
    static constexpr T update_unit() { return INF; }
    static constexpr T query_unit() { return 0; }
};
#line 7 "data_structure/test/segtree3_rmq_raq.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> init(N, 0);
    SegmentTree<RangeMinimumAndRangeAddQuery<ll, (1ll << 31) - 1>> seg(init);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.query(s, t + 1) << endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

