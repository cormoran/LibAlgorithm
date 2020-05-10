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
