#include <iostream>
#include <vector>
#include <algorithm>
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

    void ispisSvihStanova(){
        for(const auto &stan : v){
            cout << stan.vlasnik << " " << stan.brojSoba << " " << stan.velicina;
            cout << '\n';
        }
    }

    Stan nadjiStan1(string vlasnik){
        const auto it = find_if(v.begin(), v.end(), [vlasnik](const Stan &s){
            return s.vlasnik == vlasnik;
        });
        return *it;
    }
    Stan* nadjiStan2(string vlasnik){
        const auto it = find_if(v.begin(), v.end(), [vlasnik](const Stan &s){
            return s.vlasnik == vlasnik;
        });
        return &(*it);
    }
    Stan& nadjiStan3(string vlasnik) {
        const auto it = find_if(v.begin(), v.end(), [vlasnik](const Stan &s){
            return s.vlasnik == vlasnik;
        });
        return *it;
    }
};

int main(){
    Stan s;
    s.velicina = 2;
    s.brojSoba = 69;
    s.vlasnik = "Coldplay";
    Zgrada z;
    z.dodajStan1(s);
    z.dodajStan2(s);
    z.dodajStan3(&s);
// Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? Zašto se ispisuje više puta destruktor nego konstruktor?
    z.ispisSvihStanova();

    Stan s2;
    s2.velicina = 2;
    s2.brojSoba = 69;
    s2.vlasnik = "Artick Monkeys";
    z.dodajStan1(s2);

    s2 = z.nadjiStan1("Artick Monkeys");
    s2.vlasnik = "alex turner";
    cout << s2.vlasnik << " " << s2.brojSoba << " " << s2.velicina << '\n';

    Stan *s3;

    Stan temp;
    temp.velicina = 2;
    temp.brojSoba = 69;
    temp.vlasnik = "Radio Head";
    z.dodajStan1(temp);


    s3 = z.nadjiStan2("Radio Head");
    s3->vlasnik = "thome york";
    cout << (*s3).vlasnik << " " << (*s3).brojSoba << " " << (*s3).velicina << '\n';

    Stan s4;
    s4 = z.nadjiStan3("Coldplay");
    s4 .vlasnik = "chris martin";
    cout << s4.vlasnik << " " << s4.brojSoba << " " << s4.velicina << '\n';

    z.ispisSvihStanova();

    return 0;
}