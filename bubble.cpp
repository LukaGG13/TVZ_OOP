#include <iostream>
#include <cmath>
using namespace std;

class Bubble {
    public:
    string boja;
    double r;
    Bubble(string boja, double r) {
        this->boja = boja;
        this->r = r;
    }

    Bubble operator+(const Bubble& b){
        string boja = this->r > b.r ? this->boja : b.boja;
        double v = (4.0/3.0) *  pow (this->r, 3) * 3.14 + (4.0/3.0) *  pow (b.r, 3) * 3.14;
        double r = pow(v / (4.0 / 3.0) / 3.14, 1.0 / 3.0);
        return Bubble(boja, r);
    }

    Bubble operator-(const Bubble& b){
        double v = (4.0/3.0) *  pow (this->r, 3) * 3.14 - (4.0/3.0) *  pow (b.r, 3) * 3.14;
        double r = pow(v / (4.0 / 3.0) / 3.14, 1.0 / 3.0);
        return Bubble(this->boja, r);
    }

    bool operator==(const Bubble& b){
        if(this->boja == b.boja && abs(this->r - b.r) <= 0.0001)
            return true;
        return false;
    }
};

ostream& operator<<(ostream &out, const Bubble& b) {
    out.precision(4);
    return out << b.boja << ": " << b.r << '\n';
}

int main() {
    Bubble a("blue", 10.4);
    Bubble b("red", 7.2);
    Bubble c("green", 18.8);

    Bubble x = a + b; //nastat će novi bubble obujma 6275.27
    cout << x; //blue: 11.44
    Bubble y = x + c;
    cout << y; //green: 20.12

    Bubble z = y - x;
    cout << z; //green: 18.8

    if(z == c)
    cout << "OK" << endl; //OK
    return 0;
}