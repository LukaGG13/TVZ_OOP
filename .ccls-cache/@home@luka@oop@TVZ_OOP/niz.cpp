#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Niz {
public:
    vector<T> v;
    Niz(vector<T> v) {
        this-> v = v;
    }
    bool manje_od(const Niz& niz){
        auto minIt = min(v.begin(), v.end()); 
        auto maxIt = max(niz.v.begin(), niz.v.end()); 
        if(v[min] >= niz.v[max]) return false;
        return true;
    }
};

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {11, 0, 13};

    Niz<int> p1(v1);
    Niz<int> p2(v2);

    return 0;
}
