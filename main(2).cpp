#include <iostream>
#include <string>
using namespace std;

class Ucionica {
public:
    int brRacunala;
    string nazivProizvodjaca;
    string procesor;
    string ram;

    Ucionica(int brRacunala, string nazivProizvodjaca, string procesor, string ram)
            : brRacunala(brRacunala), nazivProizvodjaca(nazivProizvodjaca), procesor(procesor), ram(ram) {}

    Ucionica(const Ucionica& other)
            : brRacunala(other.brRacunala), nazivProizvodjaca(other.nazivProizvodjaca),
              procesor(other.procesor), ram(other.ram) {}

    Ucionica(Ucionica&& other)
            : brRacunala(other.brRacunala), nazivProizvodjaca(move(other.nazivProizvodjaca)),
              procesor(move(other.procesor)), ram(move(other.ram)) {
        other.brRacunala = 0; // Nakon premještanja, drugi objekt je "prazan"
    }

    Ucionica& operator=(const Ucionica& other) {
        if (this != &other) {
            brRacunala = other.brRacunala;
            nazivProizvodjaca = other.nazivProizvodjaca;
            procesor = other.procesor;
            ram = other.ram;
        }
        return *this;
    }
};

int main() {
    // Učionica 'A' s 15 računala istih specifikacija
    Ucionica A(15, "Koncar", "Intel I5", "4 GB");

    // Učionica B ima također 15 računala istih specifikacija kao i učionica 'A'
    Ucionica B = A;
    cout << B.brRacunala << endl; // 15

    // Računala iz učionice 'B' se prenose u  učionicu 'C'
    Ucionica C = move(B);
    cout << B.brRacunala << endl; // 0

    // Privremena učionica se zatvara i njena računala se prenose u učionicu 'B'
    B = Ucionica(15, "Dell", "Intel I7", "8 GB");

    return 0;
}
