#include <iostream>
using namespace std;

class PremaliBroj {
    public:
    string poruka() const {
        return "preamli broj";
    }
};

class PrevelikBroj {
    public:
    string poruka() const {
        return "preveliki broj";
    }
};

void test(int n){
    cout << "pocetja test\n";

    if (n >= 2) {
        cout << "pocetak primjera\n";
        throw(PrevelikBroj());
    }

    return;
}

int main() {
    try {
        test(2);
        cout << "nastavak try-bloka...\n";
    } catch (const PrevelikBroj& e) {
        cout << e.poruka() << endl;
    } catch (const PremaliBroj& e) {
        cout << e.poruka() << endl;
    } catch (...) {
        cout << "... neka druga greska!";
    }

    cout << "nastavak main funkcije\n";
}