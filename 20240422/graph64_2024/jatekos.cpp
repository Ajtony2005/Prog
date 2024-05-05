#include <iostream>
#include <vector>
#include "vilag.hpp"

using namespace std;


Jatekos::Jatekos(Vilag *v) : vilag(v),
        falmagassag(kezdeti_falmagassag),
        toronymagassag(kezdeti_toronymagassag),
        mana(kezdeti_mana),
        penz(kezdeti_penz){}

    void Jatekos::serul(int utes) {
        falmagassag -= utes;
        if (falmagassag<0) {
            toronymagassag += falmagassag;
            falmagassag = 0;
        }
    }
    void Jatekos::torony_ut(int utes) {
        toronymagassag -= utes;
    }
    void Jatekos::elvesz(int leepules) {
        falmagassag -= leepules;
    }
    bool Jatekos::vesztett() {
        return toronymagassag <= 0;
    }
    void Jatekos::kap(Kartya *k) {
        kartyak.push_back(k);
    }
    void Jatekos::status(ostream &out) {
        out <<"torony: " << toronymagassag << " fal: " << falmagassag << " penz:" << penz << " mana:" << mana << endl;
        for (Kartya * k : kartyak ) {
            out << k->nev() << " ";
        }
        out << endl;
    }
    int Jatekos::get_falmagassag() {return falmagassag;}






void Jatekos::random_lep() {
    Kartya * k = kartyak.at(0); //TODO: random kellene legyen, el kellene tunnie a kijatszott lapnak
    vilag->kijatszik(this, k);
}
