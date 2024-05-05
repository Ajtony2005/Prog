#include <iostream>
#include <vector>
#include "jatekos.hpp"
#include "kartya.hpp"
#include "vilag.hpp"

using namespace std;

class Jatekos;
class Kartya;


    Vilag::Vilag() {
        jatekos_a = new Jatekos(this);
        jatekos_b = new Jatekos(this);
    }
    void random_oszt();
    void Vilag::report() {
        cout << "A: " << endl;
        jatekos_a->status(cout);
        cout << "B: " << endl;
        jatekos_b->status(cout);
        cout << " ------ " << endl;
    }
    void Vilag::a_random_lep() {
        jatekos_a ->random_lep();
    }
    void Vilag::kijatszik(Jatekos * ki, Kartya * mit) {
        Jatekos * kire;
        if (ki == jatekos_a) {
            kire = jatekos_b;
            cout << "A kijatszik B-re " << mit->nev() << endl;
        } else {
            kire = jatekos_a;
            cout << "B kijatszik A-ra " << mit->nev() << endl;
        }

        mit->kijatszik(kire, ki);
    }


void Vilag::random_oszt() {
    for (Jatekos * ki : {jatekos_a, jatekos_b}) {
        for (int i=0;i<5;i++) {
            Kartya * uj;
            int melyik = rand() % 3; //hányféle fajta kártya van
            switch (melyik) {
                case 0 : uj = new Ogre; break;
                case 1 : uj = new Ijasz; break;  //figyelj, hogy mindig legyen break!
                case 2 : uj = new Cigany; break;
            }
            ki->kap(uj);
        }
    }
}

