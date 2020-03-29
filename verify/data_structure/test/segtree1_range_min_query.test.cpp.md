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


# :heavy_check_mark: data_structure/test/segtree1_range_min_query.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2f0dc85cbb0980b745ae32d3fa8bfd47">data_structure/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/test/segtree1_range_min_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 21:47:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/segtree1.hpp.html">data_structure/segtree1.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../segtree1.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;
    RangeMinimumQuery<ll, 10000000000ll> rmq(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << endl;
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/test/segtree1_range_min_query.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#line 2 "data_structure/segtree1.hpp"
#include <vector>
using namespace std;

#include <algorithm>
#include <cassert>
#include <functional>
/*^ingore^*/

// T           : データ型
// QueryFunc   : 演算子
// UpdateFunc  : (以前の値, 適用する値) => 新しい値
// query_unit  : QueryFuncの単位元
template <class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    const OP op;
    int n;
    vector<T> data;
    SegmentTree(int nn, T init) : n(1), op() {
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        fill(begin(data) + n - 1, end(data), init);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    SegmentTree(vector<T> init) : n(1), op() {
        int nn = init.size();
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        copy(begin(init), end(init), begin(data) + n - 1);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    //index k in [0, n) の値を val に更新
    void update(int k, T val) {
        assert(0 <= k and k < n);
        k += n - 1;
        data[k] = op.update(data[k], val);
        while (k > 0) {
            k       = parent(k);
            data[k] = op.query_merge(data[left_child(k)], data[right_child(k)]);
        }
    }
    T query(int a) const {
        return query(a, a + 1);
    }
    // [a, b)
    T query(int a, int b) const {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }

  private:
    //[a, b) のクエリ, nowは今の場所, [l,r)は見ている場所
    T query(int a, int b, int now, int l, int r) const {
        if (out_of_range(a, b, l, r)) return op.query_unit();
        if (within_range(a, b, l, r))
            return data[now];
        else {  // cross range
            T vleft  = query(a, b, left_child(now), l, (l + r) / 2);
            T vright = query(a, b, right_child(now), (l + r) / 2, r);
            return op.query_merge(vleft, vright);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

// -----------------------------------------------------------------------

template <class T1, T1 INF>
struct RangeMinimumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return min(left, right); }
    T update(const T& data, const T& new_data) const { return new_data == INF ? data : new_data; }
    static constexpr T query_unit() { return INF; }
};
template <class T, T INF>
using RangeMinimumQuery = SegmentTree<RangeMinimumQueryF<T, INF>>;

template <class T1, T1 MINF>
struct RangeMaximumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return max(left, right); }
    T update(const T& data, const T& new_data) const { return new_data == MINF ? data : new_data; }
    static constexpr T query_unit() { return MINF; }
};
template <class T, T MINF>
using RangeMaximumQuery = SegmentTree<RangeMaximumQueryF<T, MINF>>;

template <class T1, T1 ZERO>
struct RangeSumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return left + right; }
    T update(const T& data, const T& new_data) const { return data + new_data; }
    static constexpr T query_unit() { return ZERO; }
};
template <class T, T ZERO>
using RangeSumQuery = SegmentTree<RangeSumQueryF<T, ZERO>>;

// template<class T, T ZERO>
// using RangeSumQuery = SegmentTree<T, plus<T>, OverWrite<T>, ZERO, ZERO>; // update は overwrite
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
#line 62 "bits/stdc++.hpp"
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
#line 5 "data_structure/test/segtree1_range_min_query.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;
    RangeMinimumQuery<ll, 10000000000ll> rmq(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

