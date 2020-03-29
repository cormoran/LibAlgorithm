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
template <class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    const OP op;
    int n;
    vector<T> data;
    SegmentTree(int nn, T init) : n(1), op() {
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        fill(begin(data) + n - 1, end(data), init);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    SegmentTree(vector<T> init) : n(1), op() {
        int nn = init.size();
        while (n < nn) n *= 2;
        data.resize(2 * n - 1, op.query_unit());
        copy(begin(init), end(init), begin(data) + n - 1);
        for (int i = n - 2; i >= 0; i--) {
            data[i] = op.query_merge(data[left_child(i)], data[right_child(i)]);
        }
    }
    //index k in [0, n) の値を val に更新
    void update(int k, T val) {
        assert(0 <= k and k < n);
        k += n - 1;
        data[k] = op.update(data[k], val);
        while (k > 0) {
            k       = parent(k);
            data[k] = op.query_merge(data[left_child(k)], data[right_child(k)]);
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
        if (out_of_range(a, b, l, r)) return op.query_unit();
        if (within_range(a, b, l, r))
            return data[now];
        else {  // cross range
            T vleft  = query(a, b, left_child(now), l, (l + r) / 2);
            T vright = query(a, b, right_child(now), (l + r) / 2, r);
            return op.query_merge(vleft, vright);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

// -----------------------------------------------------------------------

template <class T1, T1 INF>
struct RangeMinimumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return min(left, right); }
    T update(const T& data, const T& new_data) const { return new_data == INF ? data : new_data; }
    static constexpr T query_unit() { return INF; }
};
template <class T, T INF>
using RangeMinimumQuery = SegmentTree<RangeMinimumQueryF<T, INF>>;

template <class T1, T1 MINF>
struct RangeMaximumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return max(left, right); }
    T update(const T& data, const T& new_data) const { return new_data == MINF ? data : new_data; }
    static constexpr T query_unit() { return MINF; }
};
template <class T, T MINF>
using RangeMaximumQuery = SegmentTree<RangeMaximumQueryF<T, MINF>>;

template <class T1, T1 ZERO>
struct RangeSumQueryF {
    using T = T1;
    T query_merge(const T& left, const T& right) const { return left + right; }
    T update(const T& data, const T& new_data) const { return data + new_data; }
    static constexpr T query_unit() { return ZERO; }
};
template <class T, T ZERO>
using RangeSumQuery = SegmentTree<RangeSumQueryF<T, ZERO>>;

// template<class T, T ZERO>
// using RangeSumQuery = SegmentTree<T, plus<T>, OverWrite<T>, ZERO, ZERO>; // update は overwrite
