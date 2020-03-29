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


# :heavy_check_mark: data_structure/test/segtree2_range_add_query.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2f0dc85cbb0980b745ae32d3fa8bfd47">data_structure/test</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/test/segtree2_range_add_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 21:00:00+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bits/stdc++.hpp.html">bits/stdc++.hpp</a>
* :heavy_check_mark: <a href="../../../library/common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../../../library/data_structure/segtree2.hpp.html">data_structure/segtree2.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp


#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../segtree2.hpp"
#include "common/simple_header.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeAddQuery<ll, 0ll> ruq(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            ruq.update(s - 1, t, x);
        } else {
            int i;
            cin >> i;
            cout << ruq.query(i - 1) << endl;
        }
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/test/segtree2_range_add_query.test.cpp"


#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#line 2 "data_structure/segtree2.hpp"

#include <cassert>
#include <vector>
using namespace std;

#include <functional>
/*^ingore^*/

// T           : データ型
// UpdateFunc  : (以前の値, 適用する値) => 新しい値 結合性必要
// update_unit : UpdateFuncの単位元 (= 配列の初期値)
template <class T, class UpdateFunc, T update_unit>
class SegmentTree {
  public:
    int depth;
    int n;
    vector<T> data;
    UpdateFunc uf;
    SegmentTree(int n_) : depth(0) {
        while ((1 << depth) < n_) depth++;
        n = 1 << depth;  // 2^depth
        data.resize((1 << (depth + 1)) - 1, update_unit);
    }
    SegmentTree(vector<T> init) : depth(0) {
        while ((1 << depth) < init.size()) depth++;
        n = 1 << depth;  // 2^depth
        data.resize((1 << (depth + 1)) - 1, update_unit);
        copy(begin(init), end(init), begin(data) + leaf(0));
    }
    // get value of index(i)
    T query(int i) {
        assert(0 <= i and i < n);
        i     = leaf(i);
        T res = data[i];
        if (i == 0) return res;
        do {
            i   = parent(i);
            res = uf(res, data[i]);
        } while (i > 0);
        return res;
    }
    // apply f(_, v) to [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }

  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if (out_of_range(a, b, l, r)) return;
        if (within_range(a, b, l, r))
            data[i] = uf(data[i], v);
        else {
            // 遅延伝搬させる
            int m = (l + r) / 2;
            if (data[i] != update_unit) {
                update(l, r, left_child(i), l, m, data[i]);
                update(l, r, right_child(i), m, r, data[i]);
                data[i] = update_unit;
            }
            update(a, b, left_child(i), l, m, v);
            update(a, b, right_child(i), m, r, v);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
    int leaf(int i) { return i + (1 << depth) - 1; }
};

template <class T, T INIT>
struct OverWrite {
    T operator()(const T& x, const T& y) const { return y == INIT ? x : y; }
};

template <class T, T INIT>
using RangeUpdateQuery = SegmentTree<T, OverWrite<T, INIT>, INIT>;

template <class T, T INIT>
using RangeAddQuery = SegmentTree<T, plus<T>, INIT>;
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
#line 7 "data_structure/test/segtree2_range_add_query.test.cpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    RangeAddQuery<ll, 0ll> ruq(N);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            ruq.update(s - 1, t, x);
        } else {
            int i;
            cin >> i;
            cout << ruq.query(i - 1) << endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

