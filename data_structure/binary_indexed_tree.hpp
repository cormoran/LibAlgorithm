#pragma once
#include <cassert>
#include <vector>

#include "common/simple_header.hpp"
// 1-based index!
template <typename T>
struct BinaryIndexedTree {
    vector<T> data;
    int n;
    BinaryIndexedTree(size_t n) : n(n) {
        data.resize(n + 1, 0);
    }
    BinaryIndexedTree(const vector<T> &A) {
        n = A.size();
        data.resize(n + 1, 0);
        for (int i = 0; i < n; i++) update(i, A[i]);
    }
    // array[k] += val
    void update(int i, T val) {
        assert(0 <= i and i < n);
        for (; i < n + 1; i |= i + 1) data[i] += val;
    }
    // sum [0...i)
    T query(int i) const {
        assert(0 <= i and i <= n);
        T s = 0;
        for (--i; i >= 0; i = (i & (i + 1)) - 1) s += data[i];
        return s;
    }
    // sum [i, j)
    T query(int i, int j) const {
        assert(0 <= i and i < j and j <= n);
        return query(j) - query(i);
    }
};

template <class T>
using FenwickTree = BinaryIndexedTree<T>;
template <class T>
using RangeSumQuery = BinaryIndexedTree<T>;