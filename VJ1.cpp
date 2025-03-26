#include <iostream>
#include <vector>
using namespace std;

class Pedalina {
public:
    string boja;
    int kapacitet;
};

class Lokacija {
public:
    string ime, prezime;
    double x, y;
    vector<Pedalina> predmeti;
};


int main2() {
    int n;
    cout << "Unesite broj lokacija (N):";
    cin >> n;
    vector<Lokacija> lokacije(n);
    Pedalina pedalina;
    for (int i = 0; i < n; i++){
        cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju:" << endl;
        cin >> lokacije[i].ime >> lokacije[i].prezime >> lokacije[i].x >> lokacije[i].y;
    }

    int m;
    cout << " Unesite broj pedalina (M): ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Unesite redni broj lokacije kojoj pripada " << i + 1 << ". pedalina: ";
        int lokacija;
        cin >> lokacija;
        lokacija--;
        cout << "Unesite boju i kapacitet pedaline:" << endl;
        cin >> pedalina.boja >> pedalina.kapacitet;
        lokacije[lokacija].predmeti.push_back(pedalina);
    }

    cout << "Ispis lokacija i pedalina:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << lokacije[i].x << " " << lokacije[i].y << " " << lokacije[i].ime << " " << lokacije[i].prezime << " ";
        cout << "- pedaline: ";
        for (int j = 0; j < lokacije[i].predmeti.size(); j++) {
            cout << lokacije[i].predmeti[j].boja << " (" << lokacije[i].predmeti[j].kapacitet << ") ";
        }
        cout << endl;
    }

    return 0;
}
