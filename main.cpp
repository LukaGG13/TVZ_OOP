#include <iostream>
#include <vector>
using namespace std;

class Stan{
public:
    string vlasnik;
    int velicina;
    int brojSoba;
    Stan(){
        cout << "stan constructor called\n";
    }
    ~Stan(){
        cout << "stan destructor called\n";
    }
//    Stan(const Stan&) = default;
//    Stan(Stan&&) = default;
};

class Zgrada {
private:
    string firma = "";
    int n;
    int adr;
    vector<Stan> v;
public:
    void setFirma(string firma){
        if (firma.length() < 5){
            cout << "ime firme mora biti barem 5 znakova\n";
            return;
        }
        this->firma = firma;
    }

    void setBrojKatova(int n){
        if (n <= 0){
            cout << "broj katova mora biti veci od 0\n";
            return;
        }
        this->n = n;
    }

    void setAdresa(int adr){
        this->adr = adr;
    }

    void dodajStan1(Stan z){
        v.push_back(z);
    }

    void dodajStan2(Stan &z){
        v.push_back(z);
    }

    void dodajStan3(Stan *z){
        v.push_back(*z);
    }
};

int main(){
    Stan s;
    Zgrada z;
    z.dodajStan1(s);
    z.dodajStan2(s);
    z.dodajStan3(&s);
// Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?
    cout << "Hello World!!!";

    return 0;
}