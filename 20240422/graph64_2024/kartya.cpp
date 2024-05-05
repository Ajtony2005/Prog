#include <iostream>
#include <vector>
#include "jatekos.hpp"
using namespace std;

class Jatekos;

Kartya::Kartya(int p, int m) : koltseg_penz(p), koltseg_mana(m){}
UtoKartya::UtoKartya(int p, int m, int utes) : Kartya(p,m), utesero(utes){}
Ogre::Ogre() : UtoKartya(20,0,12) {}
Ijasz::Ijasz() : Kartya(7,1) {}
Cigany::Cigany() : Kartya(5, 3) {}


     void UtoKartya::kijatszik(Jatekos * kire, Jatekos * ki) {
        kire->serul(utesero);
    }



    string Ogre::nev() {
        return "Ogre";
    }
     string Ijasz::nev() {
        return "Ijasz";
    }
     void Ijasz::kijatszik(Jatekos * kire, Jatekos * ki) {
        if (ki->get_falmagassag() > kire->get_falmagassag()) {
            kire->torony_ut(5);
        } else {
            kire->serul(2);
        }
    }
    string Cigany::nev(){
        return "Cigany";
    }
     void Cigany::kijatszik(Jatekos * kire, Jatekos * ki) {
        kire->elvesz(2);

    }


