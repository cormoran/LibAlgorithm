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


# :warning: math/mint.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/mint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-11 01:00:03+09:00




## Depends on

* :heavy_check_mark: <a href="modpow.hpp.html">math/modpow.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <iostream>

#include "./modpow.hpp"
// #define MINT_SAFE_NEGATIVE
// #define MINT_USE_EXTGCD

template <class T = long long, T mod = 1000000007>
class mint {
  public:
    T x;
#ifdef MINT_SAFE_NEGATIVE
    constexpr mint(T a = 0) : x(((a % mod) + mod) % mod) {}  // allow a < 0
#else
    constexpr mint(T a = 0) : x(a % mod) {}  // assumes a >= 0, faster
#endif
    constexpr T &value() { return x; }
    constexpr const T &value() const { return x; }
    constexpr mint operator+(const mint &l) const { return mint(*this) += l; }
    constexpr mint operator-(const mint &l) const { return mint(*this) -= l; }
    constexpr mint operator*(const mint &l) const { return mint(*this) *= l; }
    constexpr mint operator/(const mint &l) const { return mint(*this) /= l; }

    constexpr mint &operator+=(const mint &l) {
        x += l.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &l) {
        x -= l.x;
        if (x < 0) x += mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &l) {
        x = (x * l.x) % mod;
        return *this;
    }
    constexpr mint &operator/=(const mint &l) {
        x = (x * l.inverse().x) % mod;
        return *this;
    }
#ifndef MINT_USE_EXTGCD
    constexpr mint inverse() const {
        return pow(mod - 2);
    }
#else
    // by extgcd
    constexpr mint inverse() const {
        T a = x, b = mod, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
#endif
    constexpr mint pow(T r) const {
        return modpow<T>(x, r, mod);
    }
};

namespace std {

template <class T, T mod>
ostream &operator<<(std::ostream &os, const mint<T, mod> &a) {
    os << a.x;
    return os;
}
template <class T, T mod>
istream &operator>>(std::istream &is, mint<T, mod> &a) {
    is >> a.x;
    return is;
}

}  // namespace std

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/mint.hpp"

#include <iostream>

#line 2 "math/modpow.hpp"

// calculate (x ** r) % mod
template <class T = long long>
constexpr T modpow(T x, T r, T mod) {
    x     = ((x % mod) + mod) % mod;
    T res = 1;
    while (r > 0) {
        if (r & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        r >>= 1;
    }
    return res;
}
#line 6 "math/mint.hpp"
// #define MINT_SAFE_NEGATIVE
// #define MINT_USE_EXTGCD

template <class T = long long, T mod = 1000000007>
class mint {
  public:
    T x;
#ifdef MINT_SAFE_NEGATIVE
    constexpr mint(T a = 0) : x(((a % mod) + mod) % mod) {}  // allow a < 0
#else
    constexpr mint(T a = 0) : x(a % mod) {}  // assumes a >= 0, faster
#endif
    constexpr T &value() { return x; }
    constexpr const T &value() const { return x; }
    constexpr mint operator+(const mint &l) const { return mint(*this) += l; }
    constexpr mint operator-(const mint &l) const { return mint(*this) -= l; }
    constexpr mint operator*(const mint &l) const { return mint(*this) *= l; }
    constexpr mint operator/(const mint &l) const { return mint(*this) /= l; }

    constexpr mint &operator+=(const mint &l) {
        x += l.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    constexpr mint &operator-=(const mint &l) {
        x -= l.x;
        if (x < 0) x += mod;
        return *this;
    }
    constexpr mint &operator*=(const mint &l) {
        x = (x * l.x) % mod;
        return *this;
    }
    constexpr mint &operator/=(const mint &l) {
        x = (x * l.inverse().x) % mod;
        return *this;
    }
#ifndef MINT_USE_EXTGCD
    constexpr mint inverse() const {
        return pow(mod - 2);
    }
#else
    // by extgcd
    constexpr mint inverse() const {
        T a = x, b = mod, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
#endif
    constexpr mint pow(T r) const {
        return modpow<T>(x, r, mod);
    }
};

namespace std {

template <class T, T mod>
ostream &operator<<(std::ostream &os, const mint<T, mod> &a) {
    os << a.x;
    return os;
}
template <class T, T mod>
istream &operator>>(std::istream &is, mint<T, mod> &a) {
    is >> a.x;
    return is;
}

}  // namespace std

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

