#ifndef VILAG_HPP_INCLUDED
#define VILAG_HPP_INCLUDED

#include "jatekos.hpp"
#include "kartya.hpp"

class Jatekos;
class Kartya;

class Vilag {
    Jatekos * jatekos_a, *jatekos_b;
public:
    Vilag();
    void random_oszt();
    void report();
    void a_random_lep();
    void kijatszik(Jatekos * ki, Kartya * mit);
};





#endif // VILAG_HPP_INCLUDED
