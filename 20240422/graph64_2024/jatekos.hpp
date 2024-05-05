#ifndef JATEKOS_HPP_INCLUDED
#define JATEKOS_HPP_INCLUDED

#include <iostream>
#include <vector>
#include "vilag.hpp"
#include "kartya.hpp"

const int kezdeti_toronymagassag = 20;
const int kezdeti_falmagassag = 10;
const int kezdeti_penz = 30;
const int kezdeti_mana = 30;


class Vilag;
class Kartya;
using namespace std;

class Jatekos {
    Vilag * vilag;
    int falmagassag, toronymagassag, mana, penz;
    vector<Kartya *> kartyak;
public:
    Jatekos(Vilag *v);
    void random_lep();
    void serul(int utes);
    void torony_ut(int utes);
    bool vesztett();
    void kap(Kartya *k);
    void status(ostream &out);
    int get_falmagassag();
    void elvesz(int elvesz);
};


#endif // JATEKOS_HPP_INCLUDED
