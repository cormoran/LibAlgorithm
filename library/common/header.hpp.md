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


# :warning: common/header.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#9efab2399c7c560b34de477b9aa0a465">common</a>
* <a href="{{ site.github.repository_url }}/blob/master/common/header.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Depends on

* :heavy_check_mark: <a href="../bits/stdc++.hpp.html">bits/stdc++.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef HEADER_HPP
#define HEADER_HPP

// #pragma GCC optimize ("O3")
// #pragma GCC target ("tune=native")
// #pragma GCC target ("avx")
// #pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
// #pragma GCC option("arch=native","tune=native","no-zero-upper")

#include "bits/stdc++.hpp"
using namespace std;

using ll = long long;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)
#define rrep(i, j) for (int i = (j)-1; i >= 0; i--)
#define repeapt(i, j, k) for (int i = (j); i < (int)(k); i++)
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " : " << x << endl

constexpr int INF    = 1 << 28;
constexpr ll INFL    = 1LL << 60;
constexpr double EPS = 1e-8;

template <class T>
bool set_min(T &a, const T &b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool set_max(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &a : v) is >> a;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &t : v) os << "\t" << t;
    return os << endl;
}

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "common/header.hpp"



// #pragma GCC optimize ("O3")
// #pragma GCC target ("tune=native")
// #pragma GCC target ("avx")
// #pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
// #pragma GCC option("arch=native","tune=native","no-zero-upper")

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
#line 11 "common/header.hpp"
using namespace std;

using ll = long long;
#define rep(i, j) for (int i = 0; i < (int)(j); i++)
#define rrep(i, j) for (int i = (j)-1; i >= 0; i--)
#define repeapt(i, j, k) for (int i = (j); i < (int)(k); i++)
#define all(v) v.begin(), v.end()
#define debug(x) cerr << #x << " : " << x << endl

constexpr int INF    = 1 << 28;
constexpr ll INFL    = 1LL << 60;
constexpr double EPS = 1e-8;

template <class T>
bool set_min(T &a, const T &b) {
    return a > b ? a = b, true : false;
}
template <class T>
bool set_max(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &a : v) is >> a;
    return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &t : v) os << "\t" << t;
    return os << endl;
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

