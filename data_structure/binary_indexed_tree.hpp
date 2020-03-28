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
