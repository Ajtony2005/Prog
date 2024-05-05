#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include <iostream>
#include <string>
#include "os.hpp"
#include <vector>

using namespace std;

class gomb: public os{
    string leszoveg, felszoveg;
    bool megnyomva;
public:
    gomb(window* a, int x_kor, int y_kor, int meretx, int merety, string leszoveg, string felszoveg, bool megnyomva);
    void rajzol();
    void fogantyu(genv::event ev);
    void mentes();

};


#endif // GOMB_HPP_INCLUDED
