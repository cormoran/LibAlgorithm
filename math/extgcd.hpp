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
