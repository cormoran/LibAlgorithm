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
