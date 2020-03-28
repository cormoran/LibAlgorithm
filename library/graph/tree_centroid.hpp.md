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


# :warning: graph/tree_centroid.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/tree_centroid.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 02:07:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
const int INF=1<<30;
typedef vector<vector<int>> EdgeList;
//
// 重心で木を分割することを繰り返す 分割統治
//
EdgeList E;
vector<int> subtree_size;
vector<bool> used;

int calc_subtree_size(int now,int pre){
  int sum=1;
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;  //used[nxt] : 親の木に入らないように
    sum+=calc_subtree_size(nxt, now);
  }
  return subtree_size[now]=sum;
}

pii search_centroid(int now,int pre,int total){ //total : 部分木のノード数
  pii ret = {INF,-1};
  int max_sub=total-subtree_size[now];
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;  //used
    ret = min(ret,search_centroid(nxt, now,total));
    max_sub=max(max_sub,subtree_size[nxt]);
  }
  return min(ret,make_pair(max_sub, now));
}

//rootを含む部分木の重心を見つけてそこで木を分割するdfs
bool dfs(int root,char c,vector<char> &ans){
  if(c>'Z')return false;
  bool ret = true;
  int total = calc_subtree_size(root, -1);
  int centroid = search_centroid(root, -1,total).second;
  ans[centroid]=c;
  used[centroid]=true;
  for(int nxt : E[centroid]){
    if(used[nxt])continue;
    ret&=dfs(nxt, c+1, ans);
  }
  return ret;
}
//************************************************//
//* codeforces #190 div1 C                       *//
//************************************************//
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/tree_centroid.hpp"
const int INF=1<<30;
typedef vector<vector<int>> EdgeList;
//
// 重心で木を分割することを繰り返す 分割統治
//
EdgeList E;
vector<int> subtree_size;
vector<bool> used;

int calc_subtree_size(int now,int pre){
  int sum=1;
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;  //used[nxt] : 親の木に入らないように
    sum+=calc_subtree_size(nxt, now);
  }
  return subtree_size[now]=sum;
}

pii search_centroid(int now,int pre,int total){ //total : 部分木のノード数
  pii ret = {INF,-1};
  int max_sub=total-subtree_size[now];
  for(int nxt : E[now]){
    if(nxt==pre || used[nxt])continue;  //used
    ret = min(ret,search_centroid(nxt, now,total));
    max_sub=max(max_sub,subtree_size[nxt]);
  }
  return min(ret,make_pair(max_sub, now));
}

//rootを含む部分木の重心を見つけてそこで木を分割するdfs
bool dfs(int root,char c,vector<char> &ans){
  if(c>'Z')return false;
  bool ret = true;
  int total = calc_subtree_size(root, -1);
  int centroid = search_centroid(root, -1,total).second;
  ans[centroid]=c;
  used[centroid]=true;
  for(int nxt : E[centroid]){
    if(used[nxt])continue;
    ret&=dfs(nxt, c+1, ans);
  }
  return ret;
}
//************************************************//
//* codeforces #190 div1 C                       *//
//************************************************//

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

