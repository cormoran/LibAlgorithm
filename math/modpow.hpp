#pragma once

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