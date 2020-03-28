#pragma once

#include <vector>
#include <cassert>
using namespace std;
const int INF = 1<<30;

#include<functional>
/*^ingore^*/

// T           : データ型
// UpdateFunc  : (以前の値, 適用する値) => 新しい値 結合性必要
// update_unit : UpdateFuncの単位元 (= 配列の初期値)
template<class T, class UpdateFunc, T update_unit>
class SegmentTree {
  public:
    int n; 
    vector<T> data;
    UpdateFunc uf;
    SegmentTree(int nn) : n(1) {
        while(n < nn) n *= 2;
        data.resize( 2 * n - 1, update_unit);
    }
    SegmentTree(vector<T> init) : n(1) {
        int nn= init.size();
        while(n < nn) n *= 2;
        data.resize( 2 * n - 1, update_unit);
        copy(begin(init), end(init), begin(data) + n - 1);
    }
    // get value of index(i)
    T query(int i) {
        assert(0 <= i and i < n);
        return query(i, 0, 0, n);
    }
    // apply f(_, v) to [a, b)
    void update(int a, int b, T v) {
        assert(0 <= a and a < b and b <= n);
        update(a, b, 0, 0, n, v);
    }
  private:
    // [a, b) 更新区間, i 今いるNode, [l, r) はNode[i]の担当区間
    void update(int a, int b, int i, int l, int r, T v) {
        if(out_of_range(a, b, l, r)) return;
        if(within_range(a, b, l, r)) data[i] = uf(data[i], v);
        else {
            // 遅延伝搬させる
            int m = (l + r) / 2;
            // 関係ない範囲は今までの値を流す
            if(l < a) { // l .. a .(r). b ..(r)
                update(l, a, left_child(i), l, m, data[i]);
                update(l, a, right_child(i), m, r, data[i]);
            }
            if(b < r) { // (l).. a .(l). b .. r
                update(b, r, left_child(i), l, m, data[i]);
                update(b, r, right_child(i), m, r, data[i]);
            }
            // 関係する範囲は今の値を合わせて流す
            update(a, b, left_child(i), l, m, f(data[i], v));
            update(a, b, right_child(i), m, r, f(data[i], v)); 
            data[i] = update_unit; // 子に全て流したから
        }
    }
    // index(a) の値を求める, 今node[i], 
    T query(int a, int i, int l, int r) {
        if(data.size() <= i) return update_unit;
        assert(l <= a and a < r);
        int m = (l + r) / 2;
        T v = a < m ? query(a, left_child(i), l, m) : query(a, right_child(i), m, r);
        return uf(v, data[i]); // 先に流しているのでvの方が古い値
    }
    static bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    static bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    static int left_child(int i) { return i * 2 + 1; }
    static int right_child(int i) { return i * 2 + 2; }
    static int parent(int i) { return (i - 1) / 2; }
};

template <class T> struct OverWrite {
    T operator() (const T& x, const T& y) const { return y; }
};

template<class T, T INIT>
using RangeUpdateQuery = SegmentTree<T, OverWrite<T>, INIT>;

template<class T, T INIT>
using RangeAddQuery = SegmentTree<T, plus<T>, INIT>;

