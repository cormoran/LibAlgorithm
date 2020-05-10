#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../extgcd.hpp"
#include "common/simple_header.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;

    ll x, y;
    extgcd(a, b, x, y);
    cout << x << " " << y << endl;

    return 0;
}