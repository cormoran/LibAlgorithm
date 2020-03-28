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


# :warning: data_structure/segtree_debug.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/segtree_debug.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:27:33+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<iostream>
using namespace std;
/*^ingore^*/
template<class SegTree>
void debug_segment_tree(const SegTree &st, ostream &os = cerr) {
    os << "\033[33m";
    os << endl;
    int n = 1, m = 1;
    for(int i = 0; i < st.data.size(); i++) {
        os << st.data[i];
        if(i + 1 == m) {
            os << endl;
            n *= 2;
            m += n;            
        } else {
            os << " ";
        }
    }
    os << "\033[39m";
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/segtree_debug.hpp"
#include<iostream>
using namespace std;
/*^ingore^*/
template<class SegTree>
void debug_segment_tree(const SegTree &st, ostream &os = cerr) {
    os << "\033[33m";
    os << endl;
    int n = 1, m = 1;
    for(int i = 0; i < st.data.size(); i++) {
        os << st.data[i];
        if(i + 1 == m) {
            os << endl;
            n *= 2;
            m += n;            
        } else {
            os << " ";
        }
    }
    os << "\033[39m";
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

