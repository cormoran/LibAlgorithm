#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include <functional>
/*^ingore^*/

// T           : データ型
// UpdateFunc  : (以前の値, 適用する値) => 新しい値 結合性必要
// update_unit : UpdateFuncの単位元 (= 配列の初期値)
template <class T, class UpdateFunc, T update_unit>
class SegmentTree {
  public:
    int depth;
    int n;
    vector<T> data;
    UpdateFunc uf;
    SegmentTree(int n_) : depth(0) {
        while ((1 << depth) < n_) depth++;
        n = 1 << depth;  // 2^depth
        data.resize((1 << (depth + 1)) - 1, update_unit);
    }
    SegmentTree(vector<T> init) : depth(0) {
        while ((1 << depth) < init.size()) depth++;
        n = 1 << depth;  // 2^depth
        data.resize((1 << (depth + 1)) - 1, update_unit);
        copy(begin(init), end(init), begin(data) + leaf(0));
    }
    // get value of index(i)
    T query(int i) {
        assert(0 <= i and i < n);
        i     = leaf(i);
        T res = data[i];
        if (i == 0) return res;
        do {
            i   = parent(i);
            res = uf(res, data[i]);
        } while (i > 0);
        return res;
    }
    // apply f(_, v) to [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }

  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if (out_of_range(a, b, l, r)) return;
        if (within_range(a, b, l, r))
            data[i] = uf(data[i], v);
        else {
            // 遅延伝搬させる
            int m = (l + r) / 2;
            if (data[i] != update_unit) {
                update(l, r, left_child(i), l, m, data[i]);
                update(l, r, right_child(i), m, r, data[i]);
                data[i] = update_unit;
            }
            update(a, b, left_child(i), l, m, v);
            update(a, b, right_child(i), m, r, v);
        }
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
    int leaf(int i) { return i + (1 << depth) - 1; }
};

template <class T, T INIT>
struct OverWrite {
    T operator()(const T& x, const T& y) const { return y == INIT ? x : y; }
};

template <class T, T INIT>
using RangeUpdateQuery = SegmentTree<T, OverWrite<T, INIT>, INIT>;

template <class T, T INIT>
using RangeAddQuery = SegmentTree<T, plus<T>, INIT>;
