#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../modpow.hpp"
#include "common/simple_header.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M, N;
    cin >> M >> N;

    cout << modpow(M, N, 1000000007ll) << endl;

    return 0;
}