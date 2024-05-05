#ifndef KARTYA_HPP_INCLUDED
#define KARTYA_HPP_INCLUDED

#include "jatekos.hpp"

using namespace std;

class Jatekos;

class Kartya {
    int koltseg_penz, koltseg_mana;
public:
    Kartya(int p, int m);
    virtual string nev()=0;
    virtual void kijatszik(Jatekos * kire, Jatekos * ki) =0;
    virtual ~Kartya() {}
};

class UtoKartya : public Kartya {
    int utesero;
public:
    UtoKartya(int p, int m, int utes);
    virtual void kijatszik(Jatekos * kire, Jatekos * ki);
};

class Ogre : public UtoKartya {
public:
    Ogre();
    virtual string nev();
};

class Ijasz : public Kartya {
public:
    Ijasz();
    virtual string nev();
    virtual void kijatszik(Jatekos * kire, Jatekos * ki);
};

class Cigany : public Kartya {
public:
    Cigany();
    virtual string nev();
    virtual void kijatszik(Jatekos * kire, Jatekos * ki);

};


#endif // KARTYA_HPP_INCLUDED
