// #include "bits/stdc++.h"
// using namespace std;
#pragma once

// vector
template<class T> istream& operator >> (istream &is , vector<T> &v) { for(T &a : v) is >> a; return is; }
template<class T> ostream& operator << (ostream &os , const vector<T> &v) { for(const T &t : v) os << "\t" << t; return os << endl; }
// pair
template<class T, class U> istream& operator >> (istream &is , const pair<T, U> &v) { return is >> v.first >> v.second; }
template<class T, class U> ostream& operator << (ostream &os , const pair<T, U> &v) { return os << "(" << v.first << ", " << v.second << ")"; }
// map
template<class T, class U> ostream& operator << (ostream &os , const map<T, U> &v) { for(const auto &t : v) os << "\t" << t; return os << endl; }
// set
template<class T> ostream& operator << (ostream &os , const set<T> &v) { for(const auto &t : v) os << "\t" << t; return os << endl; }
