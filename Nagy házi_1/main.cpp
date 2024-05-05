#include "graphics.hpp"
#include <vector>
#include <cmath>
#include <cstdlib>
#include "os.hpp"
#include "szamolos.hpp"
#include "kivalaszto.hpp"
#include <fstream>
#include "Application.hpp"
#include "gomb.hpp"


const int XX = 800;
const int YY = 800;


using namespace std;
using namespace genv;


int main(){
    window* b= new window(XX, YY);
    vector<string> gyumolcsok = {"alma", "körte", "banán", "szőlő", "narancs"};
    vector<string> autok = {"Audi", "BMW", "Kia", "Porsche", "Lexus", "Toyota"};
    new szamolos(b, 50, 50, 150, 50, 0, 0, 100);
    new szamolos(b, 300, 100, 150, 50, 0, 0, 670);
    new kivalaszto(b, 400, 400, 210, 50, gyumolcsok, 0);
    new kivalaszto(b, 100, 400, 210, 50, autok, 0);
    new gomb(b, 600, 100, 100, 100, "Igen", "Nem", 1);
    b->event_loop();
    return 0;
}
