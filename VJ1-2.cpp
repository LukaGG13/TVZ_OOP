#include <iostream>
#include <vector>
#include <memory>

using namespace std;

/*
class Artikl{
public:
    string ime;
    int kolicina;
    double cijena;

    Artikl(string ime, int kolicina, double cijena){
        this->ime = ime;
        this->kolicina = kolicina;
        this->cijena = cijena;
    }
};


class Racun {
public:
    int broj;
    double ukupnaCijena;
    vector<Artikl> v;

    Racun(){
        broj = -1;
    }

    Racun(int broj) {
        this->broj = broj;
        ukupnaCijena = 0;
    }

    void dodaj(Artikl a){
        v.push_back(a);
        ukupnaCijena += a.cijena * a.kolicina;
    }

};

class Kupac {
public:
    Racun racun;
    Kupac(Racun racun){
        this->racun = racun;
    }
};


int main(){

    Kupac Ante(Racun(1)); // Ante ima račun broj 1

    Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg

    Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg

    Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca

    cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn



    /* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio

       (naziv i ukupna cijena). Npr.



       Najskuplje placeni artikl je Coca cola 2l (20kn)

    */
/*

    Artikl najSkuplji = Ante.racun.v[0];
    for (int i = 1; i < Ante.racun.v.size(); i++) {
        if (Ante.racun.v[i].cijena * Ante.racun.v[i].kolicina > najSkuplji.cijena * najSkuplji.kolicina)
            najSkuplji = Ante.racun.v[i];
    }

    cout << "Najskuplje placeni artikl "<< najSkuplji.ime << "(" << najSkuplji.cijena * najSkuplji.kolicina << "kn)";

    return 0;

}

*/


int main(){
    unique_ptr<int> p(new int );

}