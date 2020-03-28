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
