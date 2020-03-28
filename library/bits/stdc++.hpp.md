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


# :heavy_check_mark: bits/stdc++.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cc411e6c13670e52124629b8ac83f7d0">bits</a>
* <a href="{{ site.github.repository_url }}/blob/master/bits/stdc++.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Required by

* :warning: <a href="../common/header.hpp.html">common/header.hpp</a>
* :heavy_check_mark: <a href="../common/simple_header.hpp.html">common/simple_header.hpp</a>
* :heavy_check_mark: <a href="../data_structure/union_find.hpp.html">data_structure/union_find.hpp</a>
* :heavy_check_mark: <a href="../graph/bellmanford.hpp.html">graph/bellmanford.hpp</a>
* :heavy_check_mark: <a href="../graph/bridge_and_articulation.hpp.html">graph/bridge_and_articulation.hpp</a>
* :heavy_check_mark: <a href="../graph/dijkstra.hpp.html">graph/dijkstra.hpp</a>
* :heavy_check_mark: <a href="../graph/graph_type.hpp.html">graph/graph_type.hpp</a>
* :heavy_check_mark: <a href="../graph/kruskal.hpp.html">graph/kruskal.hpp</a>
* :warning: <a href="../graph/lowest_common_ancestor.hpp.html">graph/lowest_common_ancestor.hpp</a>
* :heavy_check_mark: <a href="../graph/max_flow.hpp.html">graph/max_flow.hpp</a>
* :heavy_check_mark: <a href="../graph/min_cost_flow.hpp.html">graph/min_cost_flow.hpp</a>
* :heavy_check_mark: <a href="../graph/prim.hpp.html">graph/prim.hpp</a>
* :heavy_check_mark: <a href="../graph/strongly_connected_components_ant.hpp.html">graph/strongly_connected_components_ant.hpp</a>
* :heavy_check_mark: <a href="../graph/strongly_connected_components_detect_cycle_ant.hpp.html">graph/strongly_connected_components_detect_cycle_ant.hpp</a>
* :heavy_check_mark: <a href="../graph/strongly_connected_components_detect_cycle_tarjan.hpp.html">graph/strongly_connected_components_detect_cycle_tarjan.hpp</a>
* :heavy_check_mark: <a href="../graph/strongly_connected_components_tarjan.hpp.html">graph/strongly_connected_components_tarjan.hpp</a>
* :heavy_check_mark: <a href="../graph/tree_diameter.hpp.html">graph/tree_diameter.hpp</a>
* :warning: <a href="../graph/two_sat.hpp.html">graph/two_sat.hpp</a>
* :heavy_check_mark: <a href="../graph/warshall_floyd.hpp.html">graph/warshall_floyd.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/data_structure/test/segtree_range_min_query.test.cpp.html">data_structure/test/segtree_range_min_query.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/test/segtree_range_sum_query.test.cpp.html">data_structure/test/segtree_range_sum_query.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/data_structure/test/union_find.test.cpp.html">data_structure/test/union_find.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/bellmanford.test.cpp.html">graph/test/bellmanford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/bridge_and_articulation__articulation.test.cpp.html">graph/test/bridge_and_articulation__articulation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/bridge_and_articulation__bridge.test.cpp.html">graph/test/bridge_and_articulation__bridge.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/dijkstra.test.cpp.html">graph/test/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/kruskal.test.cpp.html">graph/test/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/max_flow.test.cpp.html">graph/test/max_flow.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/min_cost_flow.test.cpp.html">graph/test/min_cost_flow.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/prim.test.cpp.html">graph/test/prim.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/strongly_connected_components.test.cpp.html">graph/test/strongly_connected_components.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/strongly_connected_components__topological_sort.test.cpp.html">graph/test/strongly_connected_components__topological_sort.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/strongly_connected_components_detect_cycle.test.cpp.html">graph/test/strongly_connected_components_detect_cycle.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/tree__diameter.test.cpp.html">graph/test/tree__diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/graph/test/warshall_floyd.test.cpp.html">graph/test/warshall_floyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

