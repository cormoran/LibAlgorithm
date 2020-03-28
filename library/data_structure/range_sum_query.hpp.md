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


# :warning: data_structure/range_sum_query.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/range_sum_query.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:27:33+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int INF = 1<<30;

using Index = int;
template<typename Data>
class SegmentTree{
  public:
    int size;
    vector<Data> data;
    SegmentTree(int n){
        size = n;
        while(n < size) n *= 2;
        data.resize( 2 * n - 1, 0);
    }
    // Array[i] += val
    void add(Index i, Data val){
        i += size - 1;
        while(i){ // 木を登っていく
            data[i] += val;
            i = (i - 1) / 2;
        }
    }
    // sum of [a, b)
    Data sum(int a, int b){
        return sum(a, b, 0, 0, size);
    }
  private:
    //[a,b)のsum, iは今の場所, [l,r)はiの守備範囲
    Data sum(Index a, Index b, Index i, Index l, Index r){
        if( r <= a or b <= l ) return 0; // out range
        else if( a <= l and r <= b ) return data[i]; // in range
        else { // intersect
            Index lc = i * 2 + 1;
            Index rc = i * 2 + 2;
            Index m = (l + r) / 2;
            return sum(a, b, lc, l, m) + sum(a, b, rc, m, r);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/range_sum_query.hpp"
const int INF = 1<<30;

using Index = int;
template<typename Data>
class SegmentTree{
  public:
    int size;
    vector<Data> data;
    SegmentTree(int n){
        size = n;
        while(n < size) n *= 2;
        data.resize( 2 * n - 1, 0);
    }
    // Array[i] += val
    void add(Index i, Data val){
        i += size - 1;
        while(i){ // 木を登っていく
            data[i] += val;
            i = (i - 1) / 2;
        }
    }
    // sum of [a, b)
    Data sum(int a, int b){
        return sum(a, b, 0, 0, size);
    }
  private:
    //[a,b)のsum, iは今の場所, [l,r)はiの守備範囲
    Data sum(Index a, Index b, Index i, Index l, Index r){
        if( r <= a or b <= l ) return 0; // out range
        else if( a <= l and r <= b ) return data[i]; // in range
        else { // intersect
            Index lc = i * 2 + 1;
            Index rc = i * 2 + 2;
            Index m = (l + r) / 2;
            return sum(a, b, lc, l, m) + sum(a, b, rc, m, r);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

