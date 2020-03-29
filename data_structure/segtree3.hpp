#pragma once

#include <cassert>
#include <functional>
#include <vector>

#include "common/simple_header.hpp"

template <class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    OP op;
    int n;
    vector<T> data;  // query cache
    vector<T> pool;  // update pool for lazy propagation
    SegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        pool.resize(2 * n - 1, op.update_unit());
    }
    SegmentTree(const vector<T> &vec) {
        n = 1;
        while (n < vec.size()) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        pool.resize(2 * n - 1, op.update_unit());
        rep(i, vec.size()) data[n + i - 1] = vec[i];
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    // [a, b)
    T query(int a, int b) {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }
    // a[i] = f(a[i], v) for i in [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }

  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if (out_of_range(a, b, l, r)) return;
        if (within_range(a, b, l, r)) {
            pool[i] = op.update(pool[i], v);
            data[i] = i > n - 2 ? op.query_unit() : op.query_merge(data[left_child(i)], data[right_child(i)]);  // i is leaf or not
            data[i] = op.query_apply(data[i], pool[i], l, r);
            return;
        }
        // lazy propagation
        int m = (l + r) / 2;
        update(l, m, left_child(i), l, m, pool[i]);
        update(m, r, right_child(i), m, r, pool[i]);
        pool[i] = op.update_unit();
        // new value
        update(a, b, left_child(i), l, m, v);
        update(a, b, right_child(i), m, r, v);
        data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
    }
    // index(a) の値を求める, 今node[i],
    T query(int a, int b, int i, int l, int r) {
        if (out_of_range(a, b, l, r) or (int) data.size() <= i) return op.query_unit();
        if (within_range(a, b, l, r)) return data[i];
        int m = (l + r) / 2;
        T vl  = query(a, b, left_child(i), l, m);
        T vr  = query(a, b, right_child(i), m, r);
        return op.query_apply(op.query_merge(vl, vr), pool[i], max(a, l), min(b, r));  // TODO
    }
    bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    int left_child(int i) { return i * 2 + 1; }
    int right_child(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }
};

// T update(const T &data, const T &new_data) : data[i] = update(data[i], new_value)
// T query_merge(const T &left, const T &right) : merge children's query results
// T query_apply(const T &data, const T &pool, int l, int r) : apply pool of [l, r) to the query result

template <class T1, T1 INF>
struct RangeMinimumAndRangeUpdateQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return new_data == INF ? data : new_data; }
    T query_merge(const T &left, const T &right) { return min(left, right); }
    T query_apply(const T &data, const T &pool, int l, int r) { return update(data, pool); }
    static constexpr T update_unit() { return INF; }
    static constexpr T query_unit() { return INF; }
};

template <class T1, T1 INF>
struct RangeMinimumAndRangeAddQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return data + new_data; }
    T query_merge(const T &left, const T &right) { return min(left, right); }
    T query_apply(const T &data, const T &pool, int l, int r) { return (data == INF ? 0 : data) + pool; }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit() { return INF; }
};

template <class T1>
struct RangeSumQueryAndRangeAddQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return data + new_data; }
    T query_merge(const T &left, const T &right) { return left + right; }
    T query_apply(const T &data, const T &pool, int l, int r) { return data + pool * max(r - l, 0); }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit() { return 0; }
};
template <class T1, T1 INF>
struct RangeSumQueryAndRangeUpdateQuery {
    using T = T1;
    T update(const T &data, const T &new_data) { return new_data == INF ? data : new_data; }
    T query_merge(const T &left, const T &right) { return left + right; }
    T query_apply(const T &data, const T &pool, int l, int r) { return pool == INF ? data : pool * max(r - l, 0); }
    static constexpr T update_unit() { return INF; }
    static constexpr T query_unit() { return 0; }
};