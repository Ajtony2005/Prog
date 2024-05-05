#include <iostream>
#include <vector>
#include "kartya.hpp"
#include "jatekos.hpp"
#include "vilag.hpp"
using namespace std;


class Jatekos;
class Vilag;


int main()
{

    Vilag v;
    v.random_oszt();
    v.report();
    v.a_random_lep();
    cout << endl;
    v.report();
    v.a_random_lep();
    cout << endl;
    v.report();
    return 0;
}
