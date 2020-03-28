---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: data_structure/segtree3.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segtree3.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:27:33+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>
using namespace std;
const int INF = 1<<30;

#include<functional>
// http://codeforces.com/contest/833/problem/B
template<class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    OP op;
    int n;
    vector<T> data, pool;
    // 適切に改造すると，可換でなくてももうちょっとできる...    
    SegmentTree(int n_) {
        n = 1; while(n < n_) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
    }
    SegmentTree(const vector<T> &vec) {
        n = 1; while(n < vec.size()) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
        rep(i, vec.size()) data[n + i - 1] = vec[i];
        for(int i = n - 2; i >= 0; i--) {
            data[i] = op.query(data[left_child(i)], data[right_child(i)]);
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
        if(out_of_range(a, b, l, r)) return;
        if(within_range(a, b, l, r)) {            
            pool[i] = op.update(pool[i], v);
            data[i] = op.update(data[i], v); 
            return;
        }
        // 遅延伝搬させる
        int m = (l + r) / 2;
        // ためていたものを流す
        update(l, m, left_child(i), l, m, pool[i]);
        update(m, r, right_child(i), m, r, pool[i]);
        pool[i] = op.update_unit(); // 流したのでクリア
        // 新しい値を流す
        update(a, b, left_child(i), l, m, v);
        update(a, b, right_child(i), m, r, v);        
        data[i] = op.query(data[left_child(i)], data[right_child(i)]);
    }
    // index(a) の値を求める, 今node[i], 
    T query(int a, int b, int i, int l, int r) {        
        if(out_of_range(a, b, l, r) or (int)data.size() <= i) return op.query_unit();
        if(within_range(a, b, l, r)) return data[i];
        int m = (l + r) / 2;
        T vl = query(a, b, left_child(i), l, m);
        T vr = query(a, b, right_child(i), m, r);        
        return op.update(op.query(vl, vr), pool[i]);
    }
    bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    int left_child(int i) { return i * 2 + 1; }
    int right_child(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }
};

struct RMQOnSum {
    using T = int;
    T update(const T &a, const T &b) { return a + b; }
    T query(const T &a, const T &b)  { return max(a, b); }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit()  { return 0; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/segtree3.hpp"

#include <vector>
#include <cassert>
using namespace std;
const int INF = 1<<30;

#include<functional>
// http://codeforces.com/contest/833/problem/B
template<class OP>
class SegmentTree {
  public:
    using T = typename OP::T;
    OP op;
    int n;
    vector<T> data, pool;
    // 適切に改造すると，可換でなくてももうちょっとできる...    
    SegmentTree(int n_) {
        n = 1; while(n < n_) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
    }
    SegmentTree(const vector<T> &vec) {
        n = 1; while(n < vec.size()) n *= 2;
        data.resize(2 * n - 1, op.update_unit());
        pool.resize(2 * n - 1, op.query_unit());
        rep(i, vec.size()) data[n + i - 1] = vec[i];
        for(int i = n - 2; i >= 0; i--) {
            data[i] = op.query(data[left_child(i)], data[right_child(i)]);
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
        if(out_of_range(a, b, l, r)) return;
        if(within_range(a, b, l, r)) {            
            pool[i] = op.update(pool[i], v);
            data[i] = op.update(data[i], v); 
            return;
        }
        // 遅延伝搬させる
        int m = (l + r) / 2;
        // ためていたものを流す
        update(l, m, left_child(i), l, m, pool[i]);
        update(m, r, right_child(i), m, r, pool[i]);
        pool[i] = op.update_unit(); // 流したのでクリア
        // 新しい値を流す
        update(a, b, left_child(i), l, m, v);
        update(a, b, right_child(i), m, r, v);        
        data[i] = op.query(data[left_child(i)], data[right_child(i)]);
    }
    // index(a) の値を求める, 今node[i], 
    T query(int a, int b, int i, int l, int r) {        
        if(out_of_range(a, b, l, r) or (int)data.size() <= i) return op.query_unit();
        if(within_range(a, b, l, r)) return data[i];
        int m = (l + r) / 2;
        T vl = query(a, b, left_child(i), l, m);
        T vr = query(a, b, right_child(i), m, r);        
        return op.update(op.query(vl, vr), pool[i]);
    }
    bool out_of_range(int a, int b, int l, int r) { return r <= a or b <= l; }
    bool within_range(int a, int b, int l, int r) { return a <= l and r <= b; }
    int left_child(int i) { return i * 2 + 1; }
    int right_child(int i) { return i * 2 + 2; }
    int parent(int i) { return (i - 1) / 2; }
};

struct RMQOnSum {
    using T = int;
    T update(const T &a, const T &b) { return a + b; }
    T query(const T &a, const T &b)  { return max(a, b); }
    static constexpr T update_unit() { return 0; }
    static constexpr T query_unit()  { return 0; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

