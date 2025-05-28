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
    bool manje_od(const Niz& niz) const {
        auto minIt = min_element(niz.v.begin(), niz.v.end()); 
        auto maxIt = max_element(v.begin(), v.end()); 
        //cout << "Max: " << *maxIt << " Min: " << *minIt << endl; 
        return *minIt > *maxIt;
    }
};

template <class T>
class Niz2 : public Niz<T> {
public:
    Niz2(vector<T> v) : Niz<T>(v) {}
    bool operator < (const Niz2& niz) const {
        return manje_od(niz);
    }
};

template <typename T>
bool operator< (const Niz<T>& niz1, const Niz<T>& niz2) {
    return niz1.manje_od(niz2);
}

template <typename T>
bool operator>= (const Niz<T>& niz1, const Niz<T>& niz2) {
    return !(niz1 < niz2);
}

int main() {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {11, 66, 13};

    Niz<int> p1(v1);
    Niz<int> p2(v2);

    cout << (p1 < p2) << endl;
    cout << (p2 >= p2) << endl;
    cout << (p2 >= p1) << endl;
    cout << (p1 >= p2) << endl;
    return 0;
}
