#pragma once
#include <vector>
using namespace std;

#include <algorithm>
#include <cassert>
#include <functional>
/*^ingore^*/

// T           : データ型
// QueryFunc   : 演算子
// UpdateFunc  : (以前の値, 適用する値) => 新しい値
// query_unit  : QueryFuncの単位元
template <class T, class QueryFunc, class UpdateFunc, T query_unit>
class SegmentTree {
  public:
    int n;
    vector<T> data;
    QueryFunc qf;
    UpdateFunc uf;
    SegmentTree(int nn, T init) : n(1) {
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, query_unit);
        fill(begin(data) + n - 1, end(data), init);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = qf(data[left_child(i)], data[right_child(i)]);
        }
    }
    SegmentTree(vector<T> init) : n(1) {
        int nn = init.size();
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, query_unit);
        copy(begin(init), end(init), begin(data) + n - 1);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = qf(data[left_child(i)], data[right_child(i)]);
        }
    }
    //index k in [0, n) の値を val に更新
    void update(int k, T val) {
        assert(0 <= k and k < n);
        k += n - 1;
        data[k] = uf(data[k], val);
        while (k > 0) {
            k       = parent(k);
            data[k] = qf(data[left_child(k)], data[right_child(k)]);
        }
    }
    T query(int a) const {
        return query(a, a + 1);
    }
    // [a, b)
    T query(int a, int b) const {
        assert(0 <= a and a < b and b <= n);
        return query(a, b, 0, 0, n);
    }

  private:
    //[a, b) のクエリ, nowは今の場所, [l,r)は見ている場所
    T query(int a, int b, int now, int l, int r) const {
        if (out_of_range(a, b, l, r)) return query_unit;
        if (within_range(a, b, l, r))
            return data[now];
        else {  // cross range
            T vleft  = query(a, b, left_child(now), l, (l + r) / 2);
            T vright = query(a, b, right_child(now), (l + r) / 2, r);
            return qf(vleft, vright);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

// -----------------------------------------------------------------------

template <class T>
struct Min {
    T operator()(const T& x, const T& y) const { return min(x, y); }
};
template <class T>
struct Max {
    T operator()(const T& x, const T& y) const { return max(x, y); }
};
template <class T>
struct OverWrite {
    T operator()(const T& x, const T& y) const { return y; }
};

template <class T, T INF>
using RangeMinimumQuery = SegmentTree<T, Min<T>, OverWrite<T>, INF>;

template <class T, T MINF>
using RangeMaximumQuery = SegmentTree<T, Max<T>, OverWrite<T>, MINF>;

template <class T, T ZERO>
using RangeSumQuery = SegmentTree<T, plus<T>, plus<T>, ZERO>;  // update を add とした実装

// template<class T, T ZERO>
// using RangeSumQuery = SegmentTree<T, plus<T>, OverWrite<T>, ZERO, ZERO>; // update は overwrite
