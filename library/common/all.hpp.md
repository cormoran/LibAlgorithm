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


# :warning: common/all.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#9efab2399c7c560b34de477b9aa0a465">common</a>
* <a href="{{ site.github.repository_url }}/blob/master/common/all.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#define all(x) x.begin(),x.end()

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "common/all.hpp"
#define all(x) x.begin(),x.end()

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

