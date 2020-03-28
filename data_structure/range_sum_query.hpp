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
