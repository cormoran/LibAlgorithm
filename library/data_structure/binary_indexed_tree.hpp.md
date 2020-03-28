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


# :warning: data_structure/binary_indexed_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/binary_indexed_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:27:33+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
// verified!

// 1-based index!
template<typename T>
struct BIT {
    vector<T> data;
    BIT(size_t n) {
        data.resize(n + 1, 0);
    }
    //sum of [1, i]
    T sum(int i){
        assert(0 <= i);
        T s = 0;
        for(; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    // sum of [i, j]
    T sum(int i,int j){
        assert(0 < i and i <= j);
        return sum(j) - sum(i - 1);
    }
    //add x to index i
    void add(int i, T x){
        assert(0 < i);
        for(; i < data.size(); i += i & -i) data[i] += x;
    }
    // seach min i such that sum(i) >= x
    int lower_bound(T x){
        int r = data.size() - 1, l = 0; // (l, r]
        while(r - l > 1){
            int m = (r + l) / 2;
            (sum(m) >= x ? r : l) = m;
        }
        return r;
    }
};
template<class T> using BinaryIndexedTree = BIT<T>;
template<class T> using FenwickTree = BIT<T>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data_structure/binary_indexed_tree.hpp"
// verified!

// 1-based index!
template<typename T>
struct BIT {
    vector<T> data;
    BIT(size_t n) {
        data.resize(n + 1, 0);
    }
    //sum of [1, i]
    T sum(int i){
        assert(0 <= i);
        T s = 0;
        for(; i > 0; i -= i & -i) s += data[i];
        return s;
    }
    // sum of [i, j]
    T sum(int i,int j){
        assert(0 < i and i <= j);
        return sum(j) - sum(i - 1);
    }
    //add x to index i
    void add(int i, T x){
        assert(0 < i);
        for(; i < data.size(); i += i & -i) data[i] += x;
    }
    // seach min i such that sum(i) >= x
    int lower_bound(T x){
        int r = data.size() - 1, l = 0; // (l, r]
        while(r - l > 1){
            int m = (r + l) / 2;
            (sum(m) >= x ? r : l) = m;
        }
        return r;
    }
};
template<class T> using BinaryIndexedTree = BIT<T>;
template<class T> using FenwickTree = BIT<T>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

