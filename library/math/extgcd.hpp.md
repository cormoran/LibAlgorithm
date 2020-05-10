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


# :heavy_check_mark: math/extgcd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/extgcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 01:00:03+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/math/test/extgcd.test.cpp.html">math/test/extgcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// given a, b
// set x, y such that ax + by = gcd(a, b)
// returns gcd(a, b)
template <class T = long long>
T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/extgcd.hpp"

// given a, b
// set x, y such that ax + by = gcd(a, b)
// returns gcd(a, b)
template <class T = long long>
T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

